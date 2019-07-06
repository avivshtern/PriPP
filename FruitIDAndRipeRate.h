#ifndef FRUITFRUITIDANDRIPERATE_H
#define FRUITFRUITIDANDRIPERATE_H
#include <iostream>
#include "Fruit.h"

using namespace std;
class FruitIDAndRipeRate
{
	int ID_;
	int ripeRate_;

public: 

	FruitIDAndRipeRate()
	{
		ID_ = -1;
		ripeRate_ = -1;
	}

	FruitIDAndRipeRate(int id, int ripeRate)
	{
		ID_ = id;
		ripeRate_ = ripeRate;
	}

	FruitIDAndRipeRate(const FruitIDAndRipeRate &other)
	{
		ID_ = other.ID_;
		ripeRate_ = other.ripeRate_;
	}

	bool operator >(FruitIDAndRipeRate &other)
	{
		if (ripeRate_ > other.ripeRate_)
		{
			return true;
		}
		if (ripeRate_ < other.ripeRate_)
		{
			return false;
		}
		if (ripeRate_ == other.ripeRate_)
		{
			if (ID_ > other.ID_)
			{
				return true;
			}
			if (ID_ < other.ID_)
			{
				return false;
			}
		}
	}

	bool operator <(FruitIDAndRipeRate& other)
	{
		if (ripeRate_ < other.ripeRate_)
		{
			return true;
		}
		if (ripeRate_ > other.ripeRate_)
		{
			return false;
		}
		if (ripeRate_ == other.ripeRate_)
		{
			if (ID_ < other.ID_)
			{
				return true;
			}
			if (ID_ > other.ID_)
			{
				return false;
			}
		}
	}

};
#endif