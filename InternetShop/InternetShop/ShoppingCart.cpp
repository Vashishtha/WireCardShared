#include "ShoppingCart.h"

bool ShoppingCart::addItem(Items&& it)
{
	bool ret = false;
	auto itemPtr = _items.find(it);
	if (itemPtr != _items.end())
	{
		_totalPrice += (it.price * it.quantity);
		it.quantity += itemPtr->quantity;
		_items.erase(itemPtr);
		_items.insert(std::move(it));
		ret = true;
	}
	else
	{
		_totalPrice += (it.price * it.quantity);
		_items.insert(std::move(it));
		ret = true;
	}
	
	return ret;
}

bool ShoppingCart::removeItem(Items&& it)
{
	bool ret = false;
	auto itemPtr = _items.find(it);

	if (itemPtr != _items.end())
	{
		if (itemPtr->quantity > it.quantity)
		{
			_totalPrice -= (it.price * it.quantity);
			it.quantity = itemPtr->quantity - it.quantity;
			_items.erase(itemPtr);
			_items.insert(std::move(it));
			
			ret = true;
		}
		else
		{
			_items.erase(itemPtr);
			_totalPrice -= (itemPtr->price * itemPtr->quantity);
			ret = true;
		}
	}

	return ret;
}