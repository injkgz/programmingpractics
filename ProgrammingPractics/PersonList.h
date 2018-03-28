#pragma once
#include "Person5.h"
#include "PersonListItem.h"

namespace lab5
{
	class PersonList
	{//TODO: Зачем столько бесполезных комментариев?
		private:
			PersonListItem * _head;//указатель на голову списка
			PersonListItem * _tail;
			int _count; //количество элементов в списке
			bool isTrueName(char name[]);
		public:
			PersonList() //конструктор класса
			{};
			void Add(Person* person); //добавить человека в список
			Person* Find(int index); //найти человека по указанному индексу
			int IndexOf(Person* person); //вернуть индекс человека, если он есть в списке
			void Remove(Person* person); //удалить человека из списка
			void RemoveAt(int index); //удалить человека из списка по индексу
			void Clear(); //очистить список
			int GetCount(); //получить количество элементов
			Person* Read();
			static Person* MakeRandomPerson(); //генерация личности
			void GetCorrectIndex(int& index);
			void ShowPerson(Person* person);
	};
}