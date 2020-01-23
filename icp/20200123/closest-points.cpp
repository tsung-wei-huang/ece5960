#include <iostream>
#include <cassert>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

// Digest the entire source code
struct Point {

  int x, y;
  
  // default constructor
  Point() = default;

  // default copy constructor
  Point(const Point&) = default;

  // default copy assignment
  Point& operator = (const Point&) = default;
  
  // I want to do pointA == pointB
  bool operator == (const Point& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  
  // I want to do pointA != pointB
  bool operator != (const Point& rhs) const {
    return x != rhs.x || y != rhs.y;
  }
};

// I wan to do std::cout << Point
std::ostream& operator << (std::ostream& os, const Point& rhs) {
  os << '(' << rhs.x << ", " << rhs.y << ')';
  return os;
}

// Randomly generate a set of 2D points sorted in increasing
// order of x
std::vector<Point> generate_points(size_t N) {
  std::default_random_engine eng(0);
  std::uniform_int_distribution<int> dist(1, 65536);
  std::vector<Point> points(N);
  for(size_t i=0; i<N; ++i) {
    points[i].x = i;
    points[i].y = dist(eng);
  }
  return points;
} 

// prints the points to standard out
void show(const std::string& msg, const std::vector<Point>& S) {
  std::cout << msg << '\n';
  for(const auto& p : S) {
    std::cout << p << '\n';
  }
}

// check if A dominates B
float dist(const Point& p1, const Point& p2) {  
  return std::sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  
                    (p1.y - p2.y)*(p1.y - p2.y));  
}  

// Brute-force solution (freaking slow)
float brute_force(const std::vector<Point>& S, int beg, int end) {
  auto min = std::numeric_limits<float>::max();  
  for (int i = beg; i < end; ++i) {
    for (int j = i+1; j < end; ++j) {
      if (dist(S[i], S[j]) < min) {
        min = dist(S[i], S[j]); 
      }
    }
  }
  return min;  
}

// TODO: closest point pair in a strip
float closest_dist_on_strip(std::vector<Point>& strip, float D) {
  
  float min = D;
  
  // sort the strip points in ascending order of y
  // check https://en.cppreference.com/w/cpp/algorithm/sort
  std::sort(strip.begin(), strip.end(), [] (const Point& p1, const Point& p2) {
    return p1.y < p2.y;
  });

  // find the minimum distance in the strip

  return min;
}
// END-TODO

// TODO: finish the closest point pair problem using divide and conquer
float divide_and_conquer(const std::vector<Point>& S, int beg, int end) {
  return 0f;
}
// END-TODO

// Main function
int main(int argc, char* argv[]) {
   
  size_t N;

  while(std::cin >> N) {

    assert(N >= 2);

    // generate a unique set of points
    auto S = generate_points(N);
    
    // turn on the following if you want to see the points
    //show("The Point Set S:", S);
    
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
    if(std::fabs(D_bf - D_dc) > 1e-4f) {
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


