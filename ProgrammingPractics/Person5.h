#pragma once
#include "Sex.h"

namespace lab5
{
	class Person
	{
		public: 
				Person(char Name[40], char Surname[40], unsigned int Age, Sex Sex);
				bool operator==(const Person& good);
				bool operator!=(const Person& good);
				void SetName(char name[40]);
				void SetSurname(char surname[40]);
				void SetAge(unsigned int age);
				void SetSex(Sex sex);
				char* GetName();
				char* GetSurname();
				int GetAge();
				Sex GetSex();
		private:
				char Name[40];
				char Surname[40];
				int Age;
				Sex Sex;
	};
}