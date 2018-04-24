#include "Child.h"

namespace lab5
{
<<<<<<< HEAD
	Child::Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school) : Person(name, surname, NULL, sex)
	{//TODO: Можно сократить, использовав правильно конструктор базового
=======
	Child::Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school)
	{
		SetName(name);
		SetSurname(surname);
>>>>>>> parent of b41fdc8... TODO
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

<<<<<<< HEAD
	//TODO: Именование. Правильный тип.
	//исправил
	void Child::SetAge(unsigned int age)
=======
	void Child::SetAge(int Age)
>>>>>>> parent of b41fdc8... TODO
	{
		if (age <= _maxAge && age >= _minAge)
		{
			_age = age;
		}
		else
		{//TODO: Таким образом класс привязывается к консольному вводу-выводу, а так не должно быть!
		 //исправил
			_age = _minAge;
		}
	}


	int Child::GetAge()
	{
<<<<<<< HEAD
		return Person::GetAge();;
	}

	void Child::SetMother(Adult* mother)
	{//TODO: Если не попадёте в пол - будет непонятное поведение. Нет никакой информации в ответ и значение не присвоено.

=======
		//TODO: Именование локальных переменных
		return Person::GetAge();;//TODO: Можно не создавать отдельную переменную.
		//исправил
	}

	void Child::SetMother(Adult* mother)
	{//TODO: Где проверка на передаваемые значения?
	 //исправил
>>>>>>> parent of b41fdc8... TODO
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
<<<<<<< HEAD
		{//TODO: Привязка к консоли.
		 //исправил.
			return nullptr;
=======
		{
			cout << endl << "Мамы нет..." << endl;
>>>>>>> parent of b41fdc8... TODO
		}
	}

	Adult* Child::GetFather()
	{
		if (_father != nullptr)
		{
			return _father;
		}
		else
<<<<<<< HEAD
		{//TODO: Привязка к консоли.
			//исправил.
			return nullptr;
=======
		{
			cout << endl << "Папы нет..." << endl;
>>>>>>> parent of b41fdc8... TODO
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