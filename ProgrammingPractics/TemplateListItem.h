#pragma once
#include "Person5.h"
namespace lab5
{
	template <class Type>
	class TemplateListItem
	{
		public:
			TemplateListItem<Type>(Type value)
			{
				if (value != NULL)
				{
					_value = value;
				}
			}

			Type GetValue()
			{
				if (this == nullptr)
				{
					return NULL;
				}
				return _value;
			}

			TemplateListItem<Type>* Next = nullptr;
			TemplateListItem<Type>* Prev = nullptr;
		private:
			Type _value;
	};
}