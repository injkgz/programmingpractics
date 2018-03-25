#include "lab3.h"

namespace Lab3
{
	//Функция, возвращающая длину char
	int GetLength(char* string)
	{
		if (&string == nullptr)
		{
			return -1;
		}

		int length = 0;

		while (string[length] != '\0')
		{
			length++;
		}
		return length;
	}

	//Функция объединения двух char
	char* Concatenate(char * string1, char * string2)
	{
		char* mergedString = new char [200];
		int j = 0;
		int& jReference = j;

		CopyStringToString(string1, mergedString, jReference);
		CopyStringToString(string2, mergedString, jReference);
		mergedString[jReference] = '\0';
		return mergedString;
	}

	//Функция копирования одной строки в другую
	void CopyStringToString(char* string, char* stringResult, int& k)
	{
		for (int i = 0; i < GetLength(string); i++)
		{
			stringResult[k] = string[i];
			k++;
		}
	}


	//Функция,  возвращающая подстроку, состоящую из charCount символов и начинающуюся с startIndex позиции в строке string
	char* GetSubstring(char* string, int startIndex, int charCount)
	{
		int j = 0;
		char* newString = new char[200];

		if (startIndex < 0 || startIndex + charCount > GetLength(string))
		{
			return nullptr;
		}
		else
		{
			charCount += startIndex;
			for (startIndex; startIndex < charCount; startIndex++)
			{
				newString[j] = string[startIndex];
				j++;
			}
			newString[++j] = '\0';
			return newString;
		}
	}

	//Функция поиска подстроки в строке
	int FindSubstring(char* string, char* substring)
	{
		if (GetLength(string) < GetLength(substring))
		{
			return -1;
		}

		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == substring[0])
			{
				bool isSimilar = true;
				int pointer = ++i;

				if (pointer > GetLength(string))
				{
					return -1;
				}

				for (int subPointer = 1; subPointer < GetLength(substring); subPointer++)
				{
					if (string[pointer] != substring[subPointer])
					{
						isSimilar = false;
					}
					pointer++;
				}

				if (isSimilar)
				{
					return --i;
				}
			}
		}
		return -1;
	}

	//Функция, превращающая все символы в верхний регистр
	char * TransformToUppercase(char * string)
	{
		if (&string != nullptr)
		{
			char* newString = new char[GetLength(string)];

			for (int i = 0; i < GetLength(string); i++)
			{
				newString[i] = string[i];
				newString[i + 1] = '\0';
			}

			for (int i = 0; i < GetLength(newString); i++)
			{
				if (newString[i] >= 'a' && newString[i] <= 'z')
				{
					newString[i] -= 32;
				}
			}
			return newString;
		}
		else
		{
			return nullptr;
		}
	}

	//Функция преобразования всех символов в нижний регистр.
	char * TransformToLowercase(char * string)
	{
		if (&string != nullptr)
		{
			char* newString = new char[GetLength(string)];

			for (int i = 0; i < GetLength(string); i++)
			{
				newString[i] = string[i];
				newString[i + 1] = '\0';
			}

			for (int i = 0; i < GetLength(newString); i++)
			{
				if (newString[i] >= 'A' && newString[i] <= 'Z')
				{
					newString[i] += 32;
				}
			}
			return newString;
		}
		else
		{
			return nullptr;
		}
	}

	//Функция, которая разделяет исходную строку source на путь path, имя name и расширение файла extension
	void SplitFilename(char* source, char* path, char* name, char* extension)
	{
		int stopPointer = 1000000;
		if (GetLength(source) <= 1)
		{
			path = NULL;
			name = NULL;
			extension = NULL;
		}
		else
		{
			int i = GetLength(source) - 1;

			if (FindSymbol(source, extension, i, stopPointer, 0))
			{
				if (FindSymbol(source, name, i, stopPointer,1 ))
				{
					if (FindSymbol(source, path,i, stopPointer,2))
					{
						cout << endl << "Путь: " << path << endl;
						cout << "Имя: " << name << endl;
						cout << "Расширение: " << extension << endl;
					}
					else
					{
						cout << "Имя: " << name << endl;
						cout << "Расширение: " << extension << endl;
					}
				}
				else
				{
					cout << endl << "Путь к файлу неверный!";
				}
			}
			else
			{
				if (FindSymbol(source, name, i, stopPointer,1))
				{
					if (FindSymbol(source, path, i, stopPointer,2))
					{
						cout << endl << "Путь: " << path << endl;
						cout << "Имя: " << name << endl;
					}
					else
					{
						cout << "Имя: " << name << endl;
					}
				}
				else
				{
					cout << endl << "Путь к файлу неверный!";
				}
			}
		}
	}

	//Функция поиска символа в строке и возвращения части строки после символа.
	//whichsymbol переменная отражающая, какой символ мы ищем в строке. 
	// "." - 0, "\\" - 1, ":" - 2.
	bool FindSymbol(char* string1, char* string2, int i, int& pointer, int whichsymbol)
	{
		char* symbols = (char*)".\\:";

		while ((string1[i] != symbols[whichsymbol])&& (i))
		{
			i--;
			if (i == 0)
			{
				return false;
			}
		}

		pointer = i;
		int j = i;
		int k = 0;

		while (string1[j] != '\0')
		{
			string2[k] = string1[j];
			j++;
			k++;
		}

		string2[k] = '\0';
		return true;
	}

	//Функция замены табуляции на Space
	char* ReplaceTabsOnSpaces(char* string)
	{
		char* newString = new char[GetLength(string)];
		int j = 0;
		//нумерация элементов начинается с 0, так выходит, что 4-ый элемент имеет позицию счётчика j=3
		//а пятый соответственно 4, для исправления данной проблемы вводится дополнительная переменная tempj
		int tempj = 0;

		for (int i = 0; i < GetLength(string); j++)
		{
			if (string[i] == '\t')
			{
				tempj = j + 1;
				if (tempj % 4 != 0)
				{
					newString[j] = ':';
				}
				else
				{
					newString[j] = ':';
					i++;
				}
			}
			else
			{
				newString[j] = string[i];
				i++;
			}
		}
		newString[j++] = '\0';
		return newString;
	}

	//Функция замены Space на табуляцию
	char* ReplaceSpacesOnTabs(char* string)
	{
		char* newString = new char[GetLength(string)];
		int j = 0;
		int twoDotsPointer = 0;
		bool isTabulation = false;

		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == ':')
			{
				twoDotsPointer = i;

				while (string[twoDotsPointer] == ':')
				{
					if ((twoDotsPointer + 1) % 4 == 0)
					{
						isTabulation = true;
						break;
					}
					twoDotsPointer++;
				}

				if (isTabulation)
				{
					i = twoDotsPointer;
					newString[j] = '\t';
					isTabulation = false;
					j++;
				}
				else
				{
					newString[j] = string[i];
					j++;
				}
			}
			else
			{
				newString[j] = string[i];
				j++;
			}
		}
		
		newString[j++] = '\0';
		return newString;
	}

	//Ввод личности
	Person ReadPerson()
	{
		Person newPerson;
		int sex;

		cout << "Insert Surname: ";
		cin >> newPerson.Surname;
		cout << endl << "Insert Name: ";
		cin >> newPerson.Name;
		cout << endl << "Insert Sex: ";

		do
		{
			sex = CheckCin(true);
		} 
		while (sex != 0 && sex != 1);

		switch (sex)
		{
			case Female: newPerson.Sex = Female; break;
			case Male: newPerson.Sex = Male; break;
			default: break;
		}
		return newPerson;
	}

	//Вывод личности
	void PrintPerson(Person& person)
	{
		cout << "Фамилия: " << person.Surname << endl;
		cout << "Имя: " << person.Name << endl;
		cout << "Пол: " << person.Sex << endl;
	}

	
}