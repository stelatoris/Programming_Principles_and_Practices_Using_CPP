/*
6. Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. 
Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, 
we can write cout << "Roman" << r << " equals " << r.as_int() << '\n';.
*/

#include "std_lib_facilities.h"
#include <iostream>
#include <vector> 
#include "rom_numerals.h"

using namespace Roman_nums;

int roman_parser(char ch)
{
	int value{0};
	switch (ch) {
		case 'I':
			return I;
			break;
		case 'V':
			return V;
			break;
		case 'X':
			return X;
			break;
		case 'L':
			return L;
			break;
		case 'C':
			return C;
			break;
		case 'D':
			return D;
			break;
		case 'M':
			return M;
			break;
	}
}




void handle_number(int n)
{
	int difference{0};
	current_value=n;

	if(previous_value==0){
		// this is the 1st value
		total_value=n;
		current_value=n;
		previous_value=current_value;
		
		
	}
		else if(previous_value<current_value) {
		difference=current_value-previous_value;
		total_value-=previous_value;
		total_value+=difference;
		difference=0;
		previous_value=current_value;
	}
	else if(previous_value>=current_value) {
		total_value+=current_value;
		previous_value=current_value;
	}


}

std::istream& operator>>(std::istream& is, Roman_int& r)
{
	

	while(true) {
		char ch;
		if(!(is>>ch)) {
			total_value=0;
			break;
		} 
		std::cout<<"Char: "<<ch<<'\n';
		std::cout<<"Value of "<<ch<<" is "<<roman_parser(ch)<<'\n';
		std::cout<<"Before input \n";
		std::cout<<"prev value: "<<previous_value<<'\n';
		std::cout<<"current value: "<<current_value<<'\n';
		std::cout<<"total value: "<<total_value<<"\n\n";
		
		handle_number(roman_parser(ch));
		std::cout<<"After input \n";
		std::cout<<"prev value: "<<previous_value<<'\n';
		std::cout<<"current value: "<<current_value<<'\n';
		std::cout<<"total value: "<<total_value<<'\n';
		std::cout<<"---------------------------------\n\n";
		

	}
	r.int_number=total_value;
	return is;
}



std::ostream& operator<<(std::ostream& os, Roman_int& r)
{
	return os<<r.roman_num;
}


int main()
try 
{
	//ifstream ifs {"numbers.txt"};
	//if(!ifs) error("can't open input file","numbers.txt");
	
	Roman_int num1;
	//std::cout<<"Readings from file: \n";
	//ifs>>num1;
	std::cout<<"Please enter a roman numeral\n";
	std::cin>>num1;
	
	

}

catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "exception\n";
}