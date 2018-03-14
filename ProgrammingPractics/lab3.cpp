#include "lab3.h"

namespace Lab3
{
	int j = 0;

	//�������, ������������ ����� char
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

	//������� ����������� ���� char
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

	void CopyStringToString(char* string, char* stringResult, int& k)
	{
		for (int i = 0; i < GetLength(string); i++)
		{
			stringResult[k] = string[i];
			k++;
		}
	}

	//�������,  ������������ ���������, ��������� �� charCount �������� � ������������ � startIndex ������� � ������ string
	char* GetSubstring(char* string, int startIndex, int charCount)
	{
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

	//�������, ������������ ��� ������� � ������� �������
	char * Uppercase(char * string)
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

	//������� �������������� ���� �������� � ������ �������.
	char * Lowercase(char * string)
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

	//�������, ������� ��������� �������� ������ source �� ���� path, ��� name � ���������� ����� extension
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

			if (FindDot(source, extension, i, stopPointer))
			{
				if (FindSlash(source, name, i, stopPointer))
				{
					if (FindTwoDots(source, path,i, stopPointer))
					{
						cout << endl << "����: " << path << endl;
						cout << "���: " << name << endl;
						cout << "����������: " << extension << endl;
					}
					else
					{
						cout << "���: " << name << endl;
						cout << "����������: " << extension << endl;
					}
				}
				else
				{
					cout << endl << "���� � ����� ��������!";
				}
			}
			else
			{
				if (FindSlash(source, name, i, stopPointer))
				{
					if (FindTwoDots(source, path, i, stopPointer))
					{
						cout << endl << "����: " << path << endl;
						cout << "���: " << name << endl;
					}
					else
					{
						cout << "���: " << name << endl;
					}
				}
				else
				{
					cout << endl << "���� � ����� ��������!";
				}
			}
		}
	}

	//������� ������ � ��������� ��������� ������ ����� �����
	bool FindDot(char* string1, char* string2, int i, int& pointer)
	{
		while ((string1[i] != '.') && (i))
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
			string2[k]=string1[j];
			j++;
			k++;
		}
		string2[k] = '\0';
		return true;
	}

	bool FindSlash(char* string1, char* string2, int i, int& pointer)
	{
		while ((string1[i] != (char)(92)) && (i))
		{
			i--;
			if (i == 0)
			{
				return false;
			}
		}

		int j = i;
		int k = 0;

		while (j < pointer)
		{
			string2[k] = string1[j];
			j++;
			k++;
		}

		pointer = i;
		string2[k] = '\0';
		return true;

	}

	bool FindTwoDots(char* string1, char* string2, int i, int& pointer)
	{
		while (string1[i] != ':' && (i))
		{
			i--;
			if (i == 0)
			{
				return false;
			}
		}

		int j = i-1;
		int k = 0;

		while (j < pointer)
		{
			string2[k] = string1[j];
			j++;
			k++;
		}
		pointer = i;
		string2[k] = '\0';
		return true;

	}

	//������� ������ ��������� �� Space
	char* ReplaceTabsOnSpaces(char* string, int countSpace)
	{
		char* newString = new char[GetLength(string)];
		int endSymbol = 0;
		int currentSymbolNewString = 0;

		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == '\t')
			{
				for (int i = 0; i < countSpace; i++)
				{
					newString[currentSymbolNewString++] = ':';
					endSymbol++;
				}
			}
			else
			{
				newString[currentSymbolNewString] = string[i];
				currentSymbolNewString++;
				endSymbol++;
			}
		}
		newString[endSymbol] = '\0';
		return newString;
	}

	//������� ������ Space �� ���������
	char* ReplaceSpacesOnTabs(char* string, int countSpace)
	{
		char* newString = new char[GetLength(string)];
		int endSymbol = 0;
		int currentSymbolNewString = 0;

		for (int i = 0; i < GetLength(string); i++)
		{
			currentSymbolNewString = i;
			bool isTab = true;
			for (int i = 0; i < countSpace; i++)
			{
				if (string[currentSymbolNewString++] != ':')
				{
					isTab = false;
				}
			}

			if (isTab)
			{
				newString[i] = '\t';
			}
			else
			{
				newString[i] = string[i];
			}
			endSymbol++;
		}
		newString[endSymbol] = '\0';
		return newString;
	}

	//���� ��������
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
		} while (sex != 0 && sex != 1);

		switch (sex)
		{
		case Female:
			newPerson.Sex = Female;
			break;
		case Male:
			newPerson.Sex = Male;
			break;
		default:
			break;
		}
		return newPerson;
	}

	//����� ��������
	void PrintPerson(Person& person)
	{
		cout << "Surname: " << person.Surname << endl;
		cout << "Name: " << person.Name << endl;
		cout << "Sex: " << person.Sex << endl;
	}

	//���� ������ �������
	void ThirdChooseMenu()
	{
		bool key = true;
		int n;

		while (key)
		{
			system("cls");
			cout << endl
				<< "������� 0 ��� ������ � ���� ������ ������������ ��� �������� ������� �� 1 �� 10"
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
				<< "��������� ����� ����������� ���� �� ��� ���, ���� �� �� ������ ���������� ��������!"
				<< endl;
			n = CheckCin(true);
			cout << endl;
			switch (n)
			{
				case 0:
					key = false;
					cout << endl << "����� �� ���������." << endl;
					system("pause");
					break;
				case GetLengthEnum:
					{
					char* string10 = (char*)"123456789";

					cout << GetLength(string10) << endl;
					break;
					}
				case ConcatenateEnum:
					{
					char* massMerge1 = (char*)"abc123";
					char* massMerge2 = (char*)"123abc";
					char* mergedString1 = Concatenate(massMerge1, massMerge2);

					for (int i = 0; i < GetLength(mergedString1); i++)
					{
						cout << mergedString1[i] << " ";
					}
					cout << endl;
					break;
					}
				case GetSubstringEnum:
					{
					char* string2 = (char*)"123abc\0";
					char* newSubString = GetSubstring(string2, 3, 3);

					for (int i = 0; i < GetLength(newSubString); i++)
					{
						cout << newSubString[i] << " ";
					}
					cout << endl;
					break;
					}
				case FindSubstringEnum:
					{
					char* string3 = (char*)"Lorem ipsum aset amet ";
					char* substring10 = (char*)" ipsum a";

					cout << FindSubstring(string3, substring10);
					break;
					}
				case UppercaseEnum:
					{
					char* string4 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";

					cout << Uppercase(string4) << endl;
					break;
					}
				case LowercaseEnum:
					{
					char* string5 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";

					cout << Lowercase(string5) << endl;
					break;
					}
				case SplitFilenameEnum:
					{
					char* string6 = (char*)"d:\\folder\\subfolder\\file.exe";
					char extension[50];
					char path[50];
					char name[50];

					SplitFilename(string6, path, name, extension);
					break; 
					}
				case ReplaceTabsOnSpacesEnum:
					{
					char* string7 = (char*)"Cake\tis\ta lie!";

					cout << ReplaceTabsOnSpaces(string7,4) << endl;
					break;
					}
				case ReplaceSpacesOnTabsEnum:
					{
					char* string8 = (char*)"Cake::::is::a:lie!";

					cout << ReplaceSpacesOnTabs(string8,4) << endl;
					break;
					}
				case PersonEnum:
					{
					Person person1 = ReadPerson();

					PrintPerson(person1);
					break;
					}
				default: break;
			}
			if (n >= 1)
			{
				GetPause();
			}
		}
	}
}








