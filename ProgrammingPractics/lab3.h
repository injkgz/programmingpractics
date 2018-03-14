#pragma once
#include "CheckCin.h"
#include "MenuEnum.h"
#include "SexEnum.h"
# include "structPerson.h"
namespace Lab3
{
	//TODO: Все сущности (структуры, перечисления, классы) должны быть в отдельных файлах!
	//сделано
	bool FindSymbol(char* string1, char* string2, int i, int& pointer, int whichsymbol);
	void CopyStringToString(char* string, char* stringResult, int& k);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	int GetLength(char* string);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char * TransformToUppercase(char * string);
	char * TransformToLowercase(char * string);
	char* ReplaceTabsOnSpaces(char* string, int countSpace);
	char* ReplaceSpacesOnTabs(char* string, int countSpace);
	Person ReadPerson();
	void PrintPerson(Person& person);
	void ThirdChooseMenu();
}

