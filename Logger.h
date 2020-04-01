#pragma once
#include <QWidget>
#include <QTextBrowser>
#include <QCoreApplication>
class Logger {

public:
	static Logger *getInstance();
	void write(const QString & msg, bool forceEmit = false);
	void error(const QString & msg, bool forceEmit = false);
	void set(QTextBrowser* l);
private:
	QTextBrowser* log;
	static Logger* logger;

};



