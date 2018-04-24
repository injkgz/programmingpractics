#pragma once
#include "Person5.h"
#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
	class Child : public Person
	{
		private:
			static const int _minAge = 0;
			static const int _maxAge = 17;
			Adult* _mother;
			Adult* _father;
			char _school[ArraySize];
		public:
			Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school);
			virtual void SetAge(unsigned int age) override;
			virtual int GetAge() override;
			void SetFather(Adult* father);
			void SetMother(Adult* mother);
			void SetSchool(char* school);
			Adult* GetMother();
			Adult* GetFather();
			char* GetSchool();
			virtual string GetDescription();
			~Child();
	};
}