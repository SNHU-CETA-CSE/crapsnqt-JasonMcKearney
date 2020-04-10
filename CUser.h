#pragma once
#ifndef CRAPS_CUSER_H
#define CRAPS_CUSER_H
class CUser
{
private:
	int m_bet{ 0 };
	float m_bank;
	bool m_firstRoll = true;
	bool m_secondRoll = false;
	int m_wins = 0;
	int m_losses = 0;
	int m_firstRollAmount = 0;
public:
	CUser(float fBank);
	void setBet(float betSpinBox);
	float getBet();
	void addWin();
	int getWins();
	void addLoss();
	int getLosses();
	void changeBank(bool secondRoll, int iSecondRollTotal, bool bWinGame);
	float getBank();
	void setFirstRollAmount(int firstRollTotal);
	bool winLoseGame(bool firstRoll, int iSecondRollTotal, bool& winGame);
};

# endif // CRAPS_CUSER_H