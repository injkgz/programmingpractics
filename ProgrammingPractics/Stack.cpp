#include "CheckCin.h"
#include "Stack.h"


void PushStack(Stack*& stackItem, Person *person)
{//TODO: В предыдущей лабе был nulptr, тут NULL - что лучше использовать?
	Stack *temp = new Stack;
	if (stackItem == NULL)
	{
		stackItem = temp;
		temp->data = *person;
		temp->next = NULL;
	}
	else
	{
		temp->next = stackItem;
		stackItem = temp;
		temp->data = *person;
	}
}
void PopStack(Stack*& stackItem)
{
	Stack *temp = stackItem;
	if (stackItem == NULL) 
	{
		cout << endl << "Стэк и так пуст! Удалять нечего, товарищ!" << endl;
	}
	else
	{
		temp = stackItem;
		if (stackItem->next != NULL) 
		{
			stackItem = stackItem->next;
		}
		delete temp;
	}
}

void GetTopStack(Stack *stackItem)
{
	if (stackItem == NULL)
	{
		cout << endl << "Стэк и так пуст! Нам нечего показывать, товарищ!" << endl;
	}
	else
	{//TODO: Дублируется ниже!
		cout << endl << ". Имя: " << stackItem->data.Name << endl;
		cout << ". Фамилия: " << stackItem->data.Surname << endl;
		switch (stackItem->data.Sex)
		{
			case 0:
				cout << "Пол:" << "Женщина" << endl << endl;
				break;
			case 1:
				cout << "Пол:" << "Мужчина" << endl << endl;
				break;
			default: break;
		}
	}
}

void GetFullStack(Stack *stackItem)
{
	Stack *temp = stackItem;
	if (stackItem == NULL)
	{
		cout << endl << "Стэк пуст! Нам нечего показывать, товарищ!" << endl;
	}
	else
	{
		int i = 0;
		while (temp!= NULL)
		{
			cout << endl << i << ". Имя: " << temp->data.Name << endl;
			cout<< ". Фамилия: " << temp->data.Surname << endl;
			switch (temp->data.Sex)
			{
				case 0:
					cout << "Пол:" << "Женщина" << endl << endl;
					break;
				case 1:
					cout << "Пол:" << "Мужчина" << endl << endl;
					break;
				default: break;
			}
			temp = temp->next;
			i++;
		}
	}
}

int GetSizeStack(Stack *stackItem)
{
	Stack *temp = stackItem;
	if (temp == NULL)
	{
		cout << endl << "Стэк пуст! Нам нечего показывать, товарищ!" << endl;
		return 0;
	}
	else
	{
		int itemsCounter = 1;
		while (temp->next != NULL)
		{
			itemsCounter++;
			temp = temp->next;
			
		}
		return itemsCounter;
	}
}
	
bool IsEmptyStack(Stack *stackItem)
{
	if (stackItem == NULL)
	{
		cout << endl << "Стэк пуст!" << endl;
		return false;
	}
	else
	{
		cout << endl << "В стеке что-то есть!" << endl;
		return true;
	}
}
