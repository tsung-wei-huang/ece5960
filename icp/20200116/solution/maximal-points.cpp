#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

// Digest the entire source code
struct Point {

  int x, y;
  
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
  std::uniform_int_distribution<int> dist(1, N);
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
bool dominate(const Point& A, const Point& B) {
  return A.x > B.x && A.y > B.y;
}

// Brute-force solution (freaking slow)
std::vector<Point> brute_force(const std::vector<Point>& S) {

  std::vector<Point> maximal_points;
  
  // Enumerate every pair of point
  for(const auto& A : S) {
    // check if I dominate all
    bool dominate_all {true};
    for(const auto& B : S) {
      if(dominate(B, A)) {
        dominate_all = false;
        break;
      }
    }

    if(dominate_all) {
      maximal_points.push_back(A);
    }
  }

  return maximal_points;
}

// TODO
// Divide and Conquer solution (feel free to create other functions)
// S is already sorted in an increasing order of x
std::vector<Point> dc(const std::vector<Point>& S, int beg, int end) {

  if(!(beg < end)) return {};

  // base case
  if(end - beg == 1) return {S[beg]};

  // recursion
  int m = (beg + end + 1) / 2;
  auto SL = dc(S, beg, m);
  auto SR = dc(S, m, end);

  // find the highest y in SR
  int ymax = std::numeric_limits<int>::min();
  for(const auto& p : SR) {
    ymax = std::max(ymax, p.y);
  }

  // delete all points with y less than ymax from SL
  for(const auto& p : SL) {
    if(ymax > p.y) {
      continue;
    }
    SR.push_back(p);
  }
  
  return SR;
}


std::vector<Point> divide_and_conquer(const std::vector<Point>& S) {
  return dc(S, 0, S.size());
}

int main(int argc, char* argv[]) {
   
  size_t N;

  while(std::cin >> N) {

    // generate a unique set of points
    auto S = generate_points(N);
    
    // turn on the following if you want to see the points
    //show("The Point Set S:", S);
    
    // brute force approach
    auto t1 = std::chrono::steady_clock::now();
    auto P_bf = brute_force(S);
    auto t2 = std::chrono::steady_clock::now();
    auto t_bf = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    
    // TODO: finish the divide_and_conquer approach
    t1 = std::chrono::steady_clock::now();
    auto P_dc = divide_and_conquer(S);
    t2 = std::chrono::steady_clock::now();
    auto t_dc = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    // ENDTODO
    
    // sort the point in x and then y for comparison
    std::sort(P_bf.begin(), P_bf.end(), [](const Point& l, const Point& r) {
      return l.x < r.x;
    });
    
    std::sort(P_dc.begin(), P_dc.end(), [](const Point& l, const Point& r) {
      return l.x < r.x;
    });

    if(P_bf != P_dc) {
      std::cout << "YOUR SOLUTION IS INCORRECT\n";
      show("GOLDEN IS:", P_bf);
      show("YOURS IS:", P_dc);
    }
    else {
      std::cout << "YOUR SOLUTION IS CORRECT\n";
      show("MAXIMAL POINTS:", P_dc);
    }
    
    std::cout << "... brute force finished in " << t_bf << " ms\n"
              << "... divide and conquer finished in " << t_dc << " ms\n";
  }

  return 0;
}


