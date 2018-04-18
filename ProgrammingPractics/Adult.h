#pragma once

#include "Person5.h"
#include "PersonTools.h"

namespace lab5
{
	class Adult : public Person
	{
		private:
			Adult * _marriedOn = nullptr;
			char _workPlace[Person::ArraySize];
		public: //TODO: Именование передаваемого параметра
			virtual void SetAge(int Age) override;
			//TODO: Длинные строки!
			Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, Adult* marriedOn, char* workPlace);
			Adult(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex, char* workPlace);
			static Adult* GetRandom(Sex sex);
			void SetMarriedOn(Adult* marriedOn);
			Adult* GetMarriedOn();
			void SetWorkPlace(char* workPlace);
			char* GetWorkPlace();
			virtual string GetDescription();
			~Adult();
	};
}