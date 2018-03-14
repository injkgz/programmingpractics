#pragma once
#include "CheckCin.h"

namespace Lab3
{
	enum Sex
	{
		Female, Male
	};

	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Sex;
	};

	enum MenuEnum
	{
		GetLengthEnum = 1, ConcatenateEnum, GetSubstringEnum,
		FindSubstringEnum, UppercaseEnum, LowercaseEnum,
		SplitFilenameEnum, ReplaceTabsOnSpacesEnum, ReplaceSpacesOnTabsEnum, PersonEnum
	};


	void CopyStringToString(char* string, char* stringResult, int& k);
	bool FindDot(char* string1, char* string2, int i, int& pointer);
	bool FindTwoDots(char* string1, char* string2, int i, int& pointer);
	bool FindSlash(char* string1, char* string2, int i, int& pointer);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	int GetLength(char* string);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char * Uppercase(char * string);
	char * Lowercase(char * string);
	char* ReplaceTabsOnSpaces(char* string, int countSpace);
	char* ReplaceSpacesOnTabs(char* string, int countSpace);
	Person ReadPerson();
	void PrintPerson(Person& person);
	void ThirdChooseMenu();
}

