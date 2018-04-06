#include "Adult.h"

namespace lab5
{
	void Adult::SetAge(int Age)
	{
		if (Age < 18)
		{
			Person::SetAge(18);
		}
		else
		{
			Person::SetAge(Age);
		}
	}

	int Adult::GetAge()
	{
		int Age = Person::GetAge();
		return Age;
	}
}