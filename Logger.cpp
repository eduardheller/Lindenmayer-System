#include "Logger.h"

Logger* Logger::logger = nullptr;

Logger * Logger::getInstance()
{
	if (!logger) {
		logger = new Logger();
	}
	return logger;
}

void Logger::write(const QString & msg, bool forceEmit)
{
	log->append("<font color='green'>"+ msg + "</font>\n");
	if (forceEmit)
		QCoreApplication::processEvents();
}

void Logger::error(const QString & msg, bool forceEmit)
{
	log->append("<font color='red'>" + msg + "</font>\n");
	if (forceEmit)
		QCoreApplication::processEvents();
}

void Logger::set(QTextBrowser * l)
{
	log = l;
}
