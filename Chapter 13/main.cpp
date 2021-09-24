//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
using namespace Graph_lib;

//----------------------------------------------------------------------
// Exercise 1
Arc::Arc(Point p, int w, int h, int b, int e)
    : width{ w }, height{ h }, begin{ b }, end{ e }
{
    add(Point{ p.x - width,p.y - height });
}

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, width, height, begin, end);
}

//----------------------------------------------------------------------
// Exercise 2

Rounded_box::Rounded_box(Point p, int ww, int hh, int rr)
    : w{ww}, h{hh}, r{rr}
{
    if(h<=0||w<=0||r<=0)
      error("Bad rectangle: non-positive side/radius");
    add(p);
}

void Rounded_box::draw_lines() const
{
    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x+w-r-r,point(0).y,r+r,r+r,0,90);       // top right rounded corner 
      fl_arc(point(0).x,point(0).y,r+r,r+r,90,180);       // top left rounded corner 
      fl_arc(point(0).x,point(0).y+h,r+r,r+r,180,270);    // bottom left rounded corner 
      fl_arc(point(0).x+w-r-r,point(0).y+h,r+r,r+r,270,360);  // bottom right rounded corner

      fl_line(point(0).x+r,point(0).y,point(0).x+w-r,point(0).y);               // top edge
      fl_line(point(0).x+w,point(0).y+r,point(0).x+w,point(0).y+h+r);   // right edge
      fl_line(point(0).x+r,point(0).y+h+r+r,point(0).x+w-r,point(0).y+h+r+r);   // bottom edge
      fl_line(point(0).x,point(0).y+r,point(0).x,point(0).y+h+r);               // left edge
    }
}

int main()
try
{    
  // Window
  Point tl{ 100, 100 };
  Simple_window win{ tl, 1000, 600, "Chapter 13 Ex 1" };

  /*
  int x_size=win.x_max();
  int y_size=win.y_max();


  Lines grid_10x10;
  for(int x=10; x<x_size; x+=10)
    grid_10x10.add(Point{x,0},Point{x,y_size});
  
  for(int y=10; y<y_size; y+=10)
    grid_10x10.add(Point{0,y},Point{x_size,y});

  win.attach(grid_10x10);
  
  Lines grid_50x50;

  for(int x=50; x<x_size; x+=50)
    grid_50x50.add(Point{x,0},Point{x,y_size});
  
  for(int y=50; y<y_size; y+=50)
    grid_50x50.add(Point{0,y},Point{x_size,y});

  grid_50x50.set_color(Color::red);
  win.attach(grid_50x50);
  
    Lines grid_100x100;

  for(int x=100; x<x_size; x+=100)
    grid_100x100.add(Point{x,0},Point{x,y_size});
  
  for(int y=100; y<y_size; y+=100)
    grid_100x100.add(Point{0,y},Point{x_size,y});

  grid_100x100.set_color(Color::green);
  win.attach(grid_100x100);
  */

  // Arc tests
  //Graph_lib::Arc ar1{ Point{400,300},200,100,1,180 };
  //ar1.set_color(Color::red);
  //win.attach(ar1);

  //win.wait_for_button();

  Graph_lib::Rounded_box rb1{tl, 576,367,32}; 
  rb1.set_color(Color::blue);

  win.attach(rb1);

  win.wait_for_button();

}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}