#include "floorplan.h"
#include "test.h"

// Function: main
// The main function of the floorplan.
int main(int argc, char *argv[]) {

  assert(argc == 3);

  floorplan(argv[1], argv[2]);
   
  test(argv[1]);

  return 0;
}
