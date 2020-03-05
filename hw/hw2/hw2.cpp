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
std::vector<int> dijkstra(const Graph& g, int src) {
  std::vector<int> dist(V);
  std::fill_n(dist.begin(), V, INT_MAX);
  
  dist[src] = 0;
  return dist;
}

std::vector<int> spfa_queue(const Graph& g, int src) {
  std::vector<int> dist(V);
  std::fill_n(dist.begin(), V, INT_MAX);
  
  dist[src] = 0;
  return dist;
}

std::vector<int> spfa_stack(const Graph& g, int src) {
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
  auto solution_dijkstra = dijkstra(graph, 0);
  auto end1 = std::chrono::steady_clock::now();

  auto beg2 = std::chrono::steady_clock::now();
  auto solution_spfa1 = spfa_queue(graph, 0);
  auto end2 = std::chrono::steady_clock::now();
  
  auto beg3 = std::chrono::steady_clock::now();
  auto solution_spfa2 = spfa_stack(graph, 0);
  auto end3 = std::chrono::steady_clock::now();

  assert(solution_dijkstra == solution_spfa_queue);
  assert(solution_dijkstra == solution_spfa_stack);

  std::cout << "BellmanFord: " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(end1-beg1).count() 
            << "ms\n"
            << "SPFA queue: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end2-beg2).count()
            << "ms\n"
            << "SPFA stack: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end3-beg3).count()
            << "ms\n";

  return 0;
}

