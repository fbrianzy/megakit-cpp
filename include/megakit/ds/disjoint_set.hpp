#pragma once
#include <vector>

namespace megakit::ds {
  struct DisjointSet {
    std::vector<int> p, r;
    explicit DisjointSet(int n): p(n), r(n,0) { for (int i=0;i<n;++i) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a, int b){
      a=find(a); b=find(b);
      if(a==b) return false;
      if(r[a]<r[b]) std::swap(a,b);
      p[b]=a;
      if(r[a]==r[b]) ++r[a];
      return true;
    }
  };
}
