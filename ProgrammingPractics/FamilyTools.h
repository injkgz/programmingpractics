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
				//исправил
				while (!isAdult)
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

			Adult* GetRandom(Sex sex)
			{
				const char* MaleName[] =
				{
					"Вэйдер", "Йода", "Оби-Ван", "Молл",
					"Энакин", "Сидиус", "Рено", "Ктун",
					"Баланар", "Зевс"
				};

				const char* MaleSurname[] =
				{
					"Дарт", "Кеноби", "Скайуокер", "Джексон",
					"Божественный", "Блудрейнов", "Молненосный",
					"Исанов", "Джобс"
				};

				const char* FemaleName[] =
				{
					"Ниа", "Кейтлин", "Федора",
					"Анна", "Маша", "Арабелла",
					"Шадия", "Лея", "Кая", "Герда"
				};

				const char* FemaleSurname[] =
				{
					"Мятежникова", "Старк", "Горе",
					"Хилькевич", "Горышкина", "Лесная",
					"Принцесса", "Ледяная", "Сколедарио",
					"Ланнистер"
				};

				const char* WorkPlaces[] =
				{
					"Google", "Apple", "Yandex", "Tesla",
					"Mail.Ru", "Huawei", "Xiaomi", "HTC", "Microsoft"
				};

				char tempName[Person::ArraySize];
				char tempSurname[Person::ArraySize];
				char tempWorkPlace[Person::ArraySize];
				//TODO: Очень много магических цифр ниже, так и не исправили!
				//исправил
				int randAge = 18 + rand() % 90;
				int tempAge = randAge;
				int randSex = rand() % 2;
				int randChar = rand() % 9;
				Sex tempSex;
				//TODO: Почему NULL?
				//потому что не указатель?
				if (sex != NULL)
				{
					tempSex = Sex(randSex);
				}
				else
				{
					tempSex = Sex(!sex);
				}
				switch (tempSex)
				{
					case Female:
					{
						lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, FemaleName[randChar],
							FemaleSurname[randChar);
						break;
					}
					case Male:
					{
						lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, MaleName[randChar],
							MaleSurname[randChar]);
						break;
					}
					default:
					{
						break;
					}
				}
				strcpy_s(tempWorkPlace, Person::ArraySize, WorkPlaces[randChar]);
				return new Adult(tempName, tempSurname, tempAge, tempSex, tempWorkPlace);
			}

			Child* GetRandom()
			{
				const char* MaleName[] =
				{
					"Вэйдер", "Йода", "Оби-Ван", "Молл",
					"Энакин", "Сидиус", "Рено", "Ктун",
					"Баланар", "Зевс"
				};

				const char* MaleSurname[] =
				{
					"Дарт", "Кеноби", "Скайуокер", "Джексон",
					"Божественный", "Блудрейнов", "Молненосный",
					"Исанов", "Джобс"
				};

				const char* FemaleName[] =
				{
					"Ниа", "Кейтлин", "Федора",
					"Анна", "Маша", "Арабелла",
					"Шадия", "Лея", "Кая", "Герда"
				};

				const char* FemaleSurname[] =
				{
					"Мятежникова", "Старк", "Горе",
					"Хилькевич", "Горышкина", "Лесная",
					"Принцесса", "Ледяная", "Сколедарио",
					"Ланнистер"
				};

				const char* School[] =
				{
					"Школа-лицей #1", "Гимназия #2", "НИШ",
					"КТЛ", "Столичный лицей", "Школа #5",
					"Зерде", "Школа-лицей #60", "Гимназия #70"
				};
				//TODO: Этот метод не должен тут находиться!
				//исправил
				char tempName[Person::ArraySize];
				char tempSurname[Person::ArraySize];
				char tempSchool[Person::ArraySize];
				int randAge = rand()%17;
				int randSex = rand() % 2;
				int randChar = rand() % 9;
				int tempAge = randAge;
				Sex tempSex;
				tempSex = (Sex)randSex;
				Adult* tempMother = nullptr;
				Adult* tempFather = nullptr;
				switch (tempSex)
				{//TODO: Очень много магических цифр ниже, так и не исправили!
					//исправил
					case Female:
					{
						lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, FemaleName[randChar],
							FemaleSurname[randChar]);
						break;
					}
					case Male:
					{
						lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, MaleName[randChar],
							MaleSurname[randChar);
						break;
					}
					default:
					{
						break;
					}
				}

				strcpy_s(tempSchool, Person::ArraySize, School[randChar]);

				return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather, tempSchool);
			}
	};
}