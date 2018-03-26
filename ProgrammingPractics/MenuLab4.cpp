#include "DoubleLinkedList.h"
#include "CheckCin.h"
#include "Stack.h"
#include "MenuLab4.h"

Person* MakeRandomPerson()
{
	Person* newPerson = new Person;

	const char* MaleName[] =
	{
		"Вэйдер", "Йода", "Оби-Ван", "Молл",
		"Энакин", "Сидиус", "Рено", "Ктун",
		"Баланар", "Зевс"
	};

	const char* MaleSurname[] =
	{
		"Дарт", "Кеноби", "Скайуокер", "Джексон",
		"Божественный", "Блудрейнов", "Молненосный",
		"Исанов", "Джобс"
	};

	const char* FemaleName[] =
	{
		"Ниа", "Кейтлин", "Федора",
		"Анна", "Маша", "Арабелла",
		"Шадия", "Лея", "Кая", "Герда"
	};

	const char* FemaleSurname[] =
	{
		"Мятежникова", "Старк", "Горе",
		"Хилькевич", "Горышкина", "Лесная",
		"Принцесса", "Ледяная", "Сколедарио",
		"Ланнистер"
	};

	cout << "Введите F - женщина или M - мужчина" << endl;
	char key = _getch();
	int asciiValue = key;
	char insertedKey = key;
	while ((key != 'f') && (key != 'm'))
	{
		cout << endl << "Некорректный символ!" << endl << "Введите F или M" << endl;
		insertedKey = _getch();
		key = insertedKey;
	}

	asciiValue = insertedKey;

	switch (asciiValue)
	{
		case 'f':
		{
			strcpy_s(newPerson->Name, FemaleName[rand() % 10]);
			strcpy_s(newPerson->Surname, FemaleSurname[rand() % 10]);
			newPerson->Sex = Female;
			break;
		}
		case 'm':
		{
			strcpy_s(newPerson->Name, MaleName[rand() % 10]);
			strcpy_s(newPerson->Surname, MaleSurname[rand() % 10]);
			newPerson->Sex = Male;
			break;
		}
		default:
		{
			break;
		}
	}
	return newPerson;
}

void StructChooseMenu()
{
	bool key = true;
	int choosedFunction;

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора лабораторной или выберите тип структур данных: "
			<< endl
			<< "1. Двусвязный список" << endl
			<< "2. Стек" << endl
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
				ListMenu();
				break;
			}
			case 2:
			{
				StackMenu();
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

void ListMenu()
{
	bool key = true;
	int choosedFunction;
	List* list = new List;
	Add(list, MakeRandomPerson());
	Add(list, MakeRandomPerson());
	Add(list, MakeRandomPerson());
	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. ShowList" << endl
			<< "3. GetByIndex " << endl
			<< "4. RemoveByIndex" << endl
			<< "5. InsertByIndex" << endl
			<< "6. ClearList" << endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		ShowList(list);
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;
				cout << endl << "Выход в меню выбора структур" << endl;
				system("pause");
				break;
			}
			case lab4::Add:
			{
				Add(list, MakeRandomPerson());
				ShowList(list);
				break;
			}
			case lab4::ShowList:
			{
				ShowList(list);
				break;
			}
			case lab4::RemoveByIndex:
			{
				cout << "Введите индекс элемента: ";
				int index = CheckCin(true);
				RemoveByIndex(list, index);
				break;
			}
			case lab4::InsertByIndex:
			{
				cout << "Введите индекс элемента: ";
				int index = CheckCin(true);
				InsertByIndex(list, MakeRandomPerson(), index);
				break;
			}
			case lab4::GetByIndex:
			{
				cout << "Введите индекс элемента: ";
				int index = CheckCin(true);
				Node* temp = GetByIndex(list, index);
				if (temp == NULL)
				{
					break;
				}
				ShowListItem(*temp, index);
				break;
			}
			case lab4::ClearList:
			{
				ClearList(list);
				system("color 04");
				cout << endl << "Список пуст!";
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

void StackMenu()
{
	bool key = true;
	int choosedFunction;
	Stack* newStack = NULL;
	PushStack(newStack, MakeRandomPerson());
	PushStack(newStack, MakeRandomPerson());
	PushStack(newStack, MakeRandomPerson());


	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. PushStack " << endl
			<< "2. PopStack" << endl
			<< "3. GetTopStack " << endl
			<< "4. GetFullStack" << endl
			<< "5. GetSizeStack" << endl
			<< "6. IsEmptyStack" << endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		GetFullStack(newStack);
		choosedFunction = CheckCin(true);
		cout << endl;

		switch (choosedFunction)
		{
			case 0:
			{
				key = false;
				cout << endl << "Выход в меню выбора структур" << endl;
				system("pause");
				break;
			}//TODO: Зачем писать полное имя (с lab4)?
			case lab4::PushStack:
			{
				PushStack(newStack, MakeRandomPerson());
				GetFullStack(newStack);
				break;
			}
			case lab4::PopStack:
			{
				PopStack(newStack);
				GetFullStack(newStack);
				break;
			}
			case lab4::GetTopStack:
			{
				GetTopStack(newStack);
				break;
			}
			case lab4::GetFullStack:
			{
				GetFullStack(newStack);
				break;
			}
			case lab4::GetSizeStack:
			{
				int sizeOfNewStack = -1;
				sizeOfNewStack = GetSizeStack(newStack);
				switch (sizeOfNewStack)
				{
					case 0: 
					{
						cout << "Стек пуст!";
					}
					default:
					{
						cout << "В стеке " << sizeOfNewStack << " элементов!";
						GetFullStack(newStack);
					}
				}
				break;
			}
			case lab4::IsEmptyStack:
			{
				IsEmptyStack(newStack);
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