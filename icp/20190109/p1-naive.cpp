#include <iostream>

int main() {

  int a, b, c;

  while(std::cin >> a >> b >> c) {
    int answer = 1;
    for(int i=1; i<=b; i++) {
	  	answer = (answer*a)%c;
    }
    std::cout << answer << '\n';
  }

  return 0;
}

