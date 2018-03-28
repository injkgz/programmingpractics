#include "CheckCin.h"

namespace lab5
{
	//добавить человека в список
	void PersonList::Add(Person* person)
	{
		PersonListItem* temp = new PersonListItem(person);
		if (_head == nullptr)
		{
			_head = _tail = temp;
		}
		else
		{
			temp->Prev = _tail;
			_tail->Next = temp;
			_tail = temp;
		}
		_count++;
	}

	//найти человека по указанному индексу
	Person* PersonList::Find(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}

		PersonListItem* searchedItem = _head;

		for (int i = 0; i < index; i++)
		{
			if (searchedItem->Next != nullptr)
			{
				searchedItem = searchedItem->Next;
			}
		}
		//TODO: NULL!!!
		//сделано
		if (searchedItem->GetValue() != nullptr)
		{
			ShowPerson(searchedItem->GetValue());
		}
		return searchedItem->GetValue();
	}

	//вернуть индекс человека, если он есть в списке
	int PersonList::IndexOf(Person* person)
	{
		PersonListItem* searchedPerson = _head;
		int index = 0;
		while (searchedPerson != nullptr)
		{
			if (*searchedPerson->GetValue() == *person)
			{
				cout << "Индекс искомой личности = " << index;
				return index;
			}
			index++;
			searchedPerson = searchedPerson->Next;
		}
		cout << "Такой личности у нас нет!";
		return -1;
	}
	void PersonList::Removing(Person* person)
	{
		PersonListItem* deletedItem = _head;
		while (deletedItem != nullptr)
		{
			if (*deletedItem->GetValue() == *person)
			{//TODO: Дублируется в следущем методе
				//сделано
				if (deletedItem == _head)
				{
					_head = deletedItem->Next;
					if (deletedItem->Next == nullptr)
					{
						_head->Next = nullptr;
					}
					else
					{
						_head->Next = deletedItem->Next->Next;
					}
					_head->Prev = nullptr;
				}
				else if (deletedItem == _tail)
				{
					_tail = deletedItem->Prev;
					if (deletedItem->Prev == nullptr)
					{
						_tail->Prev = nullptr;
					}
					else
					{
						_tail->Prev = deletedItem->Prev->Prev;
					}
					_tail->Next = nullptr;
				}
				else
				{
					deletedItem->Prev->Next = deletedItem->Next;
					deletedItem->Next->Prev = deletedItem->Prev;
				}
				delete(deletedItem);
				_count--;
				return;
			}
			deletedItem = deletedItem->Next;
		}
		return;
	}
	//удалить человека из списка
	void PersonList::Remove(Person* person)
	{
		PersonListItem* deletedItem = _head;
		Removing(person);
	}

	//удалить человека из списка по индексу
	void PersonList::RemoveAt(int index)
	{
		Person *deletedPerson = Find(index);
		if (deletedPerson == nullptr)
		{
			return;
		}
		Removing(deletedPerson);
	}


	//очистить список
	void PersonList::Clear()
	{
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			PersonListItem* tempNext = temp->Next;
			delete temp->GetValue();
			delete temp;
			temp = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}

	//получить количество элементов
	int PersonList::GetCount()
	{
		return _count;
	}
	void GenerateRandomPerson(char tempName[250],char tempSurname[250], 
		const char Name[10], const char Surname[10], int& tempAge)
	{
		strcpy_s(tempName,250, Name);
		strcpy_s(tempSurname,250, Surname);
		tempAge = rand() % 50;
	}
	Person* PersonList::MakeRandomPerson()
	{
		const char* MaleName[] =
		{
			"Вэйдер", "Йода", "Оби-Ван", "Молл",
			"Энакин", "Сидиус", "Рено", "Ктун",
			"Баланар", "Зевс"
		};

		const char* MaleSurname[] =
		{
			"Дарт", "Кеноби", "Скайуокер", "Джексон",
			"Божественный", "Блудрейнов", "Молненосный",
			"Исанов", "Джобс"
		};

		const char* FemaleName[] =
		{
			"Ниа", "Кейтлин", "Федора",
			"Анна", "Маша", "Арабелла",
			"Шадия", "Лея", "Кая", "Герда"
		}; 

		const char* FemaleSurname[] =
		{
			"Мятежникова", "Старк", "Горе",
			"Хилькевич", "Горышкина", "Лесная",
			"Принцесса", "Ледяная", "Сколедарио",
			"Ланнистер"
		};

		
		//TODO: Почему в чисто рандомной персоне я должен вводить пол?
		//сделано
		char tempName[250];
		char tempSurname[250];
		int tempAge;
		Sex tempSex;
		int key = rand() % 1;

		switch (key)
		{
			case 0:
			{//TODO: Ниже 2 дубля
				//сделано
				GenerateRandomPerson(tempName, tempSurname, FemaleName[rand() % 9],
					FemaleSurname[rand() % 9], tempAge);
				tempSex = Female;
				break;
			}
			case 1:
			{
				GenerateRandomPerson(tempName, tempSurname, MaleName[rand() % 9],
					MaleSurname[rand() % 9], tempAge);
				tempSex = Male;
				break;
			}
			default:
			{
				break;
			}
		}
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}

	Person* PersonList::Read()
	{
		bool key = true;
		char tempName[20];
		char tempSurname[20];
		unsigned int tempAge;
		Sex tempSex;

		while (key)
		{
			cout << endl << "Введите фамилию: ";
			cin >> tempSurname;
			key = !CheckValidName(tempSurname);
		}

		key = true;

		while (key)
		{
			cout << endl << "Введите имя: ";
			cin >> tempName;
			key = !CheckValidName(tempName);
		}

		cout << endl << "Введите пол 0 - женщина, 1 - мужчина!: ";
		int n;//TODO: Не должен быть int, если есть перечисление!
		
		do
		{
			n = CheckCin(true);
		} 
		while (n != 0 && n != 1);

		switch (n)
		{
			case Female:
				tempSex = Female;
				break;
			case Male:
				tempSex = Male;
				break;
			default:
				break;
		}

		cout << endl << "Введите возраст: ";
		tempAge = CheckCin(true);
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}

	//TODO: Некорректное именование!
	//сделано
	//TODO: Так и не понятно по названию метода - что он делает.
	bool PersonList::CheckValidName(char name[])
	{
		bool isTrueName = true;
		for (int i = 0; i < strlen(name); i++)
		{
			if (isdigit(name[i]) || isspace(name[i]))
			{
				isTrueName = false;
				break;
			}

			if (name[i] == '-')
			{
				if (islower(name[i + 1]))
				{
					name[i + 1] = toupper(name[i + 1]);
				}
				else
				{
					isTrueName = false;
					break;
				}
			}
		}
		return isTrueName;
	}

	void PersonList:: GetCorrectIndex(int& index)
	{
		index = CheckCin(true);
		if (_head == nullptr)
		{
			cout << "Список пуст!" << endl
				<< "Вы можете работать только с позицией [0]!"
				<< endl;
			while (index != 0)
			{
				cout << "Введите ноль!" << endl;
				index = CheckCin(true);
			}
		}
		else if ((index+1) > _count)
		{
			while ((index+1) > _count)
			{
				cout << endl << "Не входит в границы списка!"
					<< endl << "Попробуйте ещё раз!" << endl
					<< "Введите индекс элемента: ";
				index = CheckCin(true);

			}
		}
	}

	void PersonList:: ShowPerson(Person* person)
	{
		
		cout << ". Фамилия:";
		cout << person->GetSurname() << endl;
		cout << "Имя: ";
		cout << person->GetName() << endl;
		cout << "Возраст: " << person->GetAge() << endl;
		switch (person->GetSex())
		{
			//TODO: Форматирование не по RSDN
			//исправил
			case Female:
				cout << "Пол:";
				cout << "Женщина" << endl << endl;
				break;
			case Male:
				cout << "Пол:";
				cout << "Мужчина" << endl << endl;
				break;
			default: break;
		}
	}
}
