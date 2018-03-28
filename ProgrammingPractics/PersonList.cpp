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
					_head->Next = deletedItem->Next->Next;
					_head->Prev = nullptr;
				}
				else if (deletedItem == _tail)
				{
					_tail = deletedItem->Prev;
					_tail->Prev = deletedItem->Prev->Prev;
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
		}
		deletedItem = deletedItem->Next;
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
		char tempName[20];
		char tempSurname[20];
		int tempAge;
		Sex tempSex;
		int key = rand() % 2;

		switch (key)
		{
			case 'f':
			{
				strcpy_s(tempName, FemaleName[rand() % 10]);
				strcpy_s(tempSurname, FemaleSurname[rand() % 10]);
				tempAge = rand() % 50;
				tempSex = Female;
				break;
			}
			case 'm':
			{
				strcpy_s(tempName, MaleName[rand() % 10]);
				strcpy_s(tempSurname, MaleSurname[rand() % 9]);
				tempAge = rand() % 50;
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
			key = !CheckChar(tempSurname);
		}

		key = true;

		while (key)
		{
			cout << endl << "Введите имя: ";
			cin >> tempName;
			key = !CheckChar(tempName);
		}

		cout << endl << "Введите пол 0 - женщина, 1 - мужчина!: ";
		int n;
		
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
	bool PersonList::CheckChar(char name[])
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
				<< "Вы можете добавить только на позицию [0]!"
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
		{//TODO: Почему проверка по int, а не по перечислениям?
		//сделано
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
