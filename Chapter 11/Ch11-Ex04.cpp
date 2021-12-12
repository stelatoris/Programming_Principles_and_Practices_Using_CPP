//Programmingm: Principles and Practices Using C++
//Chapter 11 Exercise 03
//4. Write a program called multi_input.cpp that prompts the user to 
//enter several integers in any combination of octal, decimal, 
//or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; 
//and converts them to decimal form. Then your program should output the values in 
//properly spaced columns like this:
//
//  0x43  hexadecimal  converts to   67 decimal 
//  0123  octal        converts to   83 decimal 
//    65  decimal      converts to   65 decimal

#include "std_lib_facilities.h"

void multi_input( std::string input)
{
    
}

int main()
try {

    std::string input_line;

    std::cout<<"Please enter several integers in any combination of octal, decimal, or hexadecimal, "
            <<"using the 0 and 0x base suffixes.\n";

    

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
