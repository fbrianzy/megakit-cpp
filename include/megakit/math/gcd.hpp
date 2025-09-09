#pragma once
#include <cstdint>

namespace megakit::math {
  inline std::int64_t gcd(std::int64_t a, std::int64_t b){
    while(b){ auto t=a%b; a=b; b=t; }
    return a<0?-a:a;
  }
  inline std::int64_t lcm(std::int64_t a, std::int64_t b){
    if(a==0 || b==0) return 0;
    return (a / gcd(a,b)) * b;
  }
}
