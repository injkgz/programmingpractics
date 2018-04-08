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
			cout << endl << "�������� �������!" << endl
				<< "������ �� ����� ���� ������ 18 ���!" << endl
				<< "���������� ��� ���!" << endl
				<< "������� �������: " << endl;
			int tempAge = CheckCin(true);
			while (tempAge < 18 && tempAge > 125)
			{
				cout << endl << "����� ������������ �������!" << endl
					<< "���������� ��� ���!" << endl;
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