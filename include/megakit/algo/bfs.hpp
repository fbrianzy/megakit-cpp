#pragma once
#include <vector>
#include <queue>
#include <limits>

namespace megakit::algo {
  // BFS for unweighted graph; returns distance from src (or INF if unreachable)
  inline std::vector<int> bfs(const std::vector<std::vector<int>>& g, int src) {
    const int n = (int)g.size();
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(n, INF);
    std::queue<int> q;
    dist[src] = 0; q.push(src);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : g[u]) if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
    return dist;
  }
}
