#include "CheckCin.h"
#include "Person5.h"
#include "Sex.h"

namespace lab5
{
	//TODO: Длины строк может не хватить
	//TODO: Нельзя поменять длинну строк из одного места!
	//Нужна функция увеличения массива? !!!НЕТ, Я НЕ ОБ ЭТОМ ПРОСИЛ!!! По-моему будет нелогично!
	//Пользователь сможет тратить бесценную
	//оперативную память просто так!
	//TODO: Пользователь не сможет ввести своё бесценное имя/фамилию, которое длиннее 40 символов - вот проблема
	//TODO: И т.к. вы запускаете приложение не на микроконтроллере, то считать память пока не надо.
	//сменил размерность на 250
	Person::Person(char Name[250], char Surname[250],
		unsigned int Age, enum Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	void Person::SetName(char name[250])
	{
		strcpy_s(Name, name);
	}
	void Person::SetSurname(char surname[250])
	{
		strcpy_s(Surname, surname);
	}
	void Person::SetAge(unsigned int age)
	{
		Age = age;
	}
	void Person::SetSex(enum Sex sex)
	{
		Sex = sex;
	}
	char* Person::GetName()
	{
		return Name;
	}
	char* Person::GetSurname()
	{
		return Surname;
	}
	int Person::GetAge()
	{
		return Age;
	}
	Sex Person::GetSex()
	{
		return Sex;
	}

	//TODO: Нижние перегрузки - дублируются
	//strcmp: посимвольно сравнивает две строки, как только попадают неодинаковые символы
	//сравнивается их код и чей окажется больше, та строка вернётся
	//в случае !strcmp мы приходим к результату, когда две строки идентичны
	//во-втором методе забыл убрать "!" перед strcmp
	//вроде можно считать, что исправил
	//TODO: Нет!
	bool Person::operator==(const Person& good)
	{
		return(!strcmp(Name, good.Name) &&
			!strcmp(Surname, good.Surname) &&
			Age == good.Age && Sex == good.Sex);
	}

	bool Person::operator!=(const Person& good)
	{
		return(strcmp(Name, good.Name) &&
			strcmp(Surname, good.Surname) &&
			Age != good.Age && Sex != good.Sex);
	}
}