#pragma once

#include "Cards.h"

using namespace std;

class CCardFactory
{
public:
	static Card* getCard(const string& type)
	{
		if (type == "Normal")
		{
			return new NormalCard(type);
		}
		else if (type == "Silver")
		{
			return new SilverCard(type);
		}
		else if (type == "Gold")
		{
			return new GoldCard(type);
		}
		else
			return nullptr;

	}
};