#pragma once
#include "Sex.h"
#include "CheckCin.h"

namespace lab5
{
	class Person
	{
		public:
			static const int ArraySize = 250;
			Person() {};
			//TODO: Название входных аргументов
			//исправил
			Person(char name[ArraySize], char surname[ArraySize], int age, enum Sex sex);
			bool operator==(const Person& good);
			bool operator!=(const Person& good);
			void SetName(char name[ArraySize]);
			void SetSurname(char surname[ArraySize]);
			virtual void SetAge(int age) = 0;
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			virtual int GetAge();
			Sex GetSex();
			virtual string GetDescription() = 0;
			~Person();
		protected: 
			int _age;
		private:
			char _name[ArraySize];
			char _surname[ArraySize];
			Sex _sex;
	};
}