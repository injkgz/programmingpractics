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
{//TODO: Меню мигает как новогодняя ёлка. Это неправильно!
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
{//TODO: Неправильная логика. Перед добавлением должно быть предупреждение, что списка нет. 
	//TODO: Также нужно проверить на попадание индекса в границы
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



