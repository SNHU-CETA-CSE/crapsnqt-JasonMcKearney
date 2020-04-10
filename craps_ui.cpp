#include "craps_ui.h"
QString qs;
#include "Die.h"
#include "CUser.h"
#include<qpixmap.h>

craps_ui::craps_ui(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

// instances of die and CUser classes
Die die1(6,1);
Die die2(6,1);
CUser userOne(10000.00);
bool bFirstRoll = true;

void craps_ui::on_rollButton_clicked()
{
	ui.winLoseLabel->setText("");
	ui.rollNumLabelUI->setText("");
	// gets the current bid from the spinbox:
	QString betAmount = ui.spinBoxBidUI->text();
	userOne.setBet(betAmount.toFloat());

	// rolls the dice when button is clicked:
	die1.roll();
	die2.roll();
	std::string die1ImageName = "dieImages/" + std::to_string(die1.getRollAmount()) + "Face.png";
	std::string die2ImageName = "dieImages/" + std::to_string(die2.getRollAmount()) + "Face.png";
	ui.dieOneUI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
	ui.dieTwoUI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));

	// finds the sum:
	int rollTotal = die1.getRollAmount() + die2.getRollAmount();

	bool bGameWon = true, bNotRollAgain = true;
	if (bFirstRoll == true) {
		userOne.setFirstRollAmount(rollTotal);
		// tells the user what they rolled:
		ui.rollNumLabelUI->setText(QString::number(rollTotal));
		// determines if the user has to roll again or if they have won the round:
		bNotRollAgain = userOne.winLoseGame(bFirstRoll, 0, bGameWon);

		// User has to roll die again:
		if (bNotRollAgain == false) {
			bFirstRoll = false;
			// shows what user is rolling for:
			ui.rollNumLabelUI->setText("Rolling for: "+ QString::number(rollTotal));
		}
		// user won or loss on first roll and is done with round:
		else {
			userOne.changeBank(false, 0, bGameWon);
			updateUI(bGameWon);
		}
	}
	// user rolled a second time:
	else {
		ui.rollNumLabelUI->setText("  Rolled a " + QString::number(rollTotal));
		bNotRollAgain = userOne.winLoseGame(bFirstRoll, rollTotal, bGameWon);
		userOne.changeBank(true, rollTotal, bGameWon);
		updateUI(bGameWon);
	}
}

void craps_ui::updateUI(bool bGameWon) {

	if (bGameWon == true) {
		userOne.addWin();
		ui.winLoseLabel->setText("You Won!");
	}
	else {
		userOne.addLoss();
		ui.winLoseLabel->setText("You Loss!");
	}

	if (userOne.getBank() <= 0) {
		ui.rollButton->setEnabled(false);
		ui.rollButton->setText("Ran out of Money!");
	}

	int amountWins = userOne.getWins();
	int amountLosses = userOne.getLosses();
	float bankAmount = userOne.getBank();
	
	// updates the bank value, how many wins and losses the user has gotten:
	ui.labelWinsValueUI->setText(QString::number(amountWins));
	ui.labelLossesValueUI->setText(QString::number(amountLosses));
	ui.currentBankValueUI->setText(QString::number(bankAmount));

	bFirstRoll = true;
}

