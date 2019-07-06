#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include "FruitIDAndRipeRate.h"

using namespace std;
class Fruit
{
	int ID_;
	int ripeRate_;
	int parentTreeNum_ = 0;

public:

	Fruit() 
	{
		ID_ = -1;
		ripeRate_ = -1;
		parentTreeNum_ = -1;
	}

	Fruit(int id, int ripeRate)
	{
		ID_ = id;
		ripeRate_ = ripeRate;
		parentTreeNum_ = -1;
	}

	Fruit(int id, int ripeRate, int parentTreeNum)
	{
		ID_ = id;
		ripeRate_ = ripeRate;
		parentTreeNum_ = parentTreeNum;
	}

	void changeRipeRate(int newRipeRate)
	{
		ripeRate_ = newRipeRate;
	}
	
	int getID()
	{
		return ID_;
	}

	int getRipeRate()
	{
		return ripeRate_;
	}

	int getParentTreeNum()
	{
		return parentTreeNum_;
	}

	FruitIDAndRipeRate getFruitIDAndRipeRate()
	{
		return FruitIDAndRipeRate(ID_, ripeRate_);
	}

};

#endif