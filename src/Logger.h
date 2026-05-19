#pragma once
#include <QFile>
#include <QString>
#include <QElapsedTimer>
#include "AppData.h"
class Logger{
public:
 static Logger& instance();
 void open(const QString&,const QString&);
 void log(const QString&);
 void start();
 void stop();
 AppData& data(){return m_data;} 
private:
 QFile file;
 QString datPath;
 QElapsedTimer timer;
 AppData m_data;
};
