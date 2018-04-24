#include "UITemplateList.h"
#include "TemplateList.h"
#include "Adult.h"
#include "Child.h"
#include "FamilyTools.h"
#include "UIData.h"

using namespace lab5;

void UITemplateList()
{
	bool key = true;
	int choosedFunction;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	lab5::TemplateList<lab5::Person*> newList;
	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода в меню выбора структуры или выберите тип данных: "
			<< endl
			<< "1. Double " << endl
			<< "2. Person" << endl
			<< "3. List<double>" << endl
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
				TemplateList<double>* list = new TemplateList<double>();
				DoubleListMenu(list, 0);
				delete list;
				break;
			}
			case 2:
			{
				UIPerson();
				break;
			}
			case 3:
			{
				UIList();
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