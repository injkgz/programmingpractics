#include "Child.h"

namespace lab5
{
	void Child::SetAge(int Age)
	{
		if (Age < 18)
		{
			cout << endl << "�� ����� ������������ �������� ��� �������� ������!" << endl
				<< "�� ������ ���� ������ 18!" << endl;

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