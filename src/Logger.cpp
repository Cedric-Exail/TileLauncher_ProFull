
#include "Logger.h"
#include <QDateTime>
#include <QMutex>

Logger& Logger::instance(){ static Logger i; return i; }

void Logger::open(const QString& log, const QString& dat){
 m_log.setFileName(log);
 m_log.open(QIODevice::Append | QIODevice::WriteOnly);
 m_data = AppData::load(dat);
 m_dat = dat;
}

void Logger::log(const QString& msg){
 QByteArray l = QString("[%1] %2
").arg(QDateTime::currentDateTime().toString(), msg).toUtf8();
 m_log.write(l);
 m_log.flush();
}

void Logger::launch(){
 m_data.launchCount++;
 m_data.save(m_dat);
 log("Application started");
}
