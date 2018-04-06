#pragma once
#include "Sex.h"

namespace lab5
{
	class Person
	{
		public:
			//TODO: Зачем это публично?
			static const int arraySize = 250;
			Person(char Name[arraySize], char Surname[arraySize], int Age, Sex Sex);
			bool operator==(const Person& good);
			bool operator!=(const Person& good);
			void SetName(char name[arraySize]);
			void SetSurname(char surname[arraySize]);
			void SetAge(int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
		private:
			//TODO: Именование не по RSDN!
			char Name[arraySize];
			char Surname[arraySize];
			int Age;
			Sex Sex;
	};
}