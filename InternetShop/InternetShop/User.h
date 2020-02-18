#pragma once
#include <string>
#include <memory>
#include "ShoppingCart.h"
#include "CCardFactory.h"

using namespace std;

class Person
{
	string _name;
	string _address;
	unique_ptr<ShoppingCart> _userCart;
	unique_ptr<Card> _card;

public:
	Person(){}
	Person(const string& name, const string& cardType) :_name(name), _userCart(new ShoppingCart()), _card(nullptr)
	{
		_card.reset(CCardFactory::getCard(cardType));
	}

	bool addItemInCart(const string& itemName, int itemQuant, double itemPrice)
	{
		Items it(itemName, itemQuant, itemPrice);
		return _userCart->addItem(move(it));
	}

	bool removeItemFrmCart(const string& itemName, int itemQuant=0)
	{
		Items it(itemName,itemQuant);
		return _userCart->removeItem(move(it));
	}

	double checkOutCart()
	{
		double TotalCost = _userCart->getTotalPrice();
		if (TotalCost > 0.0)
		{
			TotalCost -= TotalCost*(_card->getDiscount() / 100);
		}
		_userCart->clearCart();

		return TotalCost > 0.0 ? TotalCost : 0.0;
	}
};