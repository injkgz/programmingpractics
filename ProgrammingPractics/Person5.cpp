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
		strcpy_s(Name, arraySize, name);
	}
	void Person::SetSurname(char surname[arraySize])
	{
		strcpy_s(Surname, arraySize, surname);
	}
	void Person::SetAge(int age)
	{
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

	bool Person::operator==(const Person& good)
	{
		return(!strcmp(Name, good.Name) &&
			!strcmp(Surname, good.Surname) &&
			Age == good.Age && Sex == good.Sex);
	}

	bool Person::operator!=(const Person& good)
	{
		return !operator==(good);
		/*return(strcmp(Name, good.Name) &&
			strcmp(Surname, good.Surname) &&
			Age != good.Age && Sex != good.Sex);*/
	}
}