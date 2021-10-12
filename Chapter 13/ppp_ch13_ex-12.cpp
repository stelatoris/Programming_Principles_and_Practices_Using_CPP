//ppp_ch13_ex-12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

//----------------------------------------------------------------------
// Exercise 12
/*
    12. Draw a circle. Move a mark around on the circle (let it move a bit each
    time you hit the “Next” button).
*/

void moving_mark(Circle& const c,int n, Simple_window& win)
{
    //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    // n is number of times the point will travel around.
 
    for (int r = 0; r <= 360; r += (360 / n)) {
        int x = c.center().x + (c.radius() * sin(r * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(r * (PI / 180)));
        
        Mark m1{ Point{x,y},'x' };
        m1.set_color(Color::red);
        win.attach(m1);
        win.wait_for_button();
    }   
}


int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 1000, 600, "Chapter 13 Ex 12" };

    // Ex 12
    Circle c1{ Point{400,300},100 };
    win.attach(c1);
    win.wait_for_button();

    moving_mark(c1, 12, win);    
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}