#include "CheckCin.h"

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
			case 5:
				UILab5();
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

