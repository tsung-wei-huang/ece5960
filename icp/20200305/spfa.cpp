#include <iostream>
#include <chrono>
#include <vector>

int V, E;

// a structure to represent a weighted edge in graph 
struct Edge {
  int u, v, w;
};

using Graph = std::vector<std::vector<Edge>>;

// TODO
// Bellman-Ford
std::vector<int> BellmanFord(const Graph& g, int src)
{
  std::vector<int> dist(V);

  std::fill_n(dist.begin(), V, INT_MAX);
  
  dist[src] = 0;

  return dist;
}
// END-TODO

// TODO
// SPFA
std::vector<int> SPFA(const Graph& g, int src) {
  std::vector<int> dist(V);
  std::fill_n(dist.begin(), V, INT_MAX);
  
  dist[src] = 0;
  return dist;
}

// END-TODO


int main() {
  
  Graph graph;

  std::cin >> V >> E;

  graph.resize(V);

  for(int i=0; i<E; ++i) {
    Edge e;
    std::cin >> e.u >> e.v >> e.w;
    graph[e.u].push_back(e);
  }
  
  // Find shortest paths at all nodes starting from 0
  auto beg1 = std::chrono::steady_clock::now();
  auto solution_bf = BellmanFord(graph, 0);
  auto end1 = std::chrono::steady_clock::now();

  auto beg2 = std::chrono::steady_clock::now();
  auto solution_spfa = SPFA(graph, 0);
  auto end2 = std::chrono::steady_clock::now();

  assert(solution_bf == solution_spfa);

  std::cout << "BellmanFord: " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(end1-beg1).count() 
            << "ms\n"
            << "SPFA: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end2-beg2).count()
            << "ms\n";

  return 0;
}

