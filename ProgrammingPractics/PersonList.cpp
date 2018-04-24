#include "PersonList.h"

namespace lab5
{
	template <class Type>
	//добавить человека в список
	PersonList<Type>::PersonList()
	{
		_head = nullptr;
		_tail = nullptr;
	}

	template <class Type>
	void PersonList<Type>::Add(Type value)
	{
		PersonListItem* temp = new PersonListItem(value);
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

	template <class Type>
	void PersonList<Type>::ShowList()
	{
		int index = 0;
		Type* newValue = Find(index);
		while (index+1 < _count)
		{
			index++;
			newValue = Find(index);
		}
	}

	//найти человека по указанному индексу
	template <class Type>
	Type PersonList<Type>::Find(int index)
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
			cout << endl << "____________________________" << endl;
		}
		return searchedItem->GetValue();
	}

	//вернуть индекс человека, если он есть в списке
	template <class Type>
	int PersonList<Type>::IndexOf(Type* value)
	{
		PersonListItem* searchedValue = _head;
		int index = 0;
		while (searchedValue != nullptr)
		{
			if (*searchedValue->GetValue() == *person)
			{
				cout << "Индекс искомого элемента = " << index;
				return index;
			}
			index++;
			searchedValue = searchedValue->Next;
		}
		cout << "Такой личности у нас нет!";
		return -1;
	}

	//удалить человека из списка
	template <class Type>
	void PersonList<Type>::Remove(Type* value)
	{
		PersonListItem* deletedItem = _head;

		while (deletedItem != nullptr)
		{
			if (*deletedItem->GetValue() == *value)
			{
				if (deletedItem == _head)
				{
					_head = deletedItem->Next;
					if (_head != nullptr)
					{
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

	//удалить человека из списка по индексу
	template <class Type>
	void PersonList<Type>::RemoveAt(int index)
	{
		Type *deletedItem = Find(index);
		if (deletedItem == nullptr)
		{
			return;
		}
		Remove(deletedItem);
	}


	//очистить список
	template <class Type>
	void PersonList<Type>::Clear()
	{
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			PersonListItem* tempNext = temp->Next;
			delete temp;
			temp = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}

	//получить количество элементов
	template <class Type>
	int PersonList<Type>::GetCount()
	{
		return _count;
	}

	/*Person* PersonList::Read()
	{
		bool key = true;
		char tempName[Person::ArraySize];
		char tempSurname[Person::ArraySize];
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
		while (tempAge < 0 && tempAge > 125)
		{
			cout << endl << "Введён некорректный возраст!" << endl
				<< "Возраст не может быть отрицательным или больше 125!"
				<< "Попробуйте ещё раз!" << endl;
			tempAge = CheckCin(true);
		}
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}*/

	template <class Type>
	bool PersonList<Type>::CheckValidName(char name[])
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

	template <class Type>
	void PersonList<Type>:: GetCorrectIndex(int& index)
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

	template <class Type>
	void PersonList<Type>:: ShowPerson(Type* value)
	{
		cout << value->GetDescription() << endl;
	}
}
