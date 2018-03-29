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

	void PersonList::ShowList()
	{
		int index = 0;
		Person* newPerson = Find(index);
		while (index+1 < _count)
		{
			index++;
			newPerson = Find(index);
		}
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
			{
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

	Person* PersonList::Read()
	{
		bool key = true;
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		int tempAge;
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
		//TODO: Переделать в перечисление
		//сделано
		do
		{
			tempSex = (Sex)(int)CheckCin(true);
			if (tempSex != 0 && tempSex != 1)
			{
				cout << endl << "Введено неправильное значение! Введите пол 0 - женщина, 1 - мужчина!: ";
			}
		} 
		while (tempSex != 0 && tempSex != 1);

		

		cout << endl << "Введите возраст: ";
		tempAge = CheckCin(true);
		while (tempAge < 0)
		{
			cout << endl << "Введён некорректный возраст!" << endl
				<< "Возраст не может быть отрицательным!"
				<< "Попробуйте ещё раз!" << endl;
			tempAge = CheckCin(true);
		}
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}

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
