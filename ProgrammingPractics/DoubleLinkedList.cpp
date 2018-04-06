#include "CheckCin.h"
#include "DoubleLinkedList.h"

void Add(List* list, Person * person)
{
	Node* temp = new Node();
	temp->Item = *person;

	if (list->Head == nullptr)
	{
		list->Head = temp;
		list->Tail = temp;
	}
	else
	{
		temp->prev = list->Tail;
		list->Tail->next = temp;
		list->Tail = temp;
	}
	list->CountItems++;
}

void ShowListItem(Node& item, int index)
{
	cout << index<< ". Фамилия:";
	cout << item.Item.Surname << endl;
	cout << "Имя: ";
	cout << item.Item.Name << endl;
	switch (item.Item.Sex)
	{
		case Female:
			cout << "Пол:";
			cout << "Женщина"<< endl << endl;
			break;
		case Male:
			cout << "Пол:";
			cout << "Мужчина" << endl << endl;
			break;
		default: break;
	}

}

void ShowList(List* list)
{
	Node* temp = list->Head;
	cout << endl << "Всего в списке у нас " << list->CountItems << " личностей!" << endl;
	int index = 1;
	while (temp != nullptr)
	{
		ShowListItem(*temp, index);
		index++;
		temp = temp->next;
	}
	if (list->Head == nullptr)
	{
		cout <<endl<< "Список пуст!" << endl;
	}
}

Node* GetByIndex(List* list, int index)
{
	Node* temp = list->Head;

	for (int i = 0; i < index; i++)
	{
		if (temp->next != nullptr)
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

void RemoveByIndex(List* list, int index)
{
	Node* deletedItem = GetByIndex(list, index);

	if (deletedItem == list->Head)
	{
		list->Head = deletedItem->next;

		if (deletedItem->next)
		{
			list->Head->next = nullptr;
		}
		else
		{
			list->Head->next = deletedItem->next->next;
		}

		list->Head->prev = nullptr;
	}
	else if (deletedItem == list->Tail)
	{
		list->Tail = deletedItem->prev;

		if (deletedItem->prev)
		{
			list->Tail->prev = nullptr;
		}
		else
		{
			list->Tail->prev = deletedItem->prev->prev;
		}

		list->Tail->next = nullptr;
	}
	else
	{
		deletedItem->prev->next = deletedItem->next;
		deletedItem->next->prev = deletedItem->prev;
	}
	delete(deletedItem);
	list->CountItems--;
		
}

//Функция записи корректного индекса
int GetCorrectIndex(List* list)
{
	int index = CheckCin(true);
	while (index < 0)
	{
		cout << endl << "Нельзя вводить отрицательное значение!" << endl
			<< "Введите ещё раз: ";
		index = CheckCin(true);
	}
	if (list->Head == nullptr)
	{
		cout << "Список пуст!" << endl
			<< "Вы можете добавить только на позицию [0]!"
			<<endl;
		while (index != 0)
		{
			cout << "Введите ноль!" << endl;
			index = CheckCin(true);
		}
	}
	else if ((index+1) > list->CountItems)
	{
		while (index > list->CountItems)
		{
			cout << endl << "Не входит в границы списка!"
				<< endl << "Попробуйте ещё раз!" << endl
				<<"Введите индекс элемента: ";
			index = CheckCin(true);
			while (index < 0)
			{
				cout << endl << "Нельзя вводить отрицательное значение!" << endl
					<< "Введите ещё раз: ";
				index = CheckCin(true);
			}
			
		}
		return index;
	}
}

void InsertByIndex(List* list, Person *person, int index)
{	
	Node* newNode = new Node();
	newNode->Item = *person;
	if (index == 0)
	{
		list->Head = newNode;
		list->Tail = newNode;
	}
	else if (index == list->CountItems)
	{
		newNode->prev = list->Tail;
		list->Tail = newNode;
		newNode->prev->next = newNode;
		list->CountItems++;
	}
	else if (GetByIndex(list, index) != nullptr)
	{
		Node* temp = GetByIndex(list, index);
		if (temp == list->Head)
		{
			newNode->next = list->Head;
			list->Head->prev = newNode;
			list->Head = newNode;
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

void ClearList(List* list)
{
	if (list->Head == nullptr && list->Tail == nullptr)
	{
		cout << "Список и так чист!";
		return;
	}
	else
	{
		Node* newNode = list->Head;
		int i = 0;
		while ((i+1) != list->CountItems)
		{
			RemoveByIndex(list, i);
			i++;
		}
	}
	list->Head = nullptr;
	list->Tail = nullptr;
	list->CountItems = 0;
}




