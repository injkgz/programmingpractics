
#include "CheckCin.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "MenuLab4.h"
#include "UITemplateList.h"

int main()
{
	setlocale(LC_ALL, "russian");
	bool key = true;
	int choosedLab;

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода или выберите номер лабораторной работы!"
			<< endl
			<< "1 - Лабораторная работа #1"
			<< endl
			<< "2 - Лабораторная работа #2"
			<< endl
			<< "3 - Лабораторная работа #3"
			<< endl
			<< "4 - Лабораторная работа #4"
			<< endl
			<< "5 - Лабораторная работа #5-7"
			<< endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		choosedLab = CheckCin(true);
		switch (choosedLab)
		{
			case 0:
				key = false;
				cout << endl << "Выход из программы." << endl;
				system("pause");
				break;
			case 1: 
				FirstChooseMenu(); 
				break;
			case 2: 
				Laboratornaya2::SecondChooseMenu(); 
				break;
			case 3:
				Lab3::ThirdChooseMenu();
				break;
			case 4:
				StructChooseMenu();
				break;
			case 5://TODO: Где 6 лаба?
				//7-ая лаба отражает всё, что происходит в 5-6
				UITemplateList();
				break;
			default: break;
		}
		if (choosedLab > 1)
		{
			GetPause();
		}
	}
	return 0;
}

