#pragma once

#include <string>
#include <QWidget>

namespace Ui {
	class dlgHelp;
}

class dlgHelp : public QWidget
{
	Q_OBJECT

public:
	explicit dlgHelp(QWidget *parent = 0);
	~dlgHelp();

private:
	Ui::dlgHelp *ui;
};

#pragma once
