#pragma once
#include "PersonList.h"
#include "CheckCin.h"
#include "Sex.h"
#include "Person5.h"
#include "PersonTools.h"

namespace lab5
{
	class Adult : public Person
	{
		private:
			Person * _marriedOn = nullptr;
			char _workPlace[Person::arraySize];
		public:
			virtual void SetAge(int Age) override;
			Adult(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex, Adult* marriedOn, char* workPlace);
			static Adult* GetRandom();
			void SetMarriedOn(Adult* marriedOn);
			void SetWorkPlace(char* workPlace);
			void MakeWedding();
	};
}