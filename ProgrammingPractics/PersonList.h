#pragma once
#include "Person5.h"
#include "PersonListItem.h"

namespace lab5
{
	class PersonList
	{//TODO: ����� ������� ����������� ������������?
		private:
			PersonListItem * _head;//��������� �� ������ ������
			PersonListItem * _tail;
			int _count; //���������� ��������� � ������
			bool isTrueName(char name[]);
		public:
			PersonList() //����������� ������
			{};
			void Add(Person* person); //�������� �������� � ������
			Person* Find(int index); //����� �������� �� ���������� �������
			int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
			void Remove(Person* person); //������� �������� �� ������
			void RemoveAt(int index); //������� �������� �� ������ �� �������
			void Clear(); //�������� ������
			int GetCount(); //�������� ���������� ���������
			Person* Read();
			static Person* MakeRandomPerson(); //��������� ��������
			void GetCorrectIndex(int& index);
			void ShowPerson(Person* person);
	};
}