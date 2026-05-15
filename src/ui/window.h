#pragma once
#include <windows.h>
class Window{public:bool init(HINSTANCE);int loop();private:static LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);void render();HWND hwnd;};