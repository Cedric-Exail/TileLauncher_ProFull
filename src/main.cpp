#include <QApplication>
#include "TileLauncher.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    TileLauncher w;
    w.show();

#ifdef _WIN32
    RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_ALT, VK_SPACE);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_HOTKEY) {
            w.show();
            w.raise();
        }
    }
#endif

    return app.exec();
}
