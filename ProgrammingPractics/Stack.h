#pragma once
#include "CheckCin.h"

struct Stack
{//TODO: Именование публичных полей не по RSDN
	Person data;
	Stack *next = nullptr;
};