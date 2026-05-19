#include "TileLauncher.h"
#include <QGridLayout>
#include <QPushButton>
#include <QProcess>
#include "Logger.h"
TileLauncher::TileLauncher(){ Logger::instance().start(); auto*g=new QGridLayout(this);
QStringList cmds={"C:/Windows/explorer.exe","C:/Windows/notepad.exe","C:/Windows/System32/calc.exe","C:/Windows/System32/cmd.exe","C:/Windows/System32/control.exe","C:/Windows/System32/taskmgr.exe","C:/Windows/regedit.exe","C:/Windows/System32/WindowsPowerShell/v1.0/powershell.exe"};
for(int i=0;i<cmds.size();++i){auto*b=new QPushButton(cmds[i]);g->addWidget(b,i/4,i%4);QObject::connect(b,&QPushButton::clicked,[cmds,i](){QProcess::startDetached(cmds[i]);});}}
TileLauncher::~TileLauncher(){ Logger::instance().stop(); }
