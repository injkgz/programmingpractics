#pragma once
#include "CheckCin.h"

struct List
{
	//TODO: Некорректное именование публичных полей структуры
	Node* head = nullptr;
	Node* tail = nullptr;
	int CountItems = 0;
};