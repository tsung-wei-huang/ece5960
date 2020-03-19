#include <iostream>
#include <chrono>
#include <vector>

int V, E, S, T;

// a structure to represent a weighted edge in graph 
struct Edge {
  int u, v, w;
};

using Graph = std::vector<std::vector<Edge>>;

// TODO

// compute the maximum flow of the graph g
int maxflow(const Graph& g, int src, int tgt) {
  return 0;
}

// compute min s-t cut 
// return cut on s side and cut on t side in a pair of vectors
std::pair<std::vector<int>, std::vector<int>> mincut(const Graph& g, int src, int tgt) {
  std::vector<int> cut_on_s, cut_on_t;
  
  return {cut_on_s, cut_on_t};  
}

// END-TODO


int main() {
  
  Graph graph;

  std::cin >> V >> E >> S >> T;

  graph.resize(V);

  for(int i=0; i<E; ++i) {
    Edge e;
    std::cin >> e.u >> e.v >> e.w;
    graph[e.u].push_back(e);
  }
  
  // Find shortest paths at all nodes starting from 0
  std::cout << "maximum flow: " << maxflow(graph, S, T) << '\n';
  
  std::vector<int> cut_on_s;
  std::vector<int> cut_on_t;

  std::tie(cut_on_s, cut_on_t) = mincut(graph, S, T);

  std::cout << "cut on s side:";
  for(auto c : cut_on_s) {
    std::cout << ' ' << c;
  }
  std::cout << '\n';
  
  std::cout << "cut on t side:";
  for(auto c : cut_on_t) {
    std::cout << ' ' << c;
  }
  std::cout << '\n';

  return 0;
}




