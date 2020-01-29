#include <iostream>
#include <string>
#include <stack>

using namespace std; 
  
char findClosing(char c) 
{ 
    if (c == '(') 
        return ')'; 
    if (c == '{') 
        return '}'; 
    if (c == '[') 
        return ']'; 
    return -1; 
} 


// TODO:
// function to check_recursion if parenthesis are 
// balanced. 
bool check_recursion(const char* expr, size_t n) 
{ 
  return true;
} 
// END-TODO

// TODO
bool check_stack(const char* expr, size_t len) {
  return true;
}
// END-TODO
  
// Driver program to test above function 
int main() { 
  
  // study the std::string at:
  // https://en.cppreference.com/w/cpp/string/basic_string
  std::string expression;

  while(std::cin >> expression){
    // TODO: comment one to switch between stack and recursion versions
    if (check_stack(expression.data(), expression.size())) {
    //if (check_recursion(expression.data(), expression.size())) {
      cout << "valid\n"; 
    }
    else {
      cout << "invalid\n"; 
    }
    // END-TODO
  }
} 
