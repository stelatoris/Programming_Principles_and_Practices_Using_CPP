/* 
	Hasan Z. Programmer
	Aug 22nd 2021
	
	Programmingm: Principles and Practices Using C++ Book
	Chapter 11 Exercise 0x

*/


#include "std_lib_facilities.h"

int main()
try {

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}