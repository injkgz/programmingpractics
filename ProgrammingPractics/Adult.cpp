#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
	void Adult::SetAge(int Age)
	{
		if (Age >= 18 && Age <= 125)
		{
			_age = Age;
		}
		else
		{
			cout << endl << "Неверный возраст!" << endl
				<< "Взрослый не может быть младше 18 лет!" << endl
				<< "Попробуйте ещё раз!" << endl
				<< "Введите возраст: " << endl;
			int tempAge = CheckCin(true);
			while (tempAge < 18 && tempAge > 125)
			{
				cout << endl << "Введён некорректный возраст!" << endl
					<< "Попробуйте ещё раз!" << endl;
				tempAge = CheckCin(true);
			}
			_age = tempAge;
		}
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age,
		enum Sex sex, Adult* marriedOn, char* workPlace)
	{
		Person::SetName(name);
		Person::SetSurname(surname);
		Person::SetSex(sex);
		SetAge(age);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, char* workPlace)
	{
		Person::SetName(name);
		Person::SetSurname(surname);
		Person::SetSex(sex);
		SetAge(age);
		SetWorkPlace(workPlace);
	}

	Adult* Adult::GetRandom(Sex sex)
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
			"Mail.Ru", "Huawei", "Xiaomi", "HTC"
		};

		char tempName[ArraySize];
		char tempSurname[ArraySize];
		char tempWorkPlace[ArraySize];
		int tempAge = 18 + rand() % 90;
		int key = rand() % 2;
		Sex tempSex;
		if (sex != NULL)
		{
			tempSex = Sex(key);
		}
		else
		{
			tempSex = Sex(!sex);
		}
		switch (tempSex)
		{
			case Female:
			{
				lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, FemaleName[rand() % 9],
					FemaleSurname[rand() % 9]);
				break;
			}
			case Male:
			{
				lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, MaleName[rand() % 9],
					MaleSurname[rand() % 9]);
				break;
			}
			default:
			{
				break;
			}
		}
		strcpy_s(tempWorkPlace, Person::ArraySize, WorkPlaces[rand() % 8]);
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempWorkPlace);
	}

	void  Adult::SetMarriedOn(Adult* marriedOn)
	{
		_marriedOn = marriedOn;
	}

	void  Adult::SetWorkPlace(char* workPlace)
	{
		strcpy_s(_workPlace, ArraySize, workPlace);
	}


	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	Adult* Adult::GetMarriedOn()
	{
		return _marriedOn;
	}

	string Adult::GetDescription()
	{
		string description = Person::GetDescription();
		description += "\nРаботает в " + string(this->GetWorkPlace());
		if (_marriedOn != nullptr)
		{
			description += "\n Состоит в браке с " + string(this->GetMarriedOn()->GetDescription());
		}
		else
		{
			description += "\n Не состоит в браке.";
		}
		return description;
	}

	Adult::~Adult()
	{
		delete _marriedOn;
		delete _workPlace;
	}
}