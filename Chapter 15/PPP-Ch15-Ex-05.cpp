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

constexpr int x_scale = 1;
constexpr int y_scale = 500;

constexpr int r_min = 0; // range [�10:11)
constexpr int r_max = 1000000;

constexpr int n_points = 400; // number of points used in range

constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
constexpr int y_orig = ymax / 2;
constexpr Point orig{ x_orig,y_orig };

//-------------------------------------------------------------------------
// 5.
double leibniz(double x)
{    
    int terms = x;
    double sum = 1.0;
    double denominator = 3.0;
    double numerator = 1.0;    

    for (int i = 0; i < terms; ++i) {
        if (i % 2 == 0) {
            sum -= numerator / denominator;
        }
        else {
            sum += numerator / denominator;
        }
        denominator += 2;
    }
    //cout << sum<<'\n';
    return sum;
}


//-------------------------------------------------------------------------

int main()
try
{
    //  5. �Animate� (as in �15.5) the series 1�1/3+1/5�1/7+1/9�1/11+ . . . . It is
    //  known as Leibniz�s series and converges to pi / 4.
    
    Graph_lib::Window win{ Point{100,100},xmax,ymax,"Exercise 05" };

    Axis x{ Axis::x,x_axis_p,xlength,xlength / x_scale,"1==1 pixels" };
    Axis y{ Axis::y,y_axis_p,ylength,ylength / y_scale,"1==500 pixels" };

    My_fct s{ leibniz,r_min,r_max,orig,n_points,x_scale,y_scale };
    s.set_color(Color::green); 
    My_fct s2{ [](double x) {return PI / 4; },r_min,r_max,orig,n_points,x_scale,y_scale };
    s2.set_color(Color::blue);

    win.attach(x);
    win.attach(y);
    win.attach(s);
    win.attach(s2);

    gui_main();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
