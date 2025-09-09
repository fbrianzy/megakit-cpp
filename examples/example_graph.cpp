#include <iostream>
#include <vector>
#include "megakit/algo/bfs.hpp"
#include "megakit/algo/topo_sort.hpp"

int main(){
  std::vector<std::vector<int>> g(5);
  g[0] = {1,2};
  g[1] = {3};
  g[2] = {3,4};
  g[3] = {};
  g[4] = {};

  auto dist = megakit::algo::bfs(g, 0);
  auto order = megakit::algo::topo_sort_kahn(g);

  std::cout << "BFS dist from 0: ";
  for (auto d: dist) std::cout << (d==std::numeric_limits<int>::max()? -1 : d) << " ";
  std::cout << "\nTopo order: ";
  for (auto v: order) std::cout << v << " ";
  std::cout << "\n";
  return 0;
}
