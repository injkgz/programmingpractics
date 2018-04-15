#pragma once
#include "Person5.h"
#include "Adult.h"
#include "PersonTools.h"

namespace lab5
{
	class Child : public Person
	{
		private:
			Adult* _mother;
			Adult* _father;
			char _school[ArraySize];
		public:
			Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school);
			virtual void SetAge(int Age) override;
			virtual int GetAge() override;
			void SetFather(Adult* father);
			void SetMother(Adult* mother);
			void SetSchool(char school[ArraySize]);
			Adult* GetMother();
			Adult* GetFather();
			static Child* GetRandom();
			char* GetSchool();
			virtual string GetDescription();
			~Child();
	};
}