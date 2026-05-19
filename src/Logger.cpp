#include "Logger.h"
#include <QDateTime>
Logger& Logger::instance(){ static Logger i; return i; }
void Logger::open(const QString& log,const QString& dat){ file.setFileName(log); file.open(QIODevice::Append|QIODevice::WriteOnly); datPath=dat; }
void Logger::log(const QString& m){ file.write((QString("[")+QDateTime::currentDateTime().toString()+"] "+m+"
").toUtf8()); file.flush(); }
void Logger::start(){ timer.start(); m_data.launchCount++; log("START"); }
void Logger::stop(){ long long s=timer.elapsed()/1000; m_data.usageSeconds+=s; log(QString("STOP %1s").arg(s)); m_data.save(datPath); }
