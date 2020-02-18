#pragma once

#include <string>

using namespace std;

class Card
{
	string cardType;

public:
	Card(const string& type) :cardType(type)
	{

	}

	virtual double getDiscount() = 0;
};

class NormalCard : public Card
{
	string uniqNo;
public:
	NormalCard(const string& type) :Card(type)
	{

	}

	virtual double getDiscount()
	{
		return 0.0;
	}
};

class SilverCard : public Card
{

public:
	SilverCard(const string& type) :Card(type)
	{

	}

	virtual double getDiscount()
	{
		return 10.0;
	}
};

class GoldCard : public Card
{

public:
	GoldCard(const string& type) :Card(type)
	{

	}

	virtual double getDiscount()
	{
		return 20.0;
	}
};