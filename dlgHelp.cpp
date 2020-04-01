#include "dlgHelp.h"
#include "ui_help.h"


dlgHelp::dlgHelp(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dlgHelp)
{
	ui->setupUi(this);
	setWindowIcon(QIcon(":/images/icon.ico"));
}

dlgHelp::~dlgHelp()
{
	delete ui;
}
