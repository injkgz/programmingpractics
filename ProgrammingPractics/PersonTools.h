#pragma once
#include "CheckCin.h"

namespace lab5
{
	class PersonTools
	{
		public:
			static void GenerateRandomPerson(char tempName[Person::arraySize], char tempSurname[Person::arraySize],
				const char Name[10], const char Surname[10], int& tempAge)
			{
				strcpy_s(tempName, Person::arraySize, Name);
				strcpy_s(tempSurname, Person::arraySize, Surname);
				tempAge = rand() % 90;
			}
			static Person* MakeRandomPerson()
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

				char tempName[Person::arraySize];
				char tempSurname[Person::arraySize];
				int tempAge;
				Sex tempSex;
				int key = rand() % 1;

				switch (key)
				{
				case 0:
				{
					GenerateRandomPerson(tempName, tempSurname, FemaleName[rand() % 9],
						FemaleSurname[rand() % 9], tempAge);
					tempSex = Female;
					break;
				}
				case 1:
				{
					GenerateRandomPerson(tempName, tempSurname, MaleName[rand() % 9],
						MaleSurname[rand() % 9], tempAge);
					tempSex = Male;
					break;
				}
				default:
				{
					break;
				}
				}
				return new Person(tempName, tempSurname, tempAge, tempSex);
			}
	};
}