#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class Items
{
public:
	int quantity;
	string name;
	double price;

	Items(){}
	Items(const string& nam, int qua=0, double pri=0.0) :
		quantity(qua), name(nam), price(pri)
	{

	}

	Items(const Items& it)
	{
		this->quantity = it.quantity;
		this->name = it.name;
		this->price = it.price;
	}

	Items& operator=(const Items& it)
	{
		this->quantity = it.quantity;
		this->name = it.name;
		this->price = it.price;

		return *this;
	}

	Items(Items&& rtVal)
	{
		this->quantity = std::move(rtVal.quantity);
		this->name = std::move(rtVal.name);
		this->price = std::move(rtVal.price);
	}

	Items& operator=(Items&& rtVal)
	{
		this->quantity = std::move(rtVal.quantity);
		this->name = std::move(rtVal.name);
		this->price = std::move(rtVal.price);
		return *this;
	}

	bool operator ==(const Items & obj) const
	{
		if (name == obj.name)
			return true;
		else
			return false;
	}
};

namespace std
{
	template<>
	struct hash<Items>
	{
		size_t
			operator()(const Items & obj) const
		{
			return hash<string>()(obj.name);
		}
	};
}
