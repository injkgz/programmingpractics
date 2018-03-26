#pragma once
#include "Sex.h"

namespace lab5
{
	class Person
	{
		public: char Name[20];
				char Surname[20];
				int Age;
				Sex Sex;
				Person()
				{              };
	};
}