#pragma once
#include "Items.h"

using namespace std;

class ShoppingCart
{
	unordered_set<Items> _items;
	double _totalPrice;

public:
	ShoppingCart() :_totalPrice(0.0)
	{
		
	}

	ShoppingCart(const ShoppingCart& ) = delete;
	ShoppingCart& operator=(const ShoppingCart&) = delete;
	ShoppingCart(ShoppingCart&& rtVal)
	{
		_items = std::move(rtVal._items);
		_totalPrice = std::move(rtVal._totalPrice);
	}
	ShoppingCart& operator=(ShoppingCart&& rtVal)
	{
		_items = std::move(rtVal._items);
		_totalPrice = std::move(rtVal._totalPrice);
		return *this;
	}

	virtual bool addItem(Items&& it);

	virtual bool removeItem(Items&& it);

	bool isCartEmpty()
	{
		return _items.empty();
	}

	void clearCart()
	{
		_items.clear();
		_totalPrice = 0.0;
	}

	double getTotalPrice()
	{
		return _totalPrice;
	}

	virtual ~ShoppingCart()
	{

	}
};