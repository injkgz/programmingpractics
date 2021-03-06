﻿#pragma once
#include "Person5.h"
#include "TemplateListItem.h"

namespace lab5
{
	template <class Type>
	class TemplateList
	{
		private:
			TemplateListItem<Type> * _head;
			TemplateListItem<Type> * _tail;
			int _count; 
		public:
			TemplateList<Type>()
			{
				_head = nullptr;
				_tail = nullptr;
			}

			void Add(Type value)
			{
				TemplateListItem<Type>* temp = new TemplateListItem<Type>(value);
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

			Type Find(int index)
			{
				if (index < 0)
				{
					return NULL;
				}

				TemplateListItem<Type>* searchedItem = _head;

				for (int i = 0; i < index; i++)
				{
					if (searchedItem->Next != nullptr)
					{
						searchedItem = searchedItem->Next;
					}
				}
				cout<<searchedItem->GetValue();
				cout << endl << "____________________________" << endl;
				return searchedItem->GetValue();
			}

			int IndexOf(Type value)
			{
				TemplateListItem* searchedValue = _head;
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

			void Remove(Type value)
			{
				TemplateListItem<Type>* deletedItem = _head;

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

			void RemoveAt(int index)
			{
				Type deletedItem = Find(index);
				if (deletedItem == nullptr)
				{
					return;
				}
				Remove(deletedItem);
			}

			void Clear()
			{
				TemplateListItem<Type>* temp = _head;
				while (temp != nullptr)
				{
					TemplateListItem<Type>* tempNext = temp->Next;
					delete temp;
					temp = tempNext;
				}
				_head = nullptr;
				_tail = nullptr;
				_count = 0;
			}

			int GetCount()
			{
				return _count;
			}
			
			void ShowList()
			{
				
				if (_count == 0)
				{
					cout << "Список и так чист!";
					return;
				}

				int index = 0;
				Type newValue = Find(index);
				
				while (index + 1 < _count)
				{
					index++;
					newValue = Find(index);
				}
			}

			int GetCorrectIndex(int& index)
			{
				index = CheckCin(true);
				if (_head == nullptr)
				{
					cout << "Список пуст!" << endl//TODO: Как это я могу работать с позицией 0, если список пуст? Для работы я должен сперва создать список.
						//исправил
						<< "Для начала создайте список!"
						<< endl;
					return 1;
				}
				else if ((index + 1) > _count)
				{
					while ((index + 1) > _count)
					{
						cout << endl << "Не входит в границы списка!"
							<< endl << "Попробуйте ещё раз!" << endl
							<< "Введите индекс элемента: ";
						index = CheckCin(true);

					}
					return 0;
				}
			}

			
			friend std::ostream& operator<<(std::ostream& os, TemplateList* list)
			{
				TemplateListItem<Type>* temp = list->_head;
				int i = 0;
				cout << "Подсписок: ";
				while (temp != nullptr)
				{
					cout << temp->GetValue() << "  ";
					temp = temp->Next;
				}
				return os;
			}
	};

	static std::ostream& operator << (std::ostream &os, lab5::Person* person)
	{
		os << person->GetDescription();
		return os;
	}

	static std::ostream& operator << (std::ostream & os, double* d)
	{
		os << d[0];
		return os;
	}	

	
}