#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <string>

namespace Ui {
class wndMain;
}

class wndMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit wndMain(QWidget *parent = 0);
    ~wndMain();

public slots:
	void generate();
	void addProduction();
	void removeProduction();
	void exportObj();
	void clearCamera();
	void open();
	void save();
	void exit();
	void help();
	void assignBranchTexture();
	void assignLeafTexture();
	void isShadow(bool);
	void isAnimation(bool);
	void isWireframe(bool);

private:
    Ui::wndMain *ui;
};

#endif // MAINWINDOW_H
