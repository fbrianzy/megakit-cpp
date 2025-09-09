#include <iostream>
#include <random>
#include "megakit/io/argparse.hpp"
#include "megakit/algo/dijkstra.hpp"
#include "megakit/algo/bfs.hpp"
#include "megakit/algo/topo_sort.hpp"
#include "megakit/algo/kmp.hpp"
#include "megakit/ds/disjoint_set.hpp"
#include "megakit/math/gcd.hpp"
#include "megakit/math/sieve.hpp"
#include "megakit/utils/timer.hpp"

using namespace megakit;

void cmd_graph_dijkstra(io::ArgParse& ap){
  int n = ap.get_int("n", 5);
  int m = ap.get_int("m", 10);
  int src = ap.get_int("src", 0);
  std::vector<std::vector<algo::Edge>> g(n);
  std::mt19937 rng(42);
  std::uniform_int_distribution<int> U(1, 9);
  for(int i=0;i<m;++i){
    int u = i % n;
    int v = (i*7 + 3) % n;
    if(u==v) v = (v+1)%n;
    int w = U(rng);
    g[u].push_back({v,w});
  }
  auto d = algo::dijkstra(g, src);
  std::cout << "Dijkstra distances from src=" << src << "\n";
  for(int i=0;i<n;++i) std::cout << "  " << i << " -> " << d[i] << "\n";
}

void cmd_graph_bfs(io::ArgParse& ap){
  int n = ap.get_int("n", 6);
  int m = ap.get_int("m", 8);
  int src = ap.get_int("src", 0);
  std::vector<std::vector<int>> g(n);
  for(int i=0;i<m;++i){
    int u = i % n;
    int v = (i*5 + 1) % n;
    if(u!=v) g[u].push_back(v), g[v].push_back(u);
  }
  auto d = algo::bfs(g, src);
  std::cout << "BFS distances from src=" << src << "\n";
  for(int i=0;i<n;++i) std::cout << "  " << i << " -> " << (d[i]==std::numeric_limits<int>::max()? -1 : d[i]) << "\n";
}

void cmd_strings_kmp(io::ArgParse& ap){
  auto text = ap.get("text").value_or("ababcabcabababd");
  auto pat  = ap.get("pat").value_or("ababd");
  auto pos = algo::kmp_search(text, pat);
  std::cout << "KMP positions for '" << pat << "' in text: ";
  for(size_t i=0;i<pos.size();++i) std::cout << pos[i] << (i+1<pos.size()? ", ":"");
  std::cout << (pos.empty()? "(none)":"") << "\n";
}

void cmd_math(io::ArgParse& ap){
  long long a = ap.get_int("a", 24);
  long long b = ap.get_int("b", 36);
  auto g = math::gcd(a,b);
  auto l = math::lcm(a,b);
  auto primes = math::sieve(50);
  std::cout << "gcd("<<a<<","<<b<<")="<<g<<", lcm="<<l<<"\nprimes up to 50: ";
  for(size_t i=0;i<primes.size();++i) std::cout << primes[i] << (i+1<primes.size()? ", ":"");
  std::cout << "\n";
}

int main(int argc, char** argv){
  io::ArgParse ap(argc, argv);
  if (ap.pos.empty() || ap.pos[0] == "--help" || ap.kv.count("help")) {
    std::cout << "megakit_cli usage:\n"
                 "  megakit_cli graph dijkstra [--n N --m M --src S]\n"
                 "  megakit_cli graph bfs [--n N --m M --src S]\n"
                 "  megakit_cli strings kmp [--text TXT --pat PAT]\n"
                 "  megakit_cli math [--a A --b B]\n";
    return 0;
  }
  if (ap.pos.size() >= 2 && ap.pos[0] == "graph" && ap.pos[1] == "dijkstra") { cmd_graph_dijkstra(ap); return 0; }
  if (ap.pos.size() >= 2 && ap.pos[0] == "graph" && ap.pos[1] == "bfs") { cmd_graph_bfs(ap); return 0; }
  if (ap.pos.size() >= 2 && ap.pos[0] == "strings" && ap.pos[1] == "kmp") { cmd_strings_kmp(ap); return 0; }
  if (ap.pos.size() >= 1 && ap.pos[0] == "math") { cmd_math(ap); return 0; }
  std::cerr << "Unknown command. Use --help.\n";
  return 1;
}
