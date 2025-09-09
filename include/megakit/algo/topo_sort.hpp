#pragma once
#include <vector>
#include <queue>

namespace megakit::algo {
  inline std::vector<int> topo_sort_kahn(const std::vector<std::vector<int>>& g) {
    int n = (int)g.size();
    std::vector<int> indeg(n,0);
    for (int u=0; u<n; ++u) for (int v: g[u]) ++indeg[v];
    std::queue<int> q;
    for (int i=0; i<n; ++i) if (!indeg[i]) q.push(i);
    std::vector<int> order;
    while(!q.empty()) {
      int u=q.front(); q.pop();
      order.push_back(u);
      for (int v: g[u]) if (--indeg[v]==0) q.push(v);
    }
    return order;
  }
}
