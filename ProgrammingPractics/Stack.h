#pragma once
#include "CheckCin.h"
#include "Person.h"

struct Stack
{
	Person Data;
	Stack *Next = nullptr;
};