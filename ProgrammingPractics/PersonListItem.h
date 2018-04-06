#pragma once
#include "Person5.h"

namespace lab5
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				Value = person;
			}
			Person* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			//TODO: Именование не по RSDN
			Person* Value;
	};
}