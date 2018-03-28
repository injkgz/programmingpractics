#include "CheckCin.h"


void Add(List* list, Person * person)
{
	Node* temp = new Node();
	temp->Item = *person;

	if (list->head == nullptr)
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
	cout << index << ". Фамилия:";
	cout << item.Item.Surname << endl;
	cout << "Имя: ";
	cout << item.Item.Name << endl;
	switch (item.Item.Sex)
	{
		case 0:
			cout << "Пол:";
			cout << "Женщина"<< endl << endl;
			break;
		case 1:
			cout << "Пол:";
			cout << "Мужчина" << endl << endl;
			break;
		default: break;
	}

}

void ShowList(List* list)
{
	Node* temp = list->head;
	cout << endl << "Всего в списке у нас " << list->CountItems << " личностей!" << endl;
	int index = 1;
	while (temp != nullptr)
	{
		ShowListItem(*temp, index);
		index++;
		temp = temp->next;
	}
	if (list->head == nullptr)
	{
		cout <<endl<< "Список пуст!" << endl;
	}
}

Node* GetByIndex(List* list, int index)
{
	Node* temp = list->head;

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

	if (deletedItem == list->head)
	{
		list->head = deletedItem->next;
		list->head->next = deletedItem->next->next;
		list->head->prev = nullptr;
	}
	else if (deletedItem == list->tail)
	{
		list->tail = deletedItem->prev;
		list->tail->prev = deletedItem->prev->prev;
		list->tail->next = nullptr;
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
	if (list->head == nullptr)
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
	else if (index > list->CountItems)
	{
		while (index > list->CountItems)
		{
			cout << endl << "Не входит в границы списка!"
				<< endl << "Попробуйте ещё раз!" << endl
				<<"Введите индекс элемента: ";
			index = CheckCin(true);
			
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
		list->head = newNode;
		list->tail = newNode;
	}
	else if (index == list->CountItems)
	{
		newNode->prev = list->tail;
		list->tail = newNode;
		newNode->prev->next = newNode;
		list->CountItems++;
	}
	else if (GetByIndex(list, index) != nullptr)
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

void ClearList(List* list)
{
	if (list->head == nullptr && list->tail == nullptr)
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
	list->head = nullptr;
	list->tail = nullptr;
	list->CountItems = 0;
}




