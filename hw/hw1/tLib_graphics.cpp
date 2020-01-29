/******************************************************************************
 *                                                                            *
 * Copyright (c) 2014, Tsung-Wei Huang                                        *
 * University of Illinois at Urbana-Champaign (UIUC), IL, USA.                *
 *                                                                            *
 * All Rights Reserved.                                                       *
 *                                                                            *
 * This program is free software. You can redistribute and/or modify          *
 * it in accordance with the terms of the accompanying license agreement.     *
 * See LICENSE in the top-level directory for details.                        *
 *                                                                            *
 ******************************************************************************/

#include "tLib_graphics.h"

namespace tLib {
namespace Graphics {

// Constructor.
Graphics2D::Graphics2D(const double design_x, const double design_y) {
  
  // Adjust the scale to fit default image size. 
  scale = min(2048/design_x, 2048/design_y);
  
  // Perform the linear scaling to suit with the placement layout.
  img_x = design_x*scale;
  img_y = design_y*scale;

  // Cairo surface.
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, img_x, img_y);

  // Cairo context.
  painter = cairo_create(surface);
  cairo_set_line_width(painter, 10.0/scale);
  cairo_set_source_rgb(painter, 1.0, 1.0, 1.0);             // Default black background.
  cairo_paint(painter);                                     // Set the painter.
  //cairo_set_line_width(painter, 5);						// Default line width.
  
  // Apply the affine transformation: flipping y and scalling x/y.
  //
  //   scale,      0,              0      x
  //  [                             ] * [ y ]
  //       0, -scale, scale*design_y      1
  //
  cairo_matrix_init(&matrix, scale, 0, 0, -scale, 0, scale*design_y);
  cairo_set_matrix(painter, &matrix);
}

// Destructor.
Graphics2D::~Graphics2D() {
  cairo_destroy(painter);
  cairo_surface_destroy(surface);
}

// Function: image_x
double Graphics2D::image_x() const {
  return img_x;
}

// Function: image_y
double Graphics2D::image_y() const {
  return img_y;
}

// Procedure: write_to_png
void Graphics2D::write_to_png(const char file_path[]) {
  cairo_surface_write_to_png(surface, file_path);
}

// Procedure: write_to_png
void Graphics2D::write_to_png(const string &file_path) {
  cairo_surface_write_to_png(surface, file_path.c_str());
}

// Procedure: set_painter_width_color
void Graphics2D::set_painter_width_color(const double w, const double r, const double g, const double b) {
  set_painter_width(w);
  set_painter_color(r, g, b);
}

// Procedure: set_painter_width
void Graphics2D::set_painter_width(const double w) {
  cairo_set_line_width(painter, w);
}

// Procedure: set_painter_color
void Graphics2D::set_painter_color(const double r, const double g, const double b) {
  cairo_set_source_rgb(painter, r, g, b);
}

// Proedure: paint_rectangle
// cairo_move_to(painter, x, y);
// cairo_rel_line_to(painter, dx, 0);
// cairo_rel_line_to(painter, 0, dy);
// cairo_rel_line_to(painter, -dx, 0);
// cairo_close_path(painter);
void Graphics2D::paint_rectangle(const double x, const double y, const double dx, const double dy) {
  cairo_rectangle(painter, x, y, dx, dy);
  cairo_stroke(painter);
}

// Proedure: paint_filled_rectangle
void Graphics2D::paint_filled_rectangle(const double x, const double y, const double dx, const double dy) {
  cairo_rectangle(painter, x, y, dx, dy);
  cairo_fill(painter);
}

// Procedure: paint_segment
void Graphics2D::paint_segment(const double x, const double y, const double dx, const double dy) {
  cairo_move_to(painter, x, y);
  cairo_rel_line_to(painter, dx, dy);
  cairo_stroke(painter);
}

// Procedure: paint_polygon
void Graphics2D::paint_polygon(const int n, const double polygon[][2]) {
  if(n <= 1) return;
  if(n == 2) { 
    paint_segment(polygon[0][0], polygon[0][1], polygon[1][0], polygon[1][1]);
    return;
  }
  cairo_move_to(painter, polygon[0][0], polygon[0][1]);
  for(int i=1; i<n; i++) {
    cairo_line_to(painter, polygon[i][0], polygon[i][1]);
  }
  cairo_close_path(painter);
  cairo_stroke(painter);
}

// Procedure: paint_filled_polygon
void Graphics2D::paint_filled_polygon(const int n, const double polygon[][2]) {
  if(n <= 1) return;
  if(n == 2) { 
    paint_segment(polygon[0][0], polygon[0][1], polygon[1][0], polygon[1][1]);
    return;
  }
  cairo_move_to(painter, polygon[0][0], polygon[0][1]);
  for(int i=1; i<n; i++) {
    cairo_line_to(painter, polygon[i][0], polygon[i][1]);
  }
  cairo_close_path(painter);
  cairo_fill(painter);
}

// Procedure: paint_arc
void Graphics2D::paint_arc(
  const double x, 
  const double y, 
  const double r, 
  const double ang1, 
  const double ang2
) {
  cairo_arc(painter, x, y, r, ang1, ang2);
  cairo_stroke(painter);
}

// Procedure: paint_circle
void Graphics2D::paint_circle(const double x, const double y, const double r) {
  cairo_arc(painter, x, y, r, 0, 2*M_PI);
  cairo_stroke(painter);
}

// Procedure: paint_filled_circle
void Graphics2D::paint_filled_circle(const double x, const double y, const double r) {
  cairo_arc(painter, x, y, r, 0, 2*M_PI);
  cairo_fill(painter);
}

// Procedure: paint_text
void Graphics2D::paint_text(const double x, const double y, const char text[]) {
  cairo_move_to(painter, x, y);
  cairo_set_font_size(painter, 1);
  cairo_show_text(painter, text); 
}

};
};

/*// Sample usage.
int main() {

  tLib::Graphics::Graphics2D design(5000, 5000);   			// set the design area.
  
  design.set_painter_width(10);                             // set the line width.
  design.set_painter_color(0, 0, 1);                        // set the r, g, b color.
  design.paint_circle(4000, 4000, 390);                     // draw the circle.
  
  design.set_painter_width(10);                             // set the line width.
  design.set_painter_color(0, 1, 0);                        // set the r, g, b color.
  design.paint_rectangle(3000, 2000, 1000, 1000);           // draw the rectangle.
  
  design.set_painter_width(10);                             // set the line width.
  design.set_painter_color(1, 0, 0);                        // set the r, g, b color.
  design.paint_segment(1000, 1000, 500, 3000);              // draw the segment.

  design.set_painter_width(10);                             // set the line width.
  design.set_painter_color(0.1, 0.5, 0.9);                  // set the r, g, b color.
  design.paint_filled_circle(1000, 1000, 200);              // draw the filled circle.

  double triangle[3][2] = {                                 // draw a triangle polygon.
    {3500, 1200},
    {4000, 1200},
    {3750, 1500}
  };
  design.set_painter_width_color(4, 0.3, 0.4, 0.7);        
  design.paint_filled_polygon(3, triangle);

  design.write_to_png("tLib_graphics_test1.png");           // output the file to png image.

  return 0;
}*/




