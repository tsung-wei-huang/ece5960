#include <iostream>
#include <algorithm> 
#include <cmath>
#include <vector>

int main( void ) {

  int N;

  while(std::cin >> N) {
    // TODO
    int number;
    bool is_jolly = false;

    for(int i=0; i<N; ++i) {
      std::cin >> number;
    }
    std::cout << (is_jolly ? "Jolly" : "Not jolly") << '\n';
    // ENDTODO
  }

	return 0 ;
}


