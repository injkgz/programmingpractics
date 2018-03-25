#include "lab3.h"

//Меню выбора заданий
namespace Lab3
{
	void ThirdChooseMenu()
	{
		bool key = true;
		int choosedFunction;

		while (key)
		{
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
					char* string10 = (char*)"123456789";
					
					cout << GetLength(string10) << endl;
					break;
				}
				case ConcatenateItem:
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
				case GetSubstringItem:
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
				case FindSubstringItem:
				{
					char* string3 = (char*)"Lorem ipsum aset amet ";
					char* substring10 = (char*)" ipsum a";

					cout << FindSubstring(string3, substring10);
					break;
				}
				case TransformToUppercaseItem:
				{
					char* string4 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";

					cout << TransformToUppercase(string4) << endl;
					break;
				}
				case TransformToLowercaseItem:
				{
					char* string5 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";

					cout << TransformToLowercase(string5) << endl;
					break;
				}
				case SplitFilenameItem:
				{
					char* string6 = (char*)"d:\\folder\\subfolder\\file.pdf";
					char extension[50];
					char path[50];
					char name[50];
	
					SplitFilename(string6, path, name, extension);
					break;
				}
				case ReplaceTabsOnSpacesItem:
				{
					char* string7 = (char*)"Cake\tis\ta lie!";
	
					cout << ReplaceTabsOnSpaces(string7) << endl;
					break;
				}
				case ReplaceSpacesOnTabsItem:
				{
					char* string8 = (char*)"Cake::::is::::a:lie!";
	
					cout << ReplaceSpacesOnTabs(string8) << endl;
					break;
				}
				case Node:
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