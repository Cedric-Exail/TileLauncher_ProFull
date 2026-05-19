#pragma once
#include <QString>
struct AppData{
 long long launchCount=0;
 long long usageSeconds=0;
 static AppData load(const QString&){ return {}; }
 bool save(const QString&) const { return true; }
};
