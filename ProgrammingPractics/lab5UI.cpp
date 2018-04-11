#include "lab5UI.h"
#include "PersonList.h"
#include "PersonTools.h"
#include "Adult.h"
#include "Child.h"

void UILab5()
{
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//TODO: Некорректное именование!
	//исправил
	lab5::PersonList newList;
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
			<< "9. ShowList" << endl
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
				newList.Add(lab5::Adult::GetRandom());
				newList.Add(lab5::Child::GetRandom());
				newList.ShowList();
				break;
			}
			case 2:
			{
				cout << endl << "Введите индекс персоны: ";
				int index;
				newList.GetCorrectIndex(index);
				newList.Find(index);
				break;
			}
			case 3:
			{
				cout << endl << "Введите все поля персоны обязательно на английском!: " << endl;
				lab5::Person* searchedPerson = newList.Read();
				newList.IndexOf(searchedPerson);
				break;
			}
			case 4:
			{
				newList.ShowList();
				cout << endl << "Введите все поля удаляемой персоны: ";
				lab5::Person* searchedPerson = newList.Read();
				newList.Remove(searchedPerson);
				break;
			}
			case 5:
			{
				newList.ShowList();
				cout << endl << "Введите индекс удаляемой персоны: ";
				int index;
				newList.GetCorrectIndex(index);
				newList.RemoveAt(index);
				break;
			}
			case 6:
			{
				newList.ShowList();
				cout << endl << "Очищаем список!" << endl;
				newList.Clear();
				break;
			}
			case 7:
			{
				cout << endl << "Количество элементов в списке = " << newList.GetCount();
				newList.ShowList();
				break;
			}
			case 8:
			{
				cout << "Введите все поля добавляемой персоны на английском!: " << endl;
				lab5::Person* searchedPerson = newList.Read();
				newList.Add(searchedPerson);
				newList.ShowList();
			}
			case 9:
			{
				newList.ShowList();
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