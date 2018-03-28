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
			PersonList() 
			{};
			void Add(Person* person); 
			Person* Find(int index); 
			int IndexOf(Person* person); 
			void Remove(Person* person); 
			void RemoveAt(int index); 
			void Clear(); 
			int GetCount(); 
			Person* Read();
			static Person* MakeRandomPerson(); 
			void GetCorrectIndex(int& index);
			void ShowPerson(Person* person);
			void Removing(Person* person);
	};
	void GenerateRandomPerson(char tempName[250], char tempSurname[250],
		const char Name[10], const char Surname[10], int& tempAge);
}