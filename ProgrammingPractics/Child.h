#pragma once
#include "PersonList.h"
#include "CheckCin.h"
#include "Sex.h"
#include "Person5.h"

namespace lab5
{
	class Child : public Person
	{
		private:
			Person * Mother;
			Person * Father;
			char School[lab5::Person::arraySize];
		public:
			virtual void SetAge(int Age) override;
			virtual int GetAge() override;
	};
}