#include <iostream>
#include <cstring>
#include <cassert>

// without tabular method
int hanoi_naive(int n) {
  if(n == 1) return 1;
  return hanoi_naive(n-1) + hanoi_naive(n-1) + 1;
}


// TODO
int memo[31];
int hanoi(int n) {
  return 0;
}

int main() {
  
  // assume n is no large than 30
  int n;
  
  std::memset(memo, 0, 31*sizeof(int));
  
  while(std::cin >> n){

    assert(n > 0 && n < 31);

    // compute the hanoi number without tabular method
    std::cout << hanoi_naive(n) << '\n';

    // TODO: turn on the following after you finish the 
    // function hanoi with tabular method
    //std::cout << hanoi(n) << '\n';
  }

}
