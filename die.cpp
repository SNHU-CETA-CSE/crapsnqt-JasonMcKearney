#include "Die.h"
#include <iostream>
#include <ctime>

Die::Die(int iStartingNumberOfSides, int iStartingValue = 1) {
	m_numberOfSides = iStartingNumberOfSides;
	m_startingValue = iStartingValue;
	int m_rollAmount;
}

void Die::roll() {
	// Equation for rolling a dice:
	m_rollAmount = rand() % m_numberOfSides + m_startingValue;
}

int Die::getRollAmount() {
	return m_rollAmount;
}

void Die::setNumberOfSides(int iNewNumSides) {
	m_numberOfSides = iNewNumSides;
}

int Die::getNumberOfSides() {
	return m_numberOfSides;
}

void Die::setStartingValue(int iNewStartingValue) {
	m_startingValue = iNewStartingValue;
}

int Die::getStartingValue() {
	return m_startingValue;
}