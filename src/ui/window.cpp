#include "window.h"
#include "../services/logger.h"
static Window* self;
bool Window::init(HINSTANCE h){self=this;WNDCLASS wc={};wc.lpfnWndProc=WndProc;wc.hInstance=h;wc.lpszClassName=L"TileLauncherPro";RegisterClass(&wc);hwnd=CreateWindowEx(0,wc.lpszClassName,L"TileLauncher Pro",WS_OVERLAPPEDWINDOW,100,100,1000,700,nullptr,nullptr,h,nullptr);ShowWindow(hwnd,SW_SHOW);return true;}
void Window::render(){}
int Window::loop(){MSG m={};while(GetMessage(&m,0,0,0)){TranslateMessage(&m);DispatchMessage(&m);}return 0;}
LRESULT CALLBACK Window::WndProc(HWND h,UINT msg,WPARAM w,LPARAM l){switch(msg){case WM_LBUTTONDOWN:Logger::log("CLICK");return 0;case WM_PAINT:self->render();ValidateRect(h,nullptr);return 0;case WM_DESTROY:PostQuitMessage(0);return 0;}return DefWindowProc(h,msg,w,l);} 