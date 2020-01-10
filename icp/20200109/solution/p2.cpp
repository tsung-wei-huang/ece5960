#include <iostream>
#include <algorithm> 
#include <cmath>
#include <vector>

int main( void ) {

  int N;
  std::vector<bool> diff;

  while(std::cin >> N) {

    diff.resize(N);  
    std::fill(diff.begin(), diff.end(), false);

    int prev, curr;
    bool is_jolly = true;
  
    for(int i=0; i<N; ++i) {
      std::cin >> curr;
      if(i > 0) {
        int d = std::abs(curr - prev);
        if(d == 0 || d>=N || diff[d] == true) {
          is_jolly = false;
        }
        diff[d] = true;
      }
      prev = curr;
    }
    std::cout << (is_jolly ? "Jolly" : "Not jolly") << '\n';
  }

	return 0 ;
}


