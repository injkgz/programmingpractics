#include "CheckCin.h"
#include "Person5.h"
#include "Sex.h"
#include "Adult.h"
#include "Child.h"

namespace lab5
{
	Person::Person(char name[ArraySize], char surname[ArraySize],
		int age, enum Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}

	void Person::SetName(char name[ArraySize])
	{
		//TODO: Где проверка на передаваемые значения?
		//исправил
		//TODO: Исправили с помощью дублирования кода.. Теперь исправляйте дубли!
		//исправил
		_name = new char[strlen(name)];
		if (lab5::PersonTools::CheckValidName(name))
		{
			for (int i = 0; i < strlen(name)+1; i++)
			{
				_name[i] = name[i];
				if (name[i] == '\0')
				{
					break;
				}
			}
		}
	}

	void Person::SetSurname(char surname[ArraySize])
	{
		//TODO: Где проверка на передаваемые значения?
		//исправил
		//TODO: Исправили с помощью дублирования кода.. Теперь исправляйте дубли!
		//исправил
		_surname = new char[strlen(surname)];
		if (lab5::PersonTools::CheckValidName(surname))
		{
			for (int i = 0; i < strlen(surname)+1; i++)
			{
				_surname[i] = surname[i];
				if (surname[i] == '\0')
				{
					break;
				}
			}
		}
	}

	void Person::SetAge(unsigned int age)
	{
		const int minAge = 0;
		const int maxAge = 125;

		if (age >= minAge && age <= maxAge)
		{
			_age = age;
		}
	}

	void Person::SetSex(enum Sex sex)
	{
		_sex = sex;
	}

	char* Person::GetName()
	{
		return _name;
	}

	char* Person::GetSurname()
	{
		return _surname;
	}

	int Person::GetAge()
	{
		return _age;
	}

	Sex Person::GetSex()
	{
		return _sex;
	}
	//TODO: Не понял, а где переписывание всего под динамику?
	//исправил
	Person::~Person()
	{
		delete _name;
		delete _surname;
	}

	bool Person::operator==(const Person& good)
	{
		return(!strcmp(_name, good._name) &&
			!strcmp(_surname, good._surname) &&
			_age == good._age && _sex == good._sex);
	}

	bool Person::operator!=(const Person& good)
	{
		return !operator==(good);
	}

	string Person::GetDescription()
	{
		string description = string(this->GetName()) + " " + string(this->GetSurname())
			+ ". Возраст = " + to_string(this->GetAge()) + "\n Пол: ";
		Sex tempSexKey = this->GetSex();
		switch (tempSexKey)
		{
			case Female:
			{
				description += "Женщина";
				break;
			}
			case Male:
			{
				description += "Мужчина";
				break;
			}
		}
		return description;
	}
}