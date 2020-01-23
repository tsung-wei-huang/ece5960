#include <iostream>
#include <cassert>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

// Randomly generate a set of 2D points sorted in increasing
// order of x
std::vector<int> generate_data(size_t N) {
  std::default_random_engine eng(0);
  std::uniform_int_distribution<int> dist(-10000, 10000);
  std::vector<int> data(N);
  for(size_t i=0; i<N; ++i) {
    data[i] = dist(eng);
  }
  return data;
} 

// show the value of a vector
void show(const std::vector<int>& data) {
  std::cout << "DATA:";
  for(auto d : data) {
    std::cout << ' ' << d;
  }
  std::cout << '\n';
}

// Brute-force solution using selection sort (freaking slow)
void brute_force(std::vector<int>& D, int beg, int end) {
  int max = std::numeric_limits<int>::min();  
  for (int i = beg; i < end; ++i) {
    int min_v = D[i];
    int min_j = i;
    for (int j = i+1; j < end; ++j) {
      if(D[j] < min_v) {
        min_v = D[j];
        min_j = j;
      }
    }
    std::swap(D[i], D[min_j]);
  }
}

// TODO: finish the merge sort function; 
// feel free to create other help functions you need
void merge_sort(std::vector<int>& S, int beg, int end) {

  if(!(beg < end) || end - beg == 1) {
    return;
  }

  int m = (beg + end + 1) / 2;
  merge_sort(S, beg, m);
  merge_sort(S, m, end);
  merge(S, beg, end, m);
}
// END-TODO

// TODO: Finish the sorting using std::sort; 
// this should be a no-brainer, one line of code
void std_sort(std::vector<int>& S, int beg, int end) {
  std::sort(S.begin() + beg, S.begin() + end);
}
// END-TODO

// Main function
int main(int argc, char* argv[]) {
   
  size_t N;

  while(std::cin >> N) {

    assert(N >= 2);

    // generate a unique set of points
    auto D = generate_data(N);
    auto B = D;   // for brute force sort
    auto M = D;   // for merge sort
    auto S = D;   // for std sort
    
    // turn on the following if you want to see the points
    //show(S);
    
    // brute force approach
    auto t1 = std::chrono::steady_clock::now();
    brute_force(B, 0, B.size());
    std::cout << "YOUR BRUTE FORCE SORT IS "
              << (std::is_sorted(B.begin(), B.end()) ? "CORRECT" : "WRONG") 
              << '\n';
    auto t2 = std::chrono::steady_clock::now();
    auto t_bf = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // merge sort approach
    t1 = std::chrono::steady_clock::now();
    merge_sort(M, 0, M.size());
    std::cout << "YOUR MERGE SORT IS "
              << (std::is_sorted(M.begin(), M.end()) ? "CORRECT" : "WRONG") 
              << '\n';
    t2 = std::chrono::steady_clock::now();
    auto t_dc = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // std::sort
    t1 = std::chrono::steady_clock::now();
    std_sort(S, 0, S.size());
    std::cout << "YOUR STD SORT IS "
              << (std::is_sorted(S.begin(), S.end()) ? "CORRECT" : "WRONG") 
              << '\n';
    t2 = std::chrono::steady_clock::now();
    auto t_sd = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // Print the runtime
    std::cout << "... brute force finished in " << t_bf << " ms\n"
              << "... merge sort  finished in " << t_dc << " ms\n"
              << "... std::sort   finished in " << t_sd << " ms\n";
  }

  return 0;
}


