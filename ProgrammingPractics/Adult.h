#pragma once

#include "Person5.h"
#include "PersonTools.h"

namespace lab5
{
	class Adult : public Person
	{
		private:
			static const int _maxAge = 125;
			static const int _minAge = 18;
			Adult * _marriedOn = nullptr;
			char _workPlace[Person::ArraySize];
		public: //TODO: Именование передаваемого параметра
			//исправил
			virtual void SetAge(int age) override;
			//TODO: Длинные строки!
			//исправил
			Adult(char name[ArraySize], char surname[ArraySize], int age, 
				enum Sex sex, Adult* marriedOn, char* workPlace);
			Adult(char name[ArraySize], char surname[ArraySize], int age,
				enum Sex sex, char* workPlace);
			void SetMarriedOn(Adult* marriedOn);
			Adult* GetMarriedOn();
			void SetWorkPlace(char* workPlace);
			char* GetWorkPlace();
			virtual string GetDescription();
			~Adult();
	};
}