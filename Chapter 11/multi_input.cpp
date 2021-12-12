//Programmingm: Principles and Practices Using C++
//Chapter 11 Exercise 04
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

void print_result(std::string dec_type, std::string number)
{
    int int_number{0};
    std::istringstream ist;

    if(dec_type=="hex") {
        ist.str(number);
        ist>>hex>>int_number;
        std::cout<<setw(6)<<number<<'\t'<<setw(11)<<"hexadecimal"<<'\t'<<setw(10)<<"converts to\t"<<dec<<int_number<<"\tdecimal\n";
    }
    else if(dec_type=="oct") {
        ist.str(number);
        ist>>oct>>int_number;
        std::cout<<setw(6)<<number<<'\t'<<setw(11)<<"octal"<<'\t'<<setw(10)<<"converts to\t"<<dec<<int_number<<"\tdecimal\n";
    }
    else if(dec_type=="dec") {
        ist.str(number);
        ist>>dec>>int_number;
        std::cout<<setw(6)<<number<<'\t'<<setw(11)<<"decimal"<<'\t'<<setw(10)<<"converts to\t"<<dec<<int_number<<"\tdecimal\n";
    }
}

bool is_valid_number(std::string& s)
{
    int invalid{0};
    for(char ch: s) {
        if(ch!='x' && !isdigit(ch) && !isxdigit(ch)) return false;
    }
    return true;
}
std::string find_decimal_type(std::string& input)
{
    if(input[0]=='0' && input[1]=='x') return "hex";
    else if(input[0]=='0' && isdigit(input[1])) return "oct";
    else if(input[0]!='0' && isdigit(input[1])) return "dec";
}

void multi_input( std::string& input_line)
{   
    istringstream ist{input_line};
    if (!ist) error("cannot read input"); 
    std::string line;

    while (!ist.eof()) {
        std::string int_input;  //stores individual space seperated inputs
        ist>>int_input;
        if(!is_valid_number(int_input)) error ("invalid number");
        print_result(find_decimal_type(int_input), int_input);
    }
}

int main()
try {
    std::string input_line;

    std::cout<<"Please enter several integers in any combination of octal, decimal, or hexadecimal, "
            <<"using the 0 and 0x base suffixes.\n\n";
    //std::getline(std::cin, input_line);
    input_line="0x43 654467 03345 0x876";
    multi_input(input_line);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
