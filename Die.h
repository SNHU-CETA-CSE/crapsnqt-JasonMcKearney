#pragma once
#ifndef CRAPS_DIE_H
#define CRAPS_DIE_H
#include<iostream>
class Die
{
private:
	int m_numberOfSides;
	int m_startingValue;
	int m_rollAmount;
	int m_firstRollAmount;
	int m_secondRollAmount;

public:
	Die(int iStartingNumberOfSides, int iStartingValue);

	void roll();
	int getRollAmount();
	void setNumberOfSides(int iNewNumSides);
	int getNumberOfSides();
	void setStartingValue(int iNewStartingValue);
	int getStartingValue();
};

#endif // !CRAPS_DIE_H