﻿#include "lab3.h"
#include "CheckCin.h"
#pragma warning(disable : 4996)

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

	//Функция объединения двух массивов char
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

	//Функция, возвращающая из string CharCount символов с позиции startIndex
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
			path = nullptr;
			name = nullptr;
			extension = nullptr;
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
	void PrintPerson(const Person& person)
	{
		cout << "Фамилия: " << person.Surname << endl;
		cout << "Имя: " << person.Name << endl;
		cout << "Пол: " << person.Sex << endl;
	}

	char* ReadChar()
	{
		cout << endl << "Введите строку: " << endl;
		string t;
		cin >> t;
		char* str_ptr = new char[t.length() + 1]();
		strcpy(str_ptr, t.c_str());
		return str_ptr;
	}
	
	bool ChooseCin()
	{
		bool key = true;
		int choosedFunction;

		while (key)
		{
			system("cls");
			cout << endl
				<< "Введите:" << endl
				<< "0 - для ручного ввода" << endl
				<< "1 - для автоматического заполнения" << endl
				<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
				<< endl;
			choosedFunction = CheckCin(true);
			cout << endl;
			switch (choosedFunction)
			{
				case 0:
				{
					return true;
					break;
				}
				case 1:
				{
					return false;
					break;
				}
				default:
				{
					break;
				}
			}
			if (choosedFunction == 0 && choosedFunction == 1)
			{
				GetPause();
			}

		}
	}

	//Меню выбора заданий
	void ThirdChooseMenu()
	{
		bool key = true;
		int choosedFunction;

		while (key)
		{
			//TODO: Значительно упростили себе задачу, убрав из расчёта пользовательский ввод и сделав
			//TODO: весь ввод автоматическим.
			//?
			//TODO: Сделайте возможность пользовательского ввода данных.
			//сделано
			system("cls");
			cout << endl
				<< "Введите 0 для выхода в меню выбора лабораторной или выберите задание от 1 до 10"
				<< endl
				<< "1. GetLength()" << endl
				<< "2. Concatenate()" << endl
				<< "3. GetSubstring()" << endl
				<< "4. FindSubstring()" << endl
				<< "5. Uppercase()" << endl
				<< "6. Lowercase()" << endl
				<< "7. SplitFilename()" << endl
				<< "8. ReplaceTabsOnSpaces()" << endl
				<< "9. ReplaceSpacesOnTabs()" << endl
				<< "10. Work with struct Person" << endl
				<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
				<< endl;
			choosedFunction = CheckCin(true);
			cout << endl;
			switch (choosedFunction)
			{
				case 0:
				{
					key = false;
					cout << endl << "Выход из программы." << endl;
					system("pause");
					break;
				}
				case GetLengthItem:
				{
					char* string;

					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"123456789";
					}
					cout << GetLength(string) << endl;
					break;
				}
				case ConcatenateItem:
				{
					char* mergedString1;
					char* massMerge1;
					char* massMerge2;

					if (ChooseCin())
					{
						massMerge1 = ReadChar();
						massMerge2 = ReadChar();
					}
					else
					{
						massMerge1 = (char*)"abc123";
						massMerge2 = (char*)"123abc";
					}

					mergedString1 = Concatenate(massMerge1, massMerge2);

					for (int i = 0; i < GetLength(mergedString1); i++)
					{
						cout << mergedString1[i] << " ";
					}

					cout << endl;

					break;
				}
				case GetSubstringItem:
				{
					char* newSubString;
					char* string;
					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"123abc";
					}
					newSubString = GetSubstring(string, 3, 3);
					for (int i = 0; i < GetLength(newSubString); i++)
					{
						cout << newSubString[i] << " ";
					}

					cout << endl;
					break;
				}
				case FindSubstringItem:
				{
					char *string ;
					char* substring;

					if (ChooseCin())
					{
						string = ReadChar();
						substring = ReadChar();
					}
					else
					{
						string = (char*)"Lorem ipsum aset amet";
						substring = (char*)" ipsum a";
					}

					cout << FindSubstring(string, substring);
					break;
				}
				case TransformToUppercaseItem:
				{
					char *string;
					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";
					}

					cout << TransformToUppercase(string) << endl;
					break;
				}
				case TransformToLowercaseItem:
				{
					char *string;
					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";
					}
					cout << TransformToLowercase(string) << endl;
					break;
				}
				case SplitFilenameItem:
				{
					char* string;
					char extension[50];
					char path[50];
					char name[50];

					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"d:\\folder\\subfolder\\file.pdf";
					}

					SplitFilename(string, path, name, extension);
					SplitFilename(string, path, name, extension);
					string = (char*)"d:\\fol der\\subf older\\file.pdf";
					SplitFilename(string, path, name, extension);
					string = (char*)"d:\\fol der\\subf older\\file.pdf.вые.cmd";
					SplitFilename(string, path, name, extension);
					break; 
				}
				case ReplaceTabsOnSpacesItem:
				{
					char* string;

					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"Cake\tis\ta lie!";
					}

					cout << ReplaceTabsOnSpaces(string) << endl;
					cout << ReplaceTabsOnSpaces(string) << endl;
					string = (char*)"Cake\t\tis a lie!";
					cout << ReplaceTabsOnSpaces(string) << endl;
					string = (char*)"\tCake is \tlie!";
					cout << ReplaceTabsOnSpaces(string) << endl;
					delete(string);
					break;
				}
				case ReplaceSpacesOnTabsItem:
				{
					char* string;

					if (ChooseCin())
					{
						string = ReadChar();
					}
					else
					{
						string = (char*)"Cake::::is::a:lie!\0";
					}

					cout << ReplaceSpacesOnTabs(string) << endl;
					cout << ReplaceSpacesOnTabs(string) << endl;
					string = (char*)"Cake::::is::::a:lie!";
					cout << ReplaceSpacesOnTabs(string) << endl;
					string = (char*)"Cake:is:a:::::::lie!";
					cout << ReplaceSpacesOnTabs(string) << endl;
					string = (char*)"Cake:is::a:lie!";
					cout << ReplaceSpacesOnTabs(string) << endl;
					delete(string);
					break;
				}
				case PersonItem:
				{
					Person person1 = ReadPerson();

					PrintPerson(person1);
					break;
				}
				default: 
				{ 
					break; 
				}
			}
			if (choosedFunction >= 1)
			{
				GetPause();
			}
		}
	}
}