#include "lab5UI.h"
#include "PersonList.h"
#include "Adult.h"
#include "Child.h"
#include "FamilyTools.h"

void UILab5()
{
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	lab5::PersonList newList;
	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите функцию: "
			<< endl
			<< "1. Add " << endl
			<< "2. Find" << endl
			<< "3. RemoveAt" << endl
			<< "4. Clear" << endl
			<< "5. GetCount" << endl
			<< "6. ShowList" << endl
			<< "7. CreateFamily" << endl
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
				newList.Add(lab5::FamilyTools::GetRandomAdult(Male));
				newList.Add(lab5::FamilyTools::GetRandomAdult(Female));
				newList.Add(lab5::FamilyTools::GetRandomChild());
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
				newList.ShowList();
				cout << endl << "Введите индекс удаляемой персоны: ";
				int index;
				newList.GetCorrectIndex(index);
				newList.RemoveAt(index);
				break;
			}
			case 4:
			{
				newList.ShowList();
				cout << endl << "Очищаем список!" << endl;
				newList.Clear();
				break;
			}
			case 5:
			{
				cout << endl << "Количество элементов в списке = " << newList.GetCount();
				newList.ShowList();
				break;
			}
			case 6:
			{
				newList.ShowList();
				break;
			}
			case 7:
			{
				newList.ShowList();
				cout << endl << endl;
				lab5::PersonList* newListPointer = &newList;
				lab5::FamilyTools::CreateFamily(newListPointer);
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