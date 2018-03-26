#pragma once

#include "CheckCin.h"
#include "Node.h"
#include "MenuLab4.h"
#include "Person.h"
//TODO: В отдельный файл.
struct List
{
	Node* head = NULL;
	Node* tail = NULL;
	int CountItems = 0;
};

void Add(List* list, Person * person);
void ShowListItem(Node& item, int index);
void ShowList(List* list);
Node* GetByIndex(List* list, int index);
void RemoveByIndex(List* list, int index);
void InsertByIndex(List* list, Person *person, int index);
void ClearList(List* list);
Person* MakeRandomPerson();
void StructChooseMenu();
void ListMenu();


