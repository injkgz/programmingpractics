#include "PersonListItem.h"
namespace lab5
{
	template <class Type>
	Type lab5::TemplateListItem<Type>::GetValue()
	{
		if (this == nullptr)
		{
			return nullptr;
		}
		if (this->_value == nullptr)
		{
			return nullptr;
		}
		return _value;
	}
}
