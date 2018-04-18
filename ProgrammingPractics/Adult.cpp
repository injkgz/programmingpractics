#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
	void Adult::SetAge(int age)
	{
		//TODO: Магические числа повторяются ниже!
		//исправил
		if (age >= _minAge && age <= _maxAge)
		{
			_age = age;
		}
		else
		{
			//TODO: Таким образом класс привязывается к консольному вводу-выводу, а так не должно быть!
			//исправил
			_age = _minAge;
		}
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age,
		enum Sex sex, Adult* marriedOn, char* workPlace)
	{
		//TODO: Есть возможность сократить дублирование вызвав следующий конструктор.
		//исправил
		Adult(name, surname, age, sex, workPlace);
		SetMarriedOn(marriedOn);
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, char* workPlace)
	{
		Person::SetName(name);
		Person::SetSurname(surname);
		Person::SetSex(sex);
		SetAge(age);
		SetWorkPlace(workPlace);
	}

	//TODO: Этот метод не должен тут находиться!
	//исправил

	void  Adult::SetMarriedOn(Adult* marriedOn)
	{//TODO: Где проверка на передаваемые значения?
		//исправил
		if (marriedOn != nullptr && this->GetSex() != marriedOn->GetSex())
		{
			_marriedOn = marriedOn;
		}
	}

	void  Adult::SetWorkPlace(char* workPlace)
	{//TODO: Где проверка на передаваемые значения?
		//исправил
		if (workPlace != nullptr)
		{
			strcpy_s(_workPlace, ArraySize, workPlace);
		}
	}


	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	Adult* Adult::GetMarriedOn()
	{
		return _marriedOn;
	}

	string Adult::GetDescription()
	{
		string description = Person::GetDescription();
		description += "\nРаботает в " + string(this->GetWorkPlace());
		if (_marriedOn != nullptr)
		{
			description += "\n Состоит в браке с " + string(this->GetMarriedOn()->GetName())
				+ " " + string(this->GetMarriedOn()->GetSurname());
		}
		else
		{
			description += "\n Не состоит в браке.";
		}
		return description;
	}

	Adult::~Adult()
	{
		delete _marriedOn;
		delete _workPlace;
	}
}