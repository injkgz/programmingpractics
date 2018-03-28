#include "CheckCin.h"
#include "Person5.h"
#include "Sex.h"

namespace lab5
{
	//TODO: Длины строк может не хватить
	//TODO: Нельзя поменять длинну строк из одного места!
	//TODO: Аргументы метода не по RSDN!
	Person::Person(char Name[20], char Surname[20], int Age, enum Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	void Person::SetName(char name[20])
	{
		strcpy_s(Name, name);
	}
	void Person::SetSurname(char surname[20])
	{
		strcpy_s(Surname, surname);
	}
	void Person::SetAge(int age)
	{//TODO: 0 тоже может быть? А отрицательный возраст
		Age = age;
	}
	void Person::SetSex(enum Sex sex)
	{
		Sex = sex;
	}
	char* Person::GetName()
	{
		return Name;
	}
	char* Person::GetSurname()
	{
		return Surname;
	}
	int Person::GetAge()
	{
		return Age;
	}
	Sex Person::GetSex()
	{
		return Sex;
	}

	//TODO: Нижние перегрузки - во-первых дублируются, во-вторых скорее всего работают некорректно
	//TODO: А чтобы понять, насколько правильно они отрабатывают - распишите как работает strcmp
	bool Person::operator==(const Person& good)
	{
		return(!strcmp(Name, good.Name) &&
			!strcmp(Surname, good.Surname) &&
			Age == good.Age && Sex == good.Sex);
	}

	bool Person::operator!=(const Person& good)
	{
		return(!strcmp(Name, good.Name) &&
			!strcmp(Surname, good.Surname) &&
			Age != good.Age && Sex != good.Sex);
	}
}