#pragma once
#include "Sex.h"
#include "CheckCin.h"

namespace lab5
{
	class Person
	{
		public:
			//TODO: Зачем это публично?
			//я обращаюсь к этой переменной также в методах и полях
			//6-ой лабораторной работы
			static const int arraySize = 250;
			Person() {};
			Person(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex);
			bool operator==(const Person& good);
			bool operator!=(const Person& good);
			void SetName(char name[arraySize]);
			void SetSurname(char surname[arraySize]);
			virtual void SetAge(int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			virtual int GetAge();
			Sex GetSex();
			string GetDescription();
			~Person();
		protected: 
			int _age;
		private:
			//TODO: Именование не по RSDN!
			//исправил, на гите лежал старый код)
			char _name[arraySize];
			char _surname[arraySize];
			Sex _sex;
	};
}