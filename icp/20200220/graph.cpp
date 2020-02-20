#include <iostream>
#include <vector>
#include <stack>
#include <queue>

// Assume the following graph
// 0-> { 1 7 8 4}
// 1-> { 5 4 2 }
// 2-> { 4 8 6 3 1 5 }
// 3-> { 5 4 7 2 }
// 4-> { 2 3 7 1 8 5 }
// 5-> { 3 1 7 4 2 8 }
// 6-> { 2 8 7 }
// 7-> { 4 3 5 6 }
// 8-> { 2 6 4 5 }

std::vector<std::vector<int>> graph = {
  {1, 7, 8, 4},
  {5, 4, 2},
  {4, 8, 6, 3, 1, 5},
  {5, 4, 7, 2},
  {2, 3, 7, 1, 8, 5},
  {3, 1, 7, 4, 2, 8},
  {2, 8, 7},
  {4, 3, 5, 6},
  {2, 6, 4, 5}
};

// TODO: print out the DFS order (using stack)
void dfs_stack() {
}
// END-TODO

// TODO: print out the DFS order (using recursion)
void dfs_recursion() {
}
// END-TODO

// TODO: print out the BFS order 
void bfs() {
}
// END-TODO

int main() {
  
  std::cout << "DFS (iterative):\n";
  dfs_stack();
  std::cout << "DFS (recursive):\n";
  dfs_recursion();
  
  std::cout << "BFS: \n";
  bfs();

  return 0;
}






