#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <float.h>
#include "tLib_graphics.h"

#ifndef FLOORPLAN_H_
#define FLOORPLAN_H_

#define FROZEN 0.00001
#define TEMPERATURE_DECREASING_RATE 0.9
#define MAX_NUM_RAND_STEPS 2000
#define MIN(x, y) x < y ? x : y;
#define MAX(x, y) x > y ? x : y;

//-------------------------------------------------------------------------------------------------
// Definition field of enum and struct.

typedef enum CUTLINE {                                      // Cutline type.
  V = 0,
  H = 1,
  UNDEFINED_CUTLINE
}cutline_t;

typedef struct MODULE {                                     // Module struct.
  int idx;
  int llx, lly;
  int w, h;
}module_t;

typedef struct EXPRESSION_UNIT {                            // Expression struct.
  module_t* module;
  cutline_t cutline;
}expression_unit_t;

typedef struct NODE {                                       // Slicing tree struce.
  module_t* module;
  cutline_t cutline;
  struct NODE* parent;
  struct NODE* left;
  struct NODE* right;
}node_t;

typedef struct CLUSTER {                                    // Cluster of module.
  int beg, end;
  int w, h;
}cluster_t;

//-------------------------------------------------------------------------------------------------
// Definition of functions.

void floorplan(const char [], const char []);               // Major subroutine of floorplan.
void read_modules(const char []);                           // Read the modules.
void draw_modules(const char []);                           // Draw the module.
void get_expression(node_t*, int, expression_unit_t*);      // Get the expression.
void pnt_expression(expression_unit_t *, int);              // Print the expression.
void pnt_modules();                                         // Display the module coordinates.
void write_modules(const char []);                          // Write the module into a file.
void postfix_traversal(node_t*, int*, expression_unit_t*);  // Postfix tree traversal.
void rotate(node_t*);                                       // Rotate the module.
void recut(node_t*);                                        // Change the cutline.
void swap_topology(node_t*, node_t*);                       // Swap the topology.
void swap_module(node_t*, node_t*);                         // Swap the module.
double optimize(node_t*, int);                              // Optimize the floorplan.
double packing(expression_unit_t*, int);                    // Packing.
int is_overlapped();                                        // Check if modules have overlap.
int is_internal_node(node_t*);                              // Check if is a internal node.
int is_leaf_node(node_t*);                                  // Check if is a leaf node.
int is_in_subtree(node_t*, node_t*);                        // Check the subtree statue.
int is_valid_expression(expression_unit_t*, int);           // Check if the expression is valid.
node_t* init_slicing_tree(node_t*, int);                    // Initialize the tree.
node_t* challenge_init_slicing_tree();                      // Initialize the tree.
node_t* challenge_init_slicing_tree(node_t*, int);          // Initialize the tree.
module_t* get_module(int);                                  // Get the module pointer.



#endif
