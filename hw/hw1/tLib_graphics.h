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

#ifndef TLIB_GRAPHICS_H_
#define TLIB_GRAPHICS_H_

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cairo.h>

using namespace std;

namespace tLib {

namespace Graphics {

// Graphics2D class.
// Linking to cairo library can be done via the following command: 
// ~> g++ tLib_graphics.cpp `pkg-config --libs --cflags cairo`
class Graphics2D {
  
  public:

    Graphics2D(const double, const double);
    ~Graphics2D();

    double image_x() const;
    double image_y() const;
    

    void write_to_png(const char []);
    void write_to_png(const string &);
    void set_painter_width(const double);
    void set_painter_color(const double, const double, const double);
    void set_painter_width_color(const double, const double, const double, const double);
    void paint_rectangle(const double, const double, const double, const double);
    void paint_filled_rectangle(const double, const double, const double, const double);
    void paint_segment(const double, const double, const double, const double);
    void paint_polygon(const int n, const double [][2]);
    void paint_filled_polygon(const int n, const double [][2]);
    void paint_arc(const double, const double, const double, const double, const double);
    void paint_circle(const double, const double, const double);
    void paint_filled_circle(const double, const double, const double);
    void paint_text(const double, const double, const char[]);

  private:

    cairo_surface_t *surface;
    cairo_t *painter;
    cairo_matrix_t matrix;

    double img_x;
    double img_y;
    double scale;
};

};

};

#endif

