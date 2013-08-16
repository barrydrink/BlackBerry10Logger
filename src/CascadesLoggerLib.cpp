// Created by www.penrillian.com 2013

#include "CascadesLoggerLib.hpp"
#include <QDir>
#include <QDateTime>
#include <Qt/qdeclarativedebug.h>
#include <bb/ApplicationInfo>

bool CascadesLoggerLib::m_loggingToFileEnabled = false;

void myMessageOutput(QtMsgType type, const char *msg) {
	switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "Debug: %s\n", msg);
		break;
		case QtWarningMsg:
		fprintf(stderr, "Warning: %s\n", msg);
		break;
		case QtCriticalMsg:
		fprintf(stderr, "Critical: %s\n", msg);
		break;
		case QtFatalMsg:
		fprintf(stderr, "Fatal: %s\n", msg);
		abort();
		break;
	}
	if(CascadesLoggerLib::m_loggingToFileEnabled) {
		CascadesLoggerLib::sharedInstance()->log(msg);
	}
}

Q_DECL_EXPORT void CascadesLoggerLib::init() {

	QDir logDir(getLoggingDirPath());
	if (logDir.exists()) {
		m_loggingToFileEnabled = true;
	}
	qInstallMsgHandler(myMessageOutput);
}

CascadesLoggerLib::CascadesLoggerLib() {
	qint64 dateTime = QDateTime::currentMSecsSinceEpoch();
	QString number = QString::number(dateTime);
	m_logFile = new QFile(getLoggingDirPath() + "/" + getAppInfo().title() + "_" + number + ".log");
	if (m_logFile->open(QIODevice::WriteOnly)) {
		QTextStream out(m_logFile);
		QDateTime now = QDateTime::currentDateTime();
		out << "Penrillian Logging Library" << "\n\n" << "Created by Penrillian, 2013, http://www.penrillian.com" << "\n\n";
		out << now.toString() << "\n" << "==============================" << "\n\n" << "Start of log..." << "\n";
		m_logFile->close();
	}
}

Q_DECL_EXPORT void CascadesLoggerLib::log(QString msg, QString tag) {
	m_mutex.lock();

	if (m_logFile->open(QIODevice::WriteOnly | QIODevice::Append)) {
		QTime now = QTime::currentTime();
		QTextStream out(m_logFile);
		out << now.toString("hh:mm:ss:zzz") << "\t"	<< (tag.isEmpty() ? "" : tag + "\t") << msg << "\n";
		m_logFile->close();
	}

	m_mutex.unlock();
}

Q_DECL_EXPORT CascadesLoggerLib* CascadesLoggerLib::sharedInstance() {
	static CascadesLoggerLib instance;
	return &instance;
}

const QString& CascadesLoggerLib::getLoggingDirPath()
{
	static QString loggingDirPath(QDir::currentPath() + "/shared/documents/" + getAppInfo().title());
	return loggingDirPath;
}

const bb::ApplicationInfo& CascadesLoggerLib::getAppInfo()
{
	static bb::ApplicationInfo appInfo;
	return appInfo;
}
