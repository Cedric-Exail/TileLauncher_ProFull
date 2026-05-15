#pragma once
#include <fstream>
#include <chrono>
class Runtime{public:static void start(){t0=std::chrono::steady_clock::now();std::ifstream f("runtime.dat");if(f)f>>tot;}static void stop(){auto d=std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now()-t0).count();tot+=d;std::ofstream f("runtime.dat");f<<tot;}static long total(){return tot;}private:static inline std::chrono::steady_clock::time_point t0;static inline long tot=0;};