#pragma once
#include "PersonList.h"
#include "CheckCin.h"


namespace lab5
{
	class Adult : public Person
	{
		private:
			Person * MarriedOn = nullptr;
			char WorkPlace[Person::arraySize];
		public:
			virtual void SetAge(int Age) override;
			virtual int GetAge() override;
	};
}