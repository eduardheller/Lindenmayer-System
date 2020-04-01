#pragma once

#include <QDialog>
#include <string>

namespace Ui {
	class dlgProduction;
}

class dlgProduction : public QDialog
{
	Q_OBJECT

public:
	explicit dlgProduction(QWidget *parent = 0);
	~dlgProduction();

	QString getRule();
	QString getProduction();
	QString getChance();

public slots:
	void add();

private:
	Ui::dlgProduction *ui;
	QString rule;
	QString production;
	QString chance;
};

