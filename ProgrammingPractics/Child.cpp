#include "Child.h"

namespace lab5
{
	void Child::SetAge(int Age)
	{
		if (Age < 18)
		{
			cout << endl << "Вы ввели некорректное значение для возраста ребёнка!" << endl
				<< "Он должен быть младше 18!" << endl;

		}
		else
		{
			Person::SetAge(Age);
		}
	}

	int Child::GetAge()
	{
		int Age = Person::GetAge();
		return Age;
	}
}