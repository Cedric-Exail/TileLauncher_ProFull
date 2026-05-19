#include <QApplication>
#include <QPushButton>
#ifdef _WIN32
#include <windows.h>
#endif
int main(int argc,char** argv){
 QApplication a(argc,argv);
 QPushButton b("TileLauncher PRO"); b.resize(300,100); b.show();
#ifdef _WIN32
 RegisterHotKey(NULL,1,MOD_CONTROL|MOD_ALT,VK_SPACE);
#endif
 return a.exec(); }
