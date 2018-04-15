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
		strcpy_s(_name, ArraySize, name);
	}

	void Person::SetSurname(char surname[ArraySize])
	{
		strcpy_s(_surname, ArraySize, surname);
	}

	void Person::SetAge(int age)
	{
		_age = age;
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