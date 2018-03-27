#pragma once
#include "Sex.h"

namespace lab5
{
	class Person
	{
		public: 
				Person(char Name[20], char Surname[20], int Age, Sex Sex);
				bool operator==(const Person& good);
				bool operator!=(const Person& good);
				void SetName(char name[20]);
				void SetSurname(char surname[20]);
				void SetAge(int age);
				void SetSex(Sex sex);
				char* GetName();
				char* GetSurname();
				int GetAge();
				Sex GetSex();
		private:
				char Name[20];
				char Surname[20];
				int Age;
				Sex Sex;
	};
}