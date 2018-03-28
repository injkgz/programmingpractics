#pragma once
#include "CheckCin.h"

void PushStack(Stack*& stackItem, Person *person);
void PopStack(Stack*& stackItem);
void GetTopStack(Stack *stackItem);
void GetFullStack(Stack *stackItem);
int GetSizeStack(Stack *stackItem);
bool IsEmptyStack(Stack *stackItem); 
void PrintPerson(Stack* stackItem);