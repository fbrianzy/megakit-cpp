#pragma once
#include <vector>

namespace megakit::math {
  inline std::vector<int> sieve(int n){
    std::vector<bool> is(n+1, true);
    is[0]=is[1]=false;
    for(int p=2;p*p<=n;++p) if(is[p]) for(long long x=1LL*p*p; x<=n; x+=p) is[(int)x]=false;
    std::vector<int> primes;
    for(int i=2;i<=n;++i) if(is[i]) primes.push_back(i);
    return primes;
  }
}
