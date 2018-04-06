#include "CheckCin.h"
#include "StackPerson.h"

void PushStack(Stack*& stackItem, Person *person)
{
	Stack *temp = new Stack;
	if (stackItem == nullptr)
	{
		stackItem = temp;
		temp->Data = *person;
		temp->Next = nullptr;
	}
	else
	{
		temp->Next = stackItem;
		stackItem = temp;
		temp->Data = *person;
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
		stackItem = stackItem->Next;
		delete temp;
	}
}

void PrintPerson (Stack* stackItem)
{
	cout << endl << "Имя:\t\t" << stackItem->Data.Name << endl;
	cout << "Фамилия:\t" << stackItem->Data.Surname << endl;
	switch (stackItem->Data.Sex)
	{
		case Female:
			cout << "Пол:\t\t" << "Женщина" << endl << endl;
			break;
		case Male:
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
	{
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
			temp = temp->Next;
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
		while (temp->Next != nullptr)
		{
			itemsCounter++;
			temp = temp->Next;
			
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
