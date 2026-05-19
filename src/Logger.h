
#include <QFile>
#include "AppData.h"
class Logger{
public:
 static Logger& instance();
 void open(const QString&,const QString&);
 void log(const QString&);
 void launch();
 AppData m_data;
private:
 QFile m_log; QString m_dat;
};
