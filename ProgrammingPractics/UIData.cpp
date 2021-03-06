#include "UIData.h"


void DoubleListMenu(TemplateList<double>* list, int number)
{
	if (list == nullptr)
	{
		return; 
	}

	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (key)
	{
		system("cls");
		cout << endl
			<< "�� ��������� � ����� ������ DOUBLE" << endl
			<< "������� 0 ��� ������ � ���� ������ ��������� ��� �������� �������: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "��������� ����� ����������� ���� �� ��� ���, ���� �� �� ������ ���������� ��������!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;//TODO: ��� ������ ����� �� ���������?
				//��������
				cout << endl << "����� �� ����." << endl;
				system("pause");
				break;
			}
			case 1:
			{
				//TODO: �������� �� ���������, �� ��������� �����.
				//������� �����!
				cout << "������� ������� (�� ������������ �����! ����� ����� �������� �������): ";
				double* tempElem = new double(CheckCin(false));
				list->Add(*tempElem);
				break;
			}
			case 2:
			{
				cout << "������� ������!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "����� �������� �� �������" << endl;
				cout << "������� ������: " << endl;
				int index;
				list->GetCorrectIndex(index);
				cout << "��������� �������: ";
				double findObject = list->Find(index);
				double* findElement = &findObject;
				if (findElement != nullptr)
				{
					cout << *findElement;
				}
				else
				{
					cout << "������� �� ������";
				}
				break;
			}
			case 4:
			{
				cout<<"���������� ��������� = " <<list->GetCount();
				break;
			}
			case 5:
			{
				cout << "������� ������!" << endl;
				list->ShowList();
				break;
			}
			default:
			{
				break;
			}
		}

		if (choosedFunction >= 1)
		{
			GetPause();
		}
	}

}

void UIPerson()
{
	TemplateList< lab5::Person* >* list = new TemplateList<lab5::Person*>();
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (key)
	{
		system("cls");
		cout << endl
			<< "�� ��������� � ����� ������ Person" << endl
			<< "������� 0 ��� ������ � ���� ������ ��������� ��� �������� �������: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "��������� ����� ����������� ���� �� ��� ���, ���� �� �� ������ ���������� ��������!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;//TODO: ��� ������ ����� �� ���������?
				//��������
				cout << endl << "����� �� ����." << endl;
				system("pause");
				break;
			}
			case 1:
			{//TODO: ������ �� ������� ��� ���������� - ��� ���������� ��������� ���������.
				//��������
				cout << "��������� 3 �������: 2 Adult � 1 Child!" << endl;
				list->Add(lab5::FamilyTools::GetRandomAdult(Male));
				list->Add(lab5::FamilyTools::GetRandomAdult(Female));
				list->Add(lab5::FamilyTools::GetRandomChild());
				break;
			}
			case 2:
			{
				cout << "������� ������!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "����� �������� �� �������" << endl;
				cout << "������� ������: " << endl;
				int index;
				list->GetCorrectIndex(index);
				cout << "��������� �������: ";
				Person* findObject = list->Find(index);
				if (findObject != nullptr)
				{
					cout << findObject;
				}
				else
				{
					cout << "������� �� ������";
				}
				break;
			}
			case 4:
			{
				cout << "���������� ��������� = " << list->GetCount();
				break;
			}
			case 5:
			{
				cout << "������� ������!" << endl;
				list->ShowList();
				break;
			}
			default:
			{
				break;
			}
		}

		if (choosedFunction >= 1)
		{
			GetPause();
		}
	}
}

void UIList()
{
	TemplateList<TemplateList<double>*>* list = new TemplateList<TemplateList<double>*>();
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (key)
	{
		system("cls");
		cout << endl
			<< "�� ��������� � ����� ������ list" << endl
			<< "������� 0 ��� ������ � ���� ������ ��������� ��� �������� �������: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find List and Work with it" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "��������� ����� ����������� ���� �� ��� ���, ���� �� �� ������ ���������� ��������!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{//TODO: ��� ������ ����� �� ���������?
				//��������
				key = false;
				cout << endl << "����� �� ����." << endl;
				system("pause");
				break;
			}
			case 1:
			{
				list->Add(new TemplateList<double>);
				break;
			}
			case 2:
			{
				cout << "������� ������!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "����� �������� �� �������" << endl;
				cout << "������� ������: " << endl;
				int index;
				if (list->GetCorrectIndex(index)==1)
				{
					break;
				}
				DoubleListMenu(list->Find(index), index);
				break;
			}
			case 4:
			{
				cout << "���������� ��������� = " << list->GetCount();
				break;
			}
			case 5:
			{
				cout << "������� ������!" << endl;
				list->ShowList();
				break;
			}
			default:
			{
				break;
			}
		}

		if (choosedFunction >= 1)
		{
			GetPause();
		}
	}

}