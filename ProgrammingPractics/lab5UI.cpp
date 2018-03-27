#include "lab5UI.h"

void UILab5()
{
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	lab5::PersonList list1;
	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. Find" << endl
			<< "3. IndexOf " << endl
			<< "4. Remove" << endl
			<< "5. RemoveAt" << endl
			<< "6. Clear" << endl
			<< "7. GetCount" << endl
			<< "8. Read" << endl
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
			case 1:
			{
				list1.Add(lab5::PersonList::MakeRandomPerson());
				break;
			}
			case 2:
			{
				cout << endl << "Введите индекс персоны: ";
				int index;
				list1.GetCorrectIndex(index);
				list1.Find(index);
				break;
			}
			case 3:
			{
				cout << endl << "Введите все поля персоны обязательно на английском!: " << endl;
				lab5::Person* searchedPerson = list1.Read();
				list1.IndexOf(searchedPerson);
				break;
			}
			case 4:
			{
				cout << endl << "Введите все поля удаляемой персоны: ";
				lab5::Person* searchedPerson = list1.Read();
				list1.Remove(searchedPerson);
				break;
			}
			case 5:
			{
				cout << endl << "Введите индекс удаляемой персоны: ";
				int index;
				list1.GetCorrectIndex(index);
				list1.RemoveAt(index);
				break;
			}
			case 6:
			{
				cout << endl << "Очищаем список!" << endl;
				list1.Clear();
				break;
			}
			case 7:
			{
				cout << endl << "Количество элементов в списке = " << list1.GetCount();
				break;
			}
			case 8:
			{
				cout << "Введите все поля добавляемой персоны на английском!: " << endl;
				cout << endl << "Введите все поля удаляемой персоны: ";
				lab5::Person* searchedPerson = list1.Read();
				list1.Add(searchedPerson);
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