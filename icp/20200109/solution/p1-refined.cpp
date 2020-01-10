#include <iostream>

#define SQUARE(x) (x*x)

int64_t bigmod(int64_t a, int64_t b, int64_t c) {
  if(b==0) {
    return 1;
  }
  else if(b%2==0) {
    return SQUARE(bigmod(a,b/2,c))%c;
  }
  else {
    return ((a%c)*bigmod(a,b-1,c))%c;
  }
}

int main() {
  int64_t a, b, c;
  while(std::cin >> a >> b >> c) {
    std::cout << bigmod(a, b, c) << '\n';
  }
  return 0;
}

