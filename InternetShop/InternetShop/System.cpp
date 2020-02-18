#include "User.h"
#include "Items.h"
#include <unordered_map>

using namespace std;

class System
{
	unordered_map<string, Person> _users;
	unordered_map<string, Items> _availableItems;

	void notifyUser(const string& name, const string& message) {}

protected:

	bool registerUser(const string& name, const string& address, const string& cardType)
	{
		_users[name] = Person(name, cardType);
		return true;
	}

	bool addItemInInventory(const string& itemName, double itemPrice, int itemQuant)
	{
		auto itr = _availableItems.find(itemName);
		if (itr != _availableItems.end())
		{
			_availableItems[itemName].quantity += itemQuant;
			_availableItems[itemName].price = itemPrice;
			
		}
		else
		{
			_availableItems[itemName] = Items(itemName, itemQuant, itemPrice);
		}

		return true;
	}

	

public:

	void checkOut(const string& name)
	{
		auto itr = _users.find(name);
		double toPay = 0.0;

		if (itr != _users.end())
		{
			toPay = itr->second.checkOutCart();
		}
		notifyUser(name, "Total bill post applying card discount is: " + to_string(toPay));
	}
	void buyItem(const string& userName, const string& item, int quantity)
	{
		if (_availableItems[item].quantity > quantity)
		{
			_users[userName].addItemInCart(item, quantity, _availableItems[item].price);
			_availableItems[item].quantity -= quantity;
		}
	}
	void putItem(const string& userName, const string& item, int quantity)
	{
		_users[userName].removeItemFrmCart(item, quantity);
		_availableItems[item].quantity += quantity;
	}

};

class SysAdmin : public System
{
public:
	bool registerUser(const string& name, const string& address, const string& cardType)
	{
		return System::registerUser(name, address, cardType);
	}

	bool addItemInInventory(const string& itemName, double itemPrice, int itemQuant)
	{
		return System::addItemInInventory(itemName, itemPrice, itemQuant);
	}
};

int main()
{
	System sys;
	SysAdmin admin;
	admin.registerUser("Abhinav","Pune","Silver");

	return 0;
}