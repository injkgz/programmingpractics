#include "Adult.h"

namespace lab5
{
	void Adult::SetAge(int Age)
	{
		if (Age >= 18 && Age <= 125)
		{
			_age = Age;
		}
		else
		{
			cout << endl << "�������� �������!" << endl
				<< "�������� �� ����� ���� ������ 18 ���!" << endl
				<< "���������� ��� ���!" << endl
				<< "������� �������: " << endl;
			int tempAge = CheckCin(true);
			while (tempAge < 18 && tempAge > 125)
			{
				cout << endl << "����� ������������ �������!" << endl
					<< "���������� ��� ���!" << endl;
				tempAge = CheckCin(true);
			}
			_age = tempAge;
		}
	}

	Adult::Adult(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex, Adult* marriedOn, char* workPlace)
	{
		Person::SetName(Name);
		Person::SetSurname(Surname);
		Person::SetSex(Sex);
		SetAge(Age);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
	}

	Adult* Adult::GetRandom()
	{
		const char* MaleName[] =
		{
			"������", "����", "���-���", "����",
			"������", "������", "����", "����",
			"�������", "����"
		};

		const char* MaleSurname[] =
		{
			"����", "������", "���������", "�������",
			"������������", "����������", "�����������",
			"������", "�����"
		};

		const char* FemaleName[] =
		{
			"���", "�������", "������",
			"����", "����", "��������",
			"�����", "���", "���", "�����"
		};

		const char* FemaleSurname[] =
		{
			"�����������", "�����", "����",
			"���������", "���������", "������",
			"���������", "�������", "����������",
			"���������"
		};

		const char* WorkPlaces[] = 
		{ 
			"Google", "Apple", "Yandex", "Tesla",
			"Mail.Ru", "Huawei", "Xiaomi", "HTC"
		};

		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		char tempWorkPlace[Person::arraySize];
		int tempAge = rand() % 90 - 18;
		Sex tempSex;
		int key = rand() % 1;
		tempSex = (Sex)key;

		switch (tempSex)
		{
			case Female:
			{
				 lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, FemaleName[rand() % 9],
					FemaleSurname[rand() % 9]);
				break;
			}
			case Male:
			{
				lab5::PersonTools::GenerateRandomPerson(tempName, tempSurname, MaleName[rand() % 9],
					MaleSurname[rand() % 9]);
				break;
			}
			default:
			{
				break;
			}
		}
		strcpy_s(tempWorkPlace, Person::arraySize, WorkPlaces[rand() % 8]);
		Adult *tempMarriedOn = nullptr;
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriedOn, tempWorkPlace);
	}

	void  Adult::SetMarriedOn(Adult* marriedOn)
	{
		if (marriedOn->GetSex() != this->GetSex())
		{
			marriedOn->SetMarriedOn(this);
			_marriedOn = marriedOn;
		}
		else
		{
			cout << endl << "���, �� �� �����������!"
				<< endl << "�������, ��� �� ��������!"
				<< endl << "��� ������� ��� ����-������ ���������������� ����!";
			Adult* tempMarriedOn = GetRandom();
			SetMarriedOn(tempMarriedOn);
			GetPause();
		}
	}

	void  Adult::SetWorkPlace(char* workPlace)
	{
		strcpy_s(_workPlace, arraySize, workPlace);
	}

	void Adult::MakeWedding()
	{
		Adult* tempMarriedOn = GetRandom();
		SetMarriedOn(tempMarriedOn);
	}
	
}