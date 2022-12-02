#include <bits/stdc++.h>

struct timer
{
    std::chrono::_V2::system_clock::time_point t1, t2;
    timer() : t1(std::chrono::high_resolution_clock::now()) {}
    ~timer()
    {
        t2 = std::chrono::high_resolution_clock::now();
        long double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        duration /= 1e6;
        std::cerr << std::setprecision(3) << "\nTime elapsed: " << duration << "s.\n";
    }
} __t;