#pragma once
#include "PersonList.h"


namespace lab5
{
	class PersonTools
	{
		public:
			static void GenerateRandomPerson(char tempName[Person::ArraySize], 
				char tempSurname[Person::ArraySize], 
				//TODO:
				//исправил
				const char name[10], 
				const char surname[10])
			{
				strcpy_s(tempName, Person::ArraySize, name);
				strcpy_s(tempSurname, Person::ArraySize, surname);				
			}
	};
}