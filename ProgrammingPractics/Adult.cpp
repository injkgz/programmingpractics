#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
<<<<<<< HEAD
	//TODO: Часть проверок можно было бы снять корректным типом данных (беззнаковым)
	//исправил
	void Adult::SetAge(unsigned int age)
=======
	void Adult::SetAge(int age)
>>>>>>> parent of b41fdc8... TODO
	{
		//TODO: Магические числа повторяются ниже!
		//исправил
		if (age >= _minAge && age <= _maxAge)
		{
			_age = age;
		}
		else
		{
<<<<<<< HEAD
			//TODO: спорный способ, но пусть так.
			//??????????????????????
=======
			//TODO: Таким образом класс привязывается к консольному вводу-выводу, а так не должно быть!
			//исправил
>>>>>>> parent of b41fdc8... TODO
			_age = _minAge;
		}
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age,
		enum Sex sex, Adult* marriedOn, char* workPlace)
	{
<<<<<<< HEAD
		//TODO: Ещё есть возможность сократить, используя тут и в child конструктор базового класса.
		//не корректно, потому как конструктор базового класса создаёт объект типа Person
		//а нам нужен объект дочернего класса.
=======
		//TODO: Есть возможность сократить дублирование вызвав следующий конструктор.
		//исправил
>>>>>>> parent of b41fdc8... TODO
		Adult(name, surname, age, sex, workPlace);
		SetMarriedOn(marriedOn);
	}

	Adult::Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, 
		char* workPlace) : Person(name, surname, NULL, sex)
	{
		SetAge(age);
		SetWorkPlace(workPlace);
	}

<<<<<<< HEAD
=======
	//TODO: Этот метод не должен тут находиться!
	//исправил

>>>>>>> parent of b41fdc8... TODO
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