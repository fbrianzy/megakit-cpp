#pragma once
#include <chrono>

namespace megakit::utils {
  struct Timer {
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> t0;
    Timer(): t0(clock::now()) {}
    double elapsed_ms() const {
      auto t1 = clock::now();
      return std::chrono::duration<double, std::milli>(t1 - t0).count();
    }
  };
}
