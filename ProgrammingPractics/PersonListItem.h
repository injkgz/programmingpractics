#pragma once
#include "Person5.h"
namespace lab5
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				_value = person;
			}
			Person* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			//TODO: Именование не по RSDN
			//исправил
			Person* _value;
	};
}