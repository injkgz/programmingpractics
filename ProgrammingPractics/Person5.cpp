#include "CheckCin.h"
#include "Person5.h"
#include "Sex.h"

namespace lab5
{
	//TODO: Длины строк может не хватить
	//Увеличил до 40!
	//TODO: Нельзя поменять длинну строк из одного места!
	//Нужна функция увеличения массива? По-моему будет нелогично!
	//Пользователь сможет тратить бесценную
	//оперативную память просто так!
	//TODO: Аргументы метода не по RSDN!
	//исправил!
	Person::Person(char Name[40], char Surname[40],
		unsigned int Age, enum Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	void Person::SetName(char name[40])
	{
		strcpy_s(Name, name);
	}
	void Person::SetSurname(char surname[40])
	{
		strcpy_s(Surname, surname);
	}
	void Person::SetAge(unsigned int age)
	{//TODO: 0 тоже может быть? А отрицательный возраст
		//возраст может быть 0, так как
		//предметная область не определена,
		//соответственно я могу новорожденного добавить
		//исправил на unsigned int
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

	//TODO: Нижние перегрузки - во-первых дублируются, во-вторых скорее всего работают некорректно
	//TODO: А чтобы понять, насколько правильно они отрабатывают - распишите как работает strcmp
	//strcmp: посимвольно сравнивает две строки, как только попадают неодинаковые символы
	//сравнивается их код и чей окажется больше, та строка вернётся
	//в случае !strcmp мы приходим к результату, когда две строки идентичны
	//во-втором методе забыл убрать "!" перед strcmp
	//вроде можно считать, что исправил
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