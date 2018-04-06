#include "PersonListItem.h"
namespace lab5
{
	Person* lab5::PersonListItem::GetValue()
	{
		if (this == nullptr)
		{
			return nullptr;
		}
		return _value;
	}
}
