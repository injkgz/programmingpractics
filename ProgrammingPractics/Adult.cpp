#include "Adult.h"

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

	Adult::Adult(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex, Adult* marriedOn, char* workPlace)
	{
		Person::SetName(Name);
		Person::SetSurname(Surname);
		Person::SetSex(Sex);
		SetAge(Age);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
	}

	Adult* Adult::GetRandom()
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

		char tempName[arraySize];
		char tempSurname[arraySize];
		char tempWorkPlace[arraySize];
		int tempAge = rand() % 90 - 18;
		Sex tempSex;
		int key = rand() % 1;
		tempSex = (Sex)key;

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
		strcpy_s(tempWorkPlace, Person::arraySize, WorkPlaces[rand() % 8]);
		Adult *tempMarriedOn = nullptr;
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriedOn, tempWorkPlace);
	}

	void  Adult::SetMarriedOn(Adult* marriedOn)
	{
		if (marriedOn->GetSex() != this->GetSex())
		{
			marriedOn->SetMarriedOn(this);
			_marriedOn = marriedOn;
		}
		else
		{
			cout << endl << "Сэр, мы не толерантные!"
				<< endl << "Надеюсь, что вы ошиблись!"
				<< endl << "Щас подыщем вам кого-нибудь противоположного пола!";
			Adult* tempMarriedOn = GetRandom();
			SetMarriedOn(tempMarriedOn);
		}
	}

	void  Adult::SetWorkPlace(char* workPlace)
	{
		strcpy_s(_workPlace, arraySize, workPlace);
	}

	void Adult::MakeWedding()
	{
		Adult* tempMarriedOn = GetRandom();
		SetMarriedOn(tempMarriedOn);
	}
	
	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	Adult* Adult::GetMarriedOn()
	{
		return _marriedOn;
	}

	string Adult::GetDescriptionAdult()
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
}