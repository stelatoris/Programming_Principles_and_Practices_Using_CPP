//main.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 15 Drill and Exercise solutions

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;


constexpr int xmax = 1200;   // window size
constexpr int ymax = 1200;

constexpr int xlength = 1200;    // Axis length
constexpr int ylength = 1200;

constexpr Point x_axis_p = { (xmax/2)-(xlength/2),(ymax / 2) };  // starting point of axis to cross both at (300,300)
constexpr Point y_axis_p = { xmax / 2,(ymax / 2) + (ylength / 2) };

constexpr int x_scale = 40;
constexpr int y_scale = 40;

constexpr int r_min = 1; // range [�10:11)
constexpr int r_max = 10;

constexpr int n_points = 10; // number of points used in range

constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
constexpr int y_orig = ymax / 2;
constexpr Point orig{ x_orig,y_orig };

//-------------------------------------------------------------------------
// 6.


double slope(double x) { return x / 2; }
//-------------------------------------------------------------------------

int main()
try
{
    //    6. Design and implement a bar graph class.Its basic data is a vector<double>
    //       holding N values, and each value should be represented by a �bar� that is
    //       a rectangle where the height represents the value.
    
    Graph_lib::Window win{ Point{100,100},xmax,ymax,"Exercise 06" };

    Axis x{ Axis::x,x_axis_p,xlength,xlength / x_scale,"1==40 pixels" };
    Axis y{ Axis::y,y_axis_p,ylength,ylength / y_scale,"1==40 pixels" };

    vector<double>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(slope(i));
    }

    Bar_graph s{ orig,x_scale,y_scale,v };
    s.set_spacing(20);
    s.set_fill_color(Color::blue);
   

    win.attach(x);
    win.attach(y);
    win.attach(s);

    gui_main();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
