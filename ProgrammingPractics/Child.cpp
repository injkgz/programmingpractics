#include "Child.h"

namespace lab5
{
	void Child::SetAge(int Age)
	{
		if (Age < 18 && Age > 0)
		{
			_age = Age;
		}
		else
		{
			cout << endl << "Неверный возраст!" << endl
				<< "Ребёнок не может быть старше 18 лет!" << endl
				<< "Попробуйте ещё раз!" << endl
				<< "Введите возраст: " << endl;
			int tempAge = CheckCin(true);
			while (tempAge < 18 && tempAge > 125)
			{
				cout << endl << "Введён некорректный возраст!" << endl
					<< "Попробуйте ещё раз!" << endl;
				tempAge = CheckCin(true);
			}
			_age = Age;
		}
	}

	int Child::GetAge()
	{
		int Age = Person::GetAge();
		return Age;
	}
}