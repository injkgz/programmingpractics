#pragma once
#include "Sex.h"
#include "CheckCin.h"

namespace lab5
{//TODO: Концептуально неверно! Объект класса person не имеет смысла, а в вашем случае его можно создать.
	//нужно для 7-ой лабы
	class Person
	{
		public:
			static const int ArraySize = 250;
			//TODO: Зачем пустой конструктор?
			//у меня иначе не отрабатывает, говорит, что нет конструктора по умолчанию. 
			//нужно для 7-ой лабы
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
			//исправил
			~Person();
		protected: 
			int _age;
		private:
			char* _name;
			char* _surname;
			Sex _sex;
	};
}