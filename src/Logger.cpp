#include "Logger.h"
#include <QDateTime>

Logger& Logger::instance()
{
    static Logger inst;
    return inst;
}

void Logger::open(const QString& log, const QString& dat)
{
    file.setFileName(log);
    file.open(QIODevice::Append | QIODevice::WriteOnly);
    datPath = dat;
}

void Logger::log(const QString& message)
{
    QString line = QString("[%1] %2\n")
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
        .arg(message);

    file.write(line.toUtf8());
    file.flush();
}

void Logger::start()
{
    timer.start();
    m_data.launchCount++;
    log("START");
}

void Logger::stop()
{
    qint64 secs = timer.elapsed() / 1000;
    m_data.usageSeconds += secs;

    log(QString("STOP %1 seconds").arg(secs));
    m_data.save(datPath);
}
