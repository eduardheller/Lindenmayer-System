#include "dlgProduction.h"
#include "ui_addproduction.h"


dlgProduction::dlgProduction(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::dlgProduction)
{
	ui->setupUi(this);
	QObject::connect(ui->btnBox, SIGNAL(accepted()), this, SLOT(add()));
	setWindowIcon(QIcon(":/images/icon.ico"));
}

dlgProduction::~dlgProduction()
{
	delete ui;
}

QString dlgProduction::getRule()
{
	return rule;
}

QString dlgProduction::getProduction()
{
	return production;
}

QString dlgProduction::getChance()
{
	return chance;
}

void dlgProduction::add()
{
	if(!ui->txtRule->text().isEmpty())
		rule = ui->txtRule->text().at(0);
	production = ui->txtProduction->text();
	chance = QString::number(ui->sBoxChance->value());
}
