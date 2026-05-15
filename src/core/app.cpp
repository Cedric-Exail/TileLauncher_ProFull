#include "app.h"
#include "../ui/window.h"
#include "../services/logger.h"
#include "../services/runtime.h"
int App::run(HINSTANCE h){Logger::init();Runtime::start();Logger::log("START total="+std::to_string(Runtime::total()));Window w;w.init(h);int r=w.loop();Runtime::stop();Logger::log("STOP total="+std::to_string(Runtime::total()));Logger::close();return r;}