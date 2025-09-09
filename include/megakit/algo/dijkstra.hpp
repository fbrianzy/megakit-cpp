#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <utility>

namespace megakit::algo {
  struct Edge { int to; int w; };

  inline std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& g, int src) {
    const int n = (int)g.size();
    const int INF = std::numeric_limits<int>::max()/4;
    std::vector<int> dist(n, INF);
    using P = std::pair<int,int>; // (dist, node)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[src] = 0; pq.emplace(0, src);
    while(!pq.empty()) {
      auto [d,u] = pq.top(); pq.pop();
      if (d != dist[u]) continue;
      for (auto e : g[u]) {
        if (dist[e.to] > d + e.w) {
          dist[e.to] = d + e.w;
          pq.emplace(dist[e.to], e.to);
        }
      }
    }
    return dist;
  }
}
