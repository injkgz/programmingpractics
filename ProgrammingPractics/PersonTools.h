#pragma once
#include "TemplateList.h"


namespace lab5
{
	class PersonTools
	{
		public:
			static void GenerateRandomPerson(char tempName[Person::ArraySize], 
				char tempSurname[Person::ArraySize], 
				const char name[10], 
				const char surname[10])
			{
				strcpy_s(tempName, Person::ArraySize, name);
				strcpy_s(tempSurname, Person::ArraySize, surname);				
			}
			static bool CheckValidName(char name[])
			{
				bool isTrueName = true;
				for (int i = 0; i < strlen(name); i++)
				{//TODO: Есть дубль в предыдущей лабе!
					//исправил
					if (isdigit(name[i]) || isspace(name[i]))
					{
						isTrueName = false;
						break;
					}

					if (name[i] == '-')
					{
						if (islower(name[i + 1]))
						{
							name[i + 1] = toupper(name[i + 1]);
						}
						else
						{
							isTrueName = false;
							break;
						}
					}
				}
				return isTrueName;
			}
	};
}