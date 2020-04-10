#include "CUser.h"
#include<iostream>

CUser::CUser(float fBank) {
	m_bank = fBank;
}

void CUser::setBet(float betSpinBox) {
	m_bet = betSpinBox;
}
float CUser::getBet() {
	return m_bet;
}

void CUser::addWin() {
	m_wins += 1;
}

int CUser::getWins() {
	return m_wins;
}

void CUser::addLoss() {
	m_losses += 1;
}

int CUser::getLosses() {
	return m_losses;
}

void CUser::changeBank(bool secondRoll, int iSecondRollTotal, bool bWinGame) {
	if (bWinGame == false) {
		m_bank -= m_bet;
	}
	else
	{
		// Base below upon payout:
		if (secondRoll == false)
		{
			// 1:1 payoff:
			m_bank += m_bet * 1;
		}
		else {
			switch (iSecondRollTotal) {
			case 4:
				m_bank += m_bet * 2;
				break;
			case 5:
				m_bank += m_bet * 1.5;
				break;
			case 6:
				m_bank += m_bet * 1.2;
				break;
			case 8:
				m_bank += m_bet * 1.2;
				break;
			case 9:
				m_bank += m_bet * 1.5;
				break;
			case 10:
				m_bank += m_bet * 2;
				break;
			}
		}
	}
}

float CUser::getBank() {
	return m_bank;
}

void CUser::setFirstRollAmount(int firstRollTotal) {
	m_firstRollAmount = firstRollTotal;
}

bool CUser::winLoseGame(bool firstRoll, int iSecondRollTotal, bool& winGame) {

	// Done with roll, until next game:
	if (firstRoll == true && (m_firstRollAmount == 7 || m_firstRollAmount  == 11)) {
		winGame = true;

		return true;
	}
	// done with roll, until next game:
	else if (firstRoll == true && m_firstRollAmount == 2 || m_firstRollAmount == 3 || m_firstRollAmount == 12) {

		winGame = false;
		return true;
	}
	else if (firstRoll == true && m_firstRollAmount == 4 || m_firstRollAmount == 5 || m_firstRollAmount == 6 || m_firstRollAmount == 8 || m_firstRollAmount == 9 || m_firstRollAmount == 10) {
		winGame = false;
		return false;
	}

	// roll a second time
	if (m_firstRollAmount == iSecondRollTotal) {
		winGame = true;
		return true;
	}
	else {
		winGame = false;
		return false;
	}
}