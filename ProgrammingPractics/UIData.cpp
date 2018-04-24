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
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;
				cout << endl << "Выход из программы." << endl;
				system("pause");
				break;
			}
			case 1:
			{
				cout << "Введите элемент: ";
				double tempElem = CheckCin(false);
				list->Add(&tempElem);
				break;
			}
			case 2:
			{
				cout << "Очищаем список!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "Поиск элемента по индексу" << endl;
				cout << "Введите индекс: " << endl;
				int index;
				list->GetCorrectIndex(index);
				cout << "Найденный элемент: ";
				double findObject = *list->Find(index);
				double* findElement = &findObject;
				if (findElement != nullptr)
				{
					cout << *findElement;
				}
				else
				{
					cout << "Элемент не найден";
				}
				break;
			}
			case 4:
			{
				cout<<"Количество элементов = " <<list->GetCount();
				break;
			}
			case 5:
			{
				cout << "Выводим список!" << endl;
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
	TemplateList<lab5::Person>* list = new TemplateList<lab5::Person>();
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;
				cout << endl << "Выход из программы." << endl;
				system("pause");
				break;
			}
			case 1:
			{
				list->Add(lab5::FamilyTools::GetRandomAdult(Male));
				list->Add(lab5::FamilyTools::GetRandomAdult(Female));
				list->Add(lab5::FamilyTools::GetRandomChild());
				break;
			}
			case 2:
			{
				cout << "Очищаем список!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "Поиск элемента по индексу" << endl;
				cout << "Введите индекс: " << endl;
				int index;
				list->GetCorrectIndex(index);
				cout << "Найденный элемент: ";
				Person* findObject = list->Find(index);
				if (findObject != nullptr)
				{
					cout << findObject;
				}
				else
				{
					cout << "Элемент не найден";
				}
				break;
			}
			case 4:
			{
				cout << "Количество элементов = " << list->GetCount();
				break;
			}
			case 5:
			{
				cout << "Выводим список!" << endl;
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
	TemplateList<TemplateList<double>>* list = new TemplateList<TemplateList<double>>();
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. Clear" << endl
			<< "3. Find List and Work with it" << endl
			<< "4. GetCount" << endl
			<< "5. ShowList" << endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;
				cout << endl << "Выход из программы." << endl;
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
				cout << "Очищаем список!" << endl;
				list->Clear();
				break;
			}
			case 3:
			{
				cout << "Поиск элемента по индексу" << endl;
				cout << "Введите индекс: " << endl;
				int index;
				list->GetCorrectIndex(index);
				DoubleListMenu(list->Find(index), index);
				break;
			}
			case 4:
			{
				cout << "Количество элементов = " << list->GetCount();
				break;
			}
			case 5:
			{
				cout << "Выводим список!" << endl;
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