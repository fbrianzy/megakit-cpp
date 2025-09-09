#include <vector>
#include "test_util.hpp"
#include "megakit/algo/bfs.hpp"
#include "megakit/algo/dijkstra.hpp"

TEST_CASE(test_bfs_basic){
  std::vector<std::vector<int>> g(3);
  g[0] = {1};
  g[1] = {0,2};
  g[2] = {1};
  auto d = megakit::algo::bfs(g, 0);
  REQUIRE(d[2] == 2);
}

TEST_CASE(test_dijkstra_nonneg){
  std::vector<std::vector<megakit::algo::Edge>> g(3);
  g[0].push_back({1, 5});
  g[1].push_back({2, 4});
  auto d = megakit::algo::dijkstra(g, 0);
  REQUIRE(d[2] == 9);
}
