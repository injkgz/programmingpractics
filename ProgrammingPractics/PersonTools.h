#pragma once
#include "CheckCin.h"

namespace lab5
{
	class PersonTools
	{
		public:
			//TODO: Длинная строка!
			//исправил
			static void GenerateRandomPerson(char tempName[Person::arraySize], 
				char tempSurname[Person::arraySize], const char Name[10], 
				const char Surname[10], int& tempAge)
			{
				strcpy_s(tempName, Person::arraySize, Name);
				strcpy_s(tempSurname, Person::arraySize, Surname);
				//TODO: Магические числа в коде.
				//могу просто комментарий поясняющий оставить
				//в tempAge генерируется "рандомный" возраст от 0 до 90 лет.
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
				tempSex = (Sex)key;

				switch (tempSex)
				{//TODO: Форматирование
					//TODO: Почему не используем перечисление?
					//исправил
					case Female:
					{
						//TODO: Магические числа в коде.
						//в char массивы передаются рандомные числа от 0 до 9,
						//потому что в них хранятся всего 9 экземпляров имен/фамилий
						GenerateRandomPerson(tempName, tempSurname, FemaleName[rand() % 9],
							FemaleSurname[rand() % 9], tempAge);
						break;
					}
					case Male:
					{
						GenerateRandomPerson(tempName, tempSurname, MaleName[rand() % 9],
							MaleSurname[rand() % 9], tempAge);
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