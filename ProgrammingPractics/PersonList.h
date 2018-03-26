#pragma once
#include "Person5.h"
#include "PersonListItem.h"

namespace lab5
{
	class PersonList
	{
		private:
			PersonListItem * _head;//��������� �� ������ ������
			PersonListItem * _tail;
			int _count; //���������� ��������� � ������
		public:
			PersonList(); //����������� ������
			void Add(Person* person); //�������� �������� � ������
			Person* Find(int index); //����� �������� �� ���������� �������
			int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
			void Remove(Person* person); //������� �������� �� ������
			void RemoveAt(int index); //������� �������� �� ������ �� �������
			void Clear(); //�������� ������
			int GetCount(); //�������� ���������� ���������
	};
}