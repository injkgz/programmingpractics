#pragma once
#include "Sex.h"

namespace lab5
{
	class Person
	{
		public://TODO: Зачем двойные отступы?
			//исправил
			Person(char Name[250], char Surname[250], unsigned int Age, Sex Sex);
			bool operator==(const Person& good);
			bool operator!=(const Person& good);
			void SetName(char name[250]);
			void SetSurname(char surname[250]);
			void SetAge(unsigned int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
		private:
			char Name[250];
			char Surname[250];
			int Age;
			Sex Sex;
	};
}