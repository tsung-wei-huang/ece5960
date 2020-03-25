#include <iostream>
#include <chrono>
#include <vector>

#define MAX_N 100

int V, E, S, T;

// a structure to represent a weighted edge in graph 
struct Edge {
  int u, v, c, w;  //u->v with capacity c and per-unit flow cost w
};

using Graph = std::vector<std::vector<Edge>>;

// TODO: implement the push-relabel algorithm to find the max flow

// compute the min cost flow of the graph g
// return a pair of max flow value and cost value
std::pair<int, int> mincost_flow(const Graph& g, int src, int tgt) {

  // you may convert the graph to adjacency matrix, 
  // assume the maximum number of nodes is no larger than 100
  // adjacency matrix makes it easier to compute residual flow

  int residual[MAX_N][MAX_N];

  return {0, 0};
}

// END-TODO


int main() {
  
  Graph graph;

  std::cin >> V >> E >> S >> T;

  graph.resize(V);

  for(int i=0; i<E; ++i) {
    Edge e;
    std::cin >> e.u >> e.v >> e.c >> e.w;
    graph[e.u].push_back(e);
  }
  
  // Find shortest paths at all nodes starting from 0
  std::pair<int, int> res;
  res = mincost_flow(graph, S, T);
  std::cout << "maximum flow: " << res.first << '\n'
            << "minimum cost: " << res.second << '\n';
  
  return 0;
}




