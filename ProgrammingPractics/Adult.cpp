#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
	//TODO: Часть проверок можно было бы снять корректным типом данных (беззнаковым)
	//исправил
	void Adult::SetAge(unsigned int age)
	{
		if (age >= _minAge && age <= _maxAge)
		{
			_age = age;
		}
		else
		{
			//TODO: спорный способ, но пусть так.
			//??????????????????????
			_age = _minAge;
		}
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age,
		enum Sex sex, Adult* marriedOn, char* workPlace)
	{
		//TODO: Ещё есть возможность сократить, используя тут и в child конструктор базового класса.
		//исправил
		Adult(name, surname, age, sex, workPlace);
		SetMarriedOn(marriedOn);
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, 
		char* workPlace) : Person(name, surname, NULL, sex)
	{
		SetAge(age);
		SetWorkPlace(workPlace);
	}

	void  Adult::SetMarriedOn(Adult* marriedOn)
	{
		if (marriedOn != nullptr && this->GetSex() != marriedOn->GetSex())
		{
			_marriedOn = marriedOn;
		}
	}

	void  Adult::SetWorkPlace(char* workPlace)
	{
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