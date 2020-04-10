#pragma once

#include <QtWidgets/QDialog>
#include "ui_craps_ui.h"

class craps_ui : public QDialog
{
	Q_OBJECT

public:
	craps_ui(QWidget *parent = Q_NULLPTR);
	void updateUI(bool bGameWon);

private:
	Ui::craps_uiClass ui;

private slots:
	void on_rollButton_clicked();
};
