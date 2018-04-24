﻿#pragma once

#include "Person5.h"
#include "PersonTools.h"

namespace lab5
{
	class Adult : public Person
	{
		private:
<<<<<<< HEAD
			//TODO: Зачем они static?
			//Переменная не должна инициализироваться для каждого объекта отдельно, а для класса в целом один раз!
=======
>>>>>>> parent of b41fdc8... TODO
			static const int _maxAge = 125;
			static const int _minAge = 18;
			Adult * _marriedOn = nullptr;
			char _workPlace[Person::ArraySize];
<<<<<<< HEAD
		public:
			virtual void SetAge(unsigned int age) override;
=======
		public: //TODO: Именование передаваемого параметра
			//исправил
			virtual void SetAge(int age) override;
			//TODO: Длинные строки!
			//исправил
>>>>>>> parent of b41fdc8... TODO
			Adult(char name[ArraySize], char surname[ArraySize], int age, 
				enum Sex sex, Adult* marriedOn, char* workPlace);
			Adult(char name[ArraySize], char surname[ArraySize], int age,
				enum Sex sex, char* workPlace);
			void SetMarriedOn(Adult* marriedOn);
			Adult* GetMarriedOn();
			void SetWorkPlace(char* workPlace);
			char* GetWorkPlace();
			virtual string GetDescription();
			~Adult();
	};
}