#pragma once
#include "Adult.h"
#include "Child.h"
#include "PersonList.h"

namespace lab5
{
	class FamilyTools
	{
		public:
			static void CreateFamily(PersonList* list)
			{
				bool isAdult = false;
				bool isChild = false;
				cout << endl << "Введите индекс ВЗРОСЛОГО МУЖЧИНЫ, с которой начнём создание семьи: ";
				int index;
				//TODO: Тут и ниже можно без явного сравнения
				while (isAdult == false)
				{
					list->GetCorrectIndex(index);
					if (list->Find(index)->GetSex() == Male && list->Find(index)->GetAge() > 18)
					{
						isAdult = true;
					}
				}
				isAdult = false;
				Adult* temp = (Adult*)list->Find(index);
				while (isAdult == false)
				{
					system("cls");
					list->ShowList();
					cout << endl << "Введите индекс супруга: ";
					list->GetCorrectIndex(index);
					Adult* tempMarriedOn = (Adult*)list->Find(index);
					if (tempMarriedOn->GetSex() != temp->GetSex() && tempMarriedOn->GetAge()>18)
					{
						temp->SetMarriedOn(tempMarriedOn);
						tempMarriedOn->SetMarriedOn(temp);
						isAdult = true;
					}
				}
				while (isChild == false)
				{
					cout << endl << "Введите индекс ребёнка!";
					list->GetCorrectIndex(index);
					Child* tempChild = (Child*)list->Find(index);
					if (tempChild->GetAge() < 18)
					{
						tempChild->SetFather(temp);
						tempChild->SetMother(temp->GetMarriedOn());
						tempChild->SetSurname(temp->GetSurname());
						isChild = true;
					}
				}
			}
	};
}