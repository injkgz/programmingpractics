#pragma once

#include "CheckCin.h"
#include "Person.h"
#include "Node.h"
#include "List.h"
#include "MenuList.h"

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
int GetCorrectIndex(List* list);



