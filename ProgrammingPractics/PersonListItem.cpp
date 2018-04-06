#include "PersonListItem.h"
namespace lab5
{
	Person* lab5::PersonListItem::GetValue()
	{
		//TODO: Не правильно, указатель на текущий объект не может быть null, 
		//TODO: т.к. он уже создан и метод вызван
		if (this == nullptr)
		{
			return nullptr;
		}
		return Value;
	}
}
