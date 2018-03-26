#pragma once

Person* MakeRandomPerson();
void StructChooseMenu();
void ListMenu();
void StackMenu();

namespace lab4
{//TODO: В отдельный файл
	enum MenuList
	{
		Add = 1,
		ShowList,
		GetByIndex,
		RemoveByIndex,
		InsertByIndex,
		ClearList

	};
	//TODO: В отдельный файл
	enum MenuStack
	{
		PushStack = 1,
		PopStack,
		GetTopStack,
		GetFullStack,
		GetSizeStack,
		IsEmptyStack
	};
}