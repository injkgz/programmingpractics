#pragma once
#include "Person5.h"
#include "PersonListItem.h"

namespace lab5
{
	class PersonList
	{
		private:
			PersonListItem * _head;
			PersonListItem * _tail;
			int _count; 
			bool CheckValidName(char name[]);
		public:
			PersonList();
			void Add(Person* person); 
			Person* Find(int index); 
			int IndexOf(Person* person); 
			void Remove(Person* person); 
			void RemoveAt(int index); 
			void Clear(); 
			int GetCount();
			//TODO: Нет такого метода.
			Person* Read();
			void ShowList();
			void GetCorrectIndex(int& index);
			void ShowPerson(Person* person);
			//TODO: Нет такого метода.
			void CreateFamily();
	};
	
}