#include "CheckCin.h"

void PushStack(Stack*& stackItem, Person *person)
{//TODO: В предыдущей лабе был nulptr, тут NULL - что лучше использовать?
	//nullptr, объяснил в лабе#3
	Stack *temp = new Stack;
	if (stackItem == nullptr)
	{
		stackItem = temp;
		temp->data = *person;
		temp->next = nullptr;
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
	if (stackItem == nullptr) 
	{
		cout << endl << "Стэк и так пуст! Удалять нечего, товарищ!" << endl;
	}
	else
	{
		temp = stackItem;
		stackItem = stackItem->next;
		delete temp;
	}
}
void PrintPerson (Stack* stackItem)
{
	cout << endl << "Имя:\t\t" << stackItem->data.Name << endl;
	cout << "Фамилия:\t" << stackItem->data.Surname << endl;
	switch (stackItem->data.Sex)
	{
		case 0:
			cout << "Пол:\t\t" << "Женщина" << endl << endl;
			break;
		case 1:
			cout << "Пол:\t\t" << "Мужчина" << endl << endl;
			break;
		default: break;
	}
}

void GetTopStack(Stack *stackItem)
{
	if (stackItem == nullptr)
	{
		cout << endl << "Стэк и так пуст! Нам нечего показывать, товарищ!" << endl;
	}
	else
	{//TODO: Дублируется ниже!
		//сделано!
		PrintPerson(stackItem);
	}
}

void GetFullStack(Stack *stackItem)
{
	Stack *temp = stackItem;
	if (stackItem == nullptr)
	{
		cout << endl << "Стэк пуст! Нам нечего показывать, товарищ!" << endl;
	}
	else
	{
		int i = 0;
		while (temp!= nullptr)
		{
			cout << endl << i << ". ";
			PrintPerson(temp);
			temp = temp->next;
			i++;
		}
	}
}

int GetSizeStack(Stack *stackItem)
{
	Stack *temp = stackItem;
	if (temp == nullptr)
	{
		cout << endl << "Стэк пуст! Нам нечего показывать, товарищ!" << endl;
		return 0;
	}
	else
	{
		int itemsCounter = 1;
		while (temp->next != nullptr)
		{
			itemsCounter++;
			temp = temp->next;
			
		}
		return itemsCounter;
	}
}
	
bool IsEmptyStack(Stack *stackItem)
{
	if (stackItem == nullptr)
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
