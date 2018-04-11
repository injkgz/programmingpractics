#pragma once
#include "PersonList.h"
#include "CheckCin.h"
#include "Sex.h"
#include "Person5.h"
#include "Adult.h"

namespace lab5
{
	class Child : public Person
	{
		private:
			Adult* _mother;
			Adult* _father;
			char _school[arraySize];
		public:
			Child(char* name, char* surname, int age, Sex sex, Adult* mother, Adult* father, char* school);
			virtual void SetAge(int Age) override;
			virtual int GetAge() override;
			void SetFather(Adult* father);
			void SetMother(Adult* mother);
			void SetSchool(char school[arraySize]);
			Adult* GetMother();
			Adult* GetFather();
			static Child* GetRandom();
			char* GetSchool();
			string GetDescriptionChild();
	};
}