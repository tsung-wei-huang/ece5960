#include <iostream>
#include <vector>
#include <stack>
#include <queue>

// Assume the following graph
std::vector<std::vector<int>> graph = {
  {1},            // vertex 0
  {0, 2, 3},      // vertex 1
  {1, 4},         // vertex 2
  {1, 4, 5},      // vertex 3
  {2, 3},         // vertex 4
  {3, 6, 7},      // vertex 5
  {5, 7},         // vertex 6
  {5, 6, 8, 9},   // vertex 7
  {7},            // vertex 8
  {7}             // vertex 9
};

// TODO: find the cut vertices
std::vector<int> cut_vertices() {
}
// END-TODO

// TODO: find the cut edges
std::vector<std::pair<int, int>> cut_edges() {
}
// END-TODO

// TODO: find the biconnected components
std::vector<std::vector<int>> biconnected_components() {
}
// END-TODO

int main() {
  
  std::cout << "cut vertices:\n";
  auto cv = cut_vertices();
  for(const auto v : cv) {
    std::cout << v << '\n';
  }

  std::cout << "cut edges\n";
  auto ce = cut_edges();
  for(const auto& pair : ce) {
    std::cout << pair.first << ' ' << pair.second << '\n';
  }

  std::cout << "biconnected components:\n";
  auto components = biconnected_components();
  for(const auto& comp : components) {
    std::cout << "component:";
    for(const auto v : comp) {
      std::cout << ' ' << v;
    }
    std::cout << '\n';
  }

  return 0;
}






