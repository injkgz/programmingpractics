#pragma once
#include "Person.h"

struct Node
{
	Person Item;
	Node* next = NULL;
	Node* prev = NULL;	
};