#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

// number of elements
int N; 

// number of queries
int Q;

// array of elements
std::vector<int> array;

// Naive linear method
int find_sum_naive(int beg, int end) {
  int s = 0;
  for(int i=beg; i<=end; ++i) {
    s+=array[i];
  }
  return s;
}

// TODO: implement the find_sum using sparse table and binary indexed tree
int find_sum_st(int beg, int end) {
  return 0;
}

int find_sum_bit(int beg, int end){
  return 0;
}
// END-TODO 

int main() {

  array.clear();

  std::cin >> N >> Q;

  for(int i=0; i<N; ++i) {
    int element;
    std::cin >> element;
    array.push_back(element);
  }

  for(int i=0; i<Q; ++i) {
    int beg, end;
    std::cin >> beg >> end;
    // TODO: comment out ther other two methods when measuring the runtime
    // of a method
    // You may use linux command, "time -p ./a.out < test.txt", to measure
    // the runtime of the program. Replace test.txt accordingly
    std::cout << "sum by naive method: " << find_sum_naive(beg, end) << '\n';
    std::cout << "sum by sparse table: " << find_sum_st(beg, end) << '\n';
    std::cout << "sum by binary indexed tree: " << find_sum_bit(beg, end) << '\n';
  }

}








