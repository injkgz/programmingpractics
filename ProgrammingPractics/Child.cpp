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
		if (Age <= _maxAge && Age >= _minAge)
		{
			_age = Age;
		}
		else
		{//TODO: Таким образом класс привязывается к консольному вводу-выводу, а так не должно быть!
		 //исправил
			_age = _minAge;
		}
	}


	int Child::GetAge()
	{
		//TODO: Именование локальных переменных
		return Person::GetAge();;//TODO: Можно не создавать отдельную переменную.
		//исправил
	}

	void Child::SetMother(Adult* mother)
	{//TODO: Где проверка на передаваемые значения?
	 //исправил
		if (mother != nullptr)
		{
			if (mother->GetSex() == Female)
			{
				_mother = mother;
			}
		}
	}

	void Child::SetFather(Adult* father)
	{//TODO: Где проверка на передаваемые значения?
		//исправил
		if (father != nullptr)
		{
			if (father->GetSex() == Male)
			{
				_father = father;
			}
		}
	}
	
	void Child::SetSchool(char* school)
	{//TODO: Где проверка на передаваемые значения?
		//исправил
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