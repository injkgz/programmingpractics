#pragma once
#include "Sex.h"
#include "CheckCin.h"

namespace lab5
{//TODO: Концептуально неверно! Объект класса person не имеет смысла, а в вашем случае его можно создать.
	class Person
	{
		public:
			static const int ArraySize = 250;
			//TODO: Зачем пустой конструктор?
			Person() {};
			Person(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex);
			bool operator==(const Person& good);
			bool operator!=(const Person& good);
			void SetName(char name[ArraySize]);
			void SetSurname(char surname[ArraySize]);
			virtual void SetAge(unsigned int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			virtual int GetAge();
			Sex GetSex();
			virtual string GetDescription();
			//TODO: футакимбыть!
			//~Person();
		protected: 
			int _age;
		private:
			char _name[ArraySize];
			char _surname[ArraySize];
			Sex _sex;
	};
}