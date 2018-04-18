#include "Child.h"

namespace lab5
{
	Child::Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		if (mother != nullptr)
		{
			SetMother(mother);
		}
		if (father != nullptr)
		{
			SetFather(father);
		}
		SetSchool(school);
	};

	void Child::SetAge(int Age)
	{
		if (Age < 18 && Age >= 0)
		{
			_age = Age;
		}
		else
		{//TODO: Таким образом класс привязывается к консольному вводу-выводу, а так не должно быть!
			cout << endl << "Неверный возраст!" << endl
				<< "Ребёнок не может быть старше 18 лет!" << endl
				<< "Попробуйте ещё раз!" << endl
				<< "Введите возраст: " << endl;
			int tempAge = CheckCin(true);

			while (tempAge < 18 && tempAge >= 0)
			{
				cout << endl << "Введён некорректный возраст!" << endl
					<< "Попробуйте ещё раз!" << endl;
				tempAge = CheckCin(true);
			}
			_age = Age;
		}
	}

	Child* Child::GetRandom()
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
			"Зерде"
		};
		//TODO: Этот метод не должен тут находиться!
		char tempName[ArraySize];
		char tempSurname[ArraySize];
		char tempSchool[ArraySize];
		int tempAge = rand() % 17;
		Sex tempSex;
		int key = rand() % 1;
		tempSex = (Sex)key;
		Adult* tempMother = nullptr;
		Adult* tempFather = nullptr;
		switch (tempSex)
		{//TODO: Очень много магических цифр ниже, так и не исправили!
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

		strcpy_s(tempSchool, ArraySize, School[rand() % 7]);

		return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather, tempSchool);
	}

	int Child::GetAge()
	{
		//TODO: Именование локальных переменных
		int Age = Person::GetAge();
		return Age;//TODO: Можно не создавать отдельную переменную.
	}

	void Child::SetMother(Adult* mother)
	{//TODO: Где проверка на передаваемые значения?
		if (mother->GetSex() == Female)
		{
			_mother = mother;
		}
		else
		{
			cout << endl << "Мама не может быть мужчиной!";
		}
	}

	void Child::SetFather(Adult* father)
	{//TODO: Где проверка на передаваемые значения?
		if (father->GetSex() == Male)
		{
			_father = father;
		}
		else
		{
			cout << endl << "Папа может всё, что угодно!"
				<< endl << "Только мамой не может быть!" << endl;
		}
	}
	
	void Child::SetSchool(char school[ArraySize])
	{//TODO: Где проверка на передаваемые значения?
		strcpy_s(_school, ArraySize, school);
	}

	Adult* Child::GetMother()
	{
		if (_mother != nullptr)
		{
			return _mother;
		}
		else
		{
			cout << endl << "Мамы нет..." << endl;
		}
	}

	Adult* Child::GetFather()
	{
		if (_father != nullptr)
		{
			return _father;
		}
		else
		{
			cout << endl << "Папы нет..." << endl;
		}
	}
	
	Child::~Child()
	{
		delete _father;
		delete _mother;
		delete _school;
	}

	char* Child::GetSchool()
	{
		return _school;
	}

	string Child::GetDescription()
	{
		string description = Person::GetDescription();
		description += "\nУчится в " + string(this->GetSchool());
		if (_mother != nullptr)
		{
			description += "\nМама: " + string(this->GetMother()->GetDescription());
		}
		if (_father != nullptr)
		{
			description += "\nПапа: " + string(this->GetFather()->GetDescription());
		}
		return description;
	}
}