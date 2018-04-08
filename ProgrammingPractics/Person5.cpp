#include "CheckCin.h"
#include "Person5.h"
#include "Sex.h"

namespace lab5
{
	Person::Person(char Name[arraySize], char Surname[arraySize],
		int Age, enum Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	void Person::SetName(char name[arraySize])
	{
		strcpy_s(_name, arraySize, name);
	}

	//TODO: Пустые строки между методами.
	//cделал
	void Person::SetSurname(char surname[arraySize])
	{
		strcpy_s(_surname, arraySize, surname);
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

		//TODO: Зачем это здесь?
		//убрал
	}
}