#include "DoubleLinkedList.h"
#include "CheckCin.h"


void Add(List* list, Person * person)
{
	Node* temp = new Node();
	temp->Item = *person;

	if (list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		temp->prev = list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	list->CountItems++;
}

void ShowListItem(Node& item, int index)
{
	system("color 0A");
	cout << index << ". Фамилия:";
	system("color 04");
	cout << item.Item.Surname << endl;
	system("color 0A");
	cout << "Имя: ";
	system("color 04");
	cout << item.Item.Name << endl;
	switch (item.Item.Sex)
	{
		case 0:
			system("color 0A");
			cout << "Пол:";
			system("color 04");
			cout << "Женщина"<< endl << endl;
			break;
		case 1:
			system("color 0A");
			cout << "Пол:";
			system("color 04");
			cout << "Мужчина" << endl << endl;
			break;
		default: break;
	}

}

void ShowList(List* list)
{
	Node* temp = list->head;
	system("color 06");
	cout << endl << "Всего в списке у нас " << list->CountItems << " личностей!" << endl;
	int index = 1;
	while (temp != NULL)
	{
		ShowListItem(*temp, index);
		index++;
		temp = temp->next;
	}
	if (list->head == NULL)
	{
		cout <<endl<< "Список пуст!" << endl;
	}
}

Node* GetByIndex(List* list, int index)
{
	Node* temp = list->head;
	if (list->head == NULL)
	{
		cout << endl << "Список пуст!" << endl;
		cout << "Для начала добавьте элемент!";
		return NULL;
	}
	else
	{
		if (index + 1 > list->CountItems)
		{
			cout << "Элемента с таким индексом нет!";
			return NULL;
		}
		else 
		{

			for (int i = 0; i < index; i++)
			{
				if (temp->next != NULL)
				{
					temp = temp->next;
				}
				else
				{
					i = index;
				}
			}

			return temp;
		}
	}
}

void RemoveByIndex(List* list, int index)
{
	Node* deletedItem = GetByIndex(list, index);
	if (list->head == NULL)
	{
		cout << endl << "Список пуст!" << endl;
		cout << "Для начала добавьте элемент!";
	}
	else
	{
		if (index + 1 > list->CountItems)
		{
			cout << "Элемента с таким индексом нет!";
		}
		else
		{

			if (deletedItem == list->head)
			{
				list->head = deletedItem->next;
				list->head->next = deletedItem->next->next;
				list->head->prev = NULL;
			}
			else if (deletedItem == list->tail)
			{
				list->tail = deletedItem->prev;
				list->tail->prev = deletedItem->prev->prev;
				list->tail->next = NULL;
			}
			else
			{
				deletedItem->prev->next = deletedItem->next;
				deletedItem->next->prev = deletedItem->prev;
			}
			delete(deletedItem);
			list->CountItems--;
		}
	}
}

void InsertByIndex(List* list, Person *person, int index)
{
	Node* newNode = new Node();
	newNode->Item = *person;
	if (list->head == NULL)
	{
		if (index == 0)
		{
			list->head = newNode;
			list->tail = newNode;
		}
		else
		{
			cout << endl << "Список пуст!" << endl;
			cout << "Для начала добавьте элемент!";
		}
	}
	else
	{
		if (index == list->CountItems)
		{
			newNode->prev = list->tail;
			list->tail = newNode;
			newNode->prev->next = newNode;
			list->CountItems++;
		}
		else if ((index + 1) > list->CountItems)
		{
			cout << "Нельзя вставить элемент по данному индексу!";
		}
		else
		{
			if (GetByIndex(list, index) != NULL)
			{
				Node* temp = GetByIndex(list, index);
				if (temp == list->head)
				{
					newNode->next = list->head;
					list->head->prev = newNode;
					list->head = newNode;
					
				}
				else
				{
					temp->prev->next = newNode;
					newNode->prev = temp->prev;
					temp->prev = newNode;
					newNode->next = temp;
				}
				list->CountItems++;
			}
		}
	}
}

void ClearList(List* list)
{
	if (list->head == NULL && list->tail == NULL)
	{
		cout << "Список и так чист!";
		return;
	}
	else
	{
		Node* newNode = list->head;
		int i = 0;
		while ((i+1) != list->CountItems)
		{
			RemoveByIndex(list, i);
			i++;
		}
	}
	list->head = NULL;
	list->tail = NULL;
	list->CountItems = 0;
}


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
		cout << endl <<"Некорректный символ!"<<endl<<"Введите F или M"<<endl;
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


