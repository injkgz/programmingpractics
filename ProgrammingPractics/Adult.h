#pragma once
#include "PersonList.h"
#include "CheckCin.h"
#include "Sex.h"
#include "Person5.h"
#include "PersonTools.h"
#include "lab3.h"

namespace lab5
{
	class Adult : public Person
	{
		private:
			Adult * _marriedOn = nullptr;
			char _workPlace[Person::arraySize];
		public:
			virtual void SetAge(int Age) override;
			Adult(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex, Adult* marriedOn, char* workPlace);
			Adult(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex, char* workPlace);
			static Adult* GetRandom();
			static Adult* GetRandom(Sex sex);
			void SetMarriedOn(Adult* marriedOn);
			Adult* GetMarriedOn();
			void SetWorkPlace(char* workPlace);
			char* GetWorkPlace();
			string GetDescriptionAdult();
	};
}