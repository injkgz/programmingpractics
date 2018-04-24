#pragma once
#include "Adult.h"
#include "Child.h"
#include "TemplateList.h"

namespace lab5
{
	class FamilyTools
	{
		public:
			template <class Type>
			static void CreateFamily(TemplateList<Type>* list)
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

			static Adult* GetRandomAdult(Sex sex)
			{
				const char* MaleName[] =
				{
					"Vader", "Yoda", "Leya", "Aleksei",
					"Alexandr","Dmitrii", "Obi-Wan","Jin",
					"Enakin"
				};

				const char* MaleSurname[] =
				{
					"Dart", "Kenobi", "Jobs", "Gates",
					"Kim", "Pak", "Tsoy", "VanDam",
					"Skywalker", "Lol"
				};

				const char* FemaleName[] =
				{
					"Nia", "Katelyn", "Fedora",
					"Anna", "Mariya", "Arabella",
					"Leya", "Kaya", "Lilo"
				};

				const char* FemaleSurname[] =
				{
					"Myatejnikova","Stark","Goryshkina",
					"Hilkevich", "Frozen","Skoledario"
					"Watson", "Lannister", "Stern"
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
<<<<<<< HEAD
				//TODO: Неправильный ответ. Даю подсказку - везде nullptr, а тут NULL - почему?
				//так пойдёт?) исправил
				if (&sex != nullptr)
=======
				if (sex != NULL)
>>>>>>> parent of b41fdc8... TODO
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
							FemaleSurname[randChar]);
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

			static Child* GetRandomChild()
			{
				const char* MaleName[] =
				{
					"Vader", "Yoda", "Leya", "Aleksei",
					"Alexandr","Dmitrii", "Obi-Wan","Jin",
					"Enakin"
				};

				const char* MaleSurname[] =
				{
					"Dart", "Kenobi", "Jobs", "Gates",
					"Kim", "Pak", "Tsoy", "VanDam",
					"Skywalker"
				};

				const char* FemaleName[] =
				{
					"Nia", "Katelyn", "Fedora",
					"Anna", "Mariya", "Arabella",
					"Leya", "Kaya", "Lilo"
				};

				const char* FemaleSurname[] =
				{
					"Myatejnikova","Stark","Goryshkina",
					"Hilkevich", "Frozen","Skoledario"
					"Watson", "Lannister", "Stern"
				};

				const char* School[] =
				{
					"Школа-лицей #1", "Гимназия #2", "НИШ",
					"КТЛ", "Столичный лицей", "Школа #5",
					"Зерде", "Школа-лицей #60", "Гимназия #70"
				};
<<<<<<< HEAD
=======
				//TODO: Этот метод не должен тут находиться!
				//исправил
>>>>>>> parent of b41fdc8... TODO
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
							MaleSurname[randChar]);
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