#include "Child.h"

namespace lab5
{
	Child::Child(char* name, char* surname, int age, Sex sex, Adult* mother, 
		Adult* father, char* school) : Person(name, surname, NULL, sex) // TODO: Нулл - нафиг!
	{
		SetAge(age);
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

	void Child::SetAge(unsigned int age)
	{
		if (age <= _maxAge && age >= _minAge)
		{
			_age = age;
		}
		else
		{
			_age = _minAge;
		}
	}


	int Child::GetAge()
	{
		return Person::GetAge();;
	}

	void Child::SetMother(Adult* mother)
	{//TODO: Если не попадёте в пол - будет непонятное поведение. Нет никакой информации в ответ и значение не присвоено.

		if (mother != nullptr)
		{
			if (mother->GetSex() == Female)
			{
				_mother = mother;
			}
		}
	}

	void Child::SetFather(Adult* father)
	{//TODO: Если не попадёте в пол - будет непонятное поведение. Нет никакой информации в ответ и значение не присвоено.
		if (father != nullptr)
		{
			if (father->GetSex() == Male)
			{
				_father = father;
			}
		}
	}
	
	void Child::SetSchool(char* school)
	{
		if (school != nullptr)
		{
			strcpy_s(_school, ArraySize, school);
		}
	}

	Adult* Child::GetMother()
	{
		if (_mother != nullptr)
		{
			return _mother;
		}
		else
		{
			return nullptr;
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
			return nullptr;
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