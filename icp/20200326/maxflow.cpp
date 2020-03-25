#include <iostream>
#include <chrono>
#include <vector>

#define MAX_N 100

int V, E, S, T;

// a structure to represent a weighted edge in graph 
struct Edge {
  int u, v, c;
};

using Graph = std::vector<std::vector<Edge>>;

// TODO: implement the push-relabel algorithm to find the max flow

// compute the maximum flow of the graph g
int maxflow(const Graph& g, int src, int tgt) {

  // you may convert the graph to adjacency matrix, 
  // assume the maximum number of nodes is no larger than 100
  // adjacency matrix makes it easier to compute residual flow

  int residual[MAX_N][MAX_N];

  return 0;
}

// END-TODO


int main() {
  
  Graph graph;

  std::cin >> V >> E >> S >> T;

  graph.resize(V);

  for(int i=0; i<E; ++i) {
    Edge e;
    std::cin >> e.u >> e.v >> e.c;
    graph[e.u].push_back(e);
  }
  
  // Find shortest paths at all nodes starting from 0
  std::cout << "maximum flow: " << maxflow(graph, S, T) << '\n';
  
  return 0;
}




