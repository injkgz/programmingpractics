#pragma once

#include "Person.h"
#include "CheckCin.h"


struct Stack
{
	Person data;
	Stack *next = NULL;
};

void PushStack(Stack*& stackItem, Person *person);
void PopStack(Stack*& stackItem );
void GetTopStack(Stack *stackItem);
void GetFullStack(Stack *stackItem);
int GetSizeStack(Stack *stackItem);
bool IsEmptyStack(Stack *stackItem);