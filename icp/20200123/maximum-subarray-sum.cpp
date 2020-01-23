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
  std::uniform_int_distribution<int> dist(-100, 100);
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

// Brute-force solution (freaking slow)
int brute_force(const std::vector<int>& D, int beg, int end) {
  int max = std::numeric_limits<int>::min();  
  for (int i = beg; i < end; ++i) {
    int sum = 0;
    for (int j = i; j < end; ++j) {
      sum += D[j];
      max = std::max(sum, max);
    }
  }
  return max;  
}

// TODO: finish the divide and conquer approach for finding
// the maximum subarray sum
int max_subarray_sum_with_m(
  const std::vector<int>& S, int beg, int end, int m
) {

  assert(beg < m && m < end);

  return 0;
}

int divide_and_conquer(const std::vector<int>& S, int beg, int end) {
  return 0;
}
// END-TODO

// Main function
int main(int argc, char* argv[]) {
   
  size_t N;

  while(std::cin >> N) {

    assert(N >= 2);

    // generate a unique set of points
    auto S = generate_data(N);
    
    // turn on the following if you want to see the points
    //show(S);
    
    // brute force approach
    auto t1 = std::chrono::steady_clock::now();
    auto D_bf = brute_force(S, 0, S.size());
    auto t2 = std::chrono::steady_clock::now();
    auto t_bf = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // divide and conquer approach
    t1 = std::chrono::steady_clock::now();
    auto D_dc = divide_and_conquer(S, 0, S.size());
    t2 = std::chrono::steady_clock::now();
    auto t_dc = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // sort the point in x and then y for comparison
    if(D_bf != D_dc) {
      std::cout << "YOUR SOLUTION IS INCORRECT ("
                << "GOLDEN IS: " << D_bf << ", "
                << "YOURS  IS: " << D_dc << ")\n";
    }
    else {
      std::cout << "YOUR SOLUTION IS CORRECT - "
                << "CLOSEST DISTANCE IS: " << D_dc << '\n';
    }
    
    std::cout << "... brute force finished in " << t_bf << " ms\n"
              << "... divide and conquer finished in " << t_dc << " ms\n";
  }

  return 0;
}


