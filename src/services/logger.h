#pragma once
#include <fstream>
#include <chrono>
#include <iomanip>
class Logger{public:static void init(){f.open("launcher.log",std::ios::app);}static void log(const std::string&s){auto t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());f<<std::put_time(std::localtime(&t),"%F %T")<<" | "<<s<<std::endl;}static void close(){f.close();}private:static inline std::ofstream f;};