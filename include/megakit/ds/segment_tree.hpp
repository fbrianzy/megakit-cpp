#pragma once
#include <vector>
#include <limits>

namespace megakit::ds {
  struct SegmentTree {
    int n;
    std::vector<long long> t;
    explicit SegmentTree(int n): n(n), t(4*n, 0) {}
    void build(const std::vector<long long>& a, int v, int tl, int tr){
      if(tl==tr) t[v]=a[tl];
      else{
        int tm=(tl+tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
      }
    }
    void build(const std::vector<long long>& a){ build(a,1,0,n-1); }
    long long sum(int v,int tl,int tr,int l,int r){
      if(l>r) return 0;
      if(l==tl && r==tr) return t[v];
      int tm=(tl+tr)/2;
      return sum(v*2, tl, tm, l, std::min(r,tm)) + sum(v*2+1, tm+1, tr, std::max(l,tm+1), r);
    }
    long long sum(int l,int r){ return sum(1,0,n-1,l,r); }
    void update(int v,int tl,int tr,int pos,long long val){
      if(tl==tr) t[v]=val;
      else{
        int tm=(tl+tr)/2;
        if(pos<=tm) update(v*2, tl, tm, pos, val);
        else update(v*2+1, tm+1, tr, pos, val);
        t[v]=t[v*2]+t[v*2+1];
      }
    }
    void update(int pos,long long val){ update(1,0,n-1,pos,val); }
  };
}
