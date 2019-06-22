#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>

using namespace std;
class Fruit
{
	int ID_;
	int ripeRate_;

public:

	Fruit() 
	{
		ID_ = -1;
		ripeRate_ = -1;
	}

	Fruit(int id, int ripeRate)
	{
		ID_ = id;
		ripeRate_ = ripeRate;
	}
	
	int getID()
	{
		return ID_;
	}

	int getRipeRate()
	{
		return ripeRate_;
	}

};

#endif