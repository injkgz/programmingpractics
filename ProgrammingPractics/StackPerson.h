#pragma once
#include "CheckCin.h"

//TODO: В отдельынй файл!
//сделано!

void PushStack(Stack*& stackItem, Person *person);
void PopStack(Stack*& stackItem);
void GetTopStack(Stack *stackItem);
void GetFullStack(Stack *stackItem);
int GetSizeStack(Stack *stackItem);
bool IsEmptyStack(Stack *stackItem); 
void PrintPerson(Stack* stackItem);