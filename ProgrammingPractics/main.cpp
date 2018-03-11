#include "CheckCin.h"

int main()
{
	setlocale(LC_ALL, "russian");
	bool key = true;
	int n;

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 0 для выхода или выберите номер лабораторной работы!"
			<< endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		n = CheckCin(true);
		switch (n)
		{
			//TODO: Поправьте форматирование по RSDN.
			//сделано
		case 0:
			key = false;
			cout << endl << "Выход из программы." << endl;
			system("pause");
			break;
		case 1: FirstChooseMenu(); break;
		case 2: Laboratornaya2::SecondChooseMenu(); break;
		default: break;
		}
		if (n > 1)//TODO: Для if-else всегда надо расставлять скобки! //Сделано!
		{
			GetPause();
		}
	}
	return 0;
}

