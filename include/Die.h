//
// Created by Harrison Baker on 8/9/24.
//

#ifndef MODULE_5_CODING_PORTION_DIE_H
#define MODULE_5_CODING_PORTION_DIE_H

#include <iostream>
#include <ctime>

class Die
{
private:
	std::string shape;
	int sideShowing;
	int numberOfRolls = 0;
public:
	const int numberOfSides;
	Die(int numberOfSides ) : numberOfSides(numberOfSides), shape("") {
	}
	Die(std::string shape, int numberOfSides) : shape(shape), numberOfSides(numberOfSides) {}


	friend std::ostream &operator<<(std::ostream &strm, const Die &die) {
		strm<< "A " << die.numberOfSides << " sided die that is shaped " << die.shape;
		return strm;
	}

	int getSideShowing()
	{
		return sideShowing;
	}

	void setSideShowing(int n)
	{
		sideShowing = n;
	}

	int getNumberOfRolls()
	{
		return numberOfRolls;
	}

	void setNumberOfRolls(int n)
	{
		numberOfRolls = n;
	}

	int roll()
	{
		int side = (rand() % numberOfSides) + 1;
		return side;
	}
};

#endif //MODULE_5_CODING_PORTION_DIE_H
