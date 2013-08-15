// Created by www.penrillian.com 2013

#ifndef CascadesLoggerLib_HPP_
#define CascadesLoggerLib_HPP_

#include <QString>
#include <QFile>
#include <QMutex>
#include <bb/ApplicationInfo>

class CascadesLoggerLib
{
public:
    virtual ~CascadesLoggerLib(){};

    void log(QString, QString = "");
    static CascadesLoggerLib* sharedInstance();
    static void init();
	static bool m_loggingToFileEnabled;

private:
    QFile* m_logFile;
	CascadesLoggerLib();
	QMutex m_mutex;
	static const QString& getLoggingDirPath();
	static const bb::ApplicationInfo& getAppInfo();
};

#endif /* CascadesLoggerLib_HPP_ */
