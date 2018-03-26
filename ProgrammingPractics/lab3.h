#pragma once
#include "CheckCin.h"
#include "Menu.h"
#include "Sex.h"
# include "Person.h"
namespace Lab3
{
	bool FindSymbol(char* string1, char* string2, int i, int& pointer, int whichsymbol);
	void CopyStringToString(char* string, char* stringResult, int& k);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	int GetLength(char* string);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char * TransformToUppercase(char * string);
	char * TransformToLowercase(char * string);
	char* ReplaceTabsOnSpaces(char* string);
	char* ReplaceSpacesOnTabs(char* string);
	Person ReadPerson();
	void PrintPerson(Person& person);
	void ThirdChooseMenu();
}

