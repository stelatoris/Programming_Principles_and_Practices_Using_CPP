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

vector<Roman_symbol>rom_symbols={{'I',1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };


bool is_valid_roman_num_symbol(const char c)
{
	return c=='I'
		|| c=='V'
		|| c=='X'
		|| c=='L'
		|| c=='C'
		|| c=='D'
		|| c=='M';
}

bool is_valid_additive(const char c) // is valid for additive notation
{
	return c=='M'
	|| c=='C'
	|| c=='X'
	|| c=='I';
}

int roman_to_int(char ch)	// return the integer value of each symbol
{
	int value{0};
	switch (ch) {
		case 'I':
			return I;	// constexpr int I=1; in rom_numerals.h
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
		default:
			error("invalid Roman Numeral symbol");
	}
}

int subtractive_notation(char current, char previous)
{
	
	if(current=='C'&&previous=='D') 	// CD = 400
		return roman_to_int(previous)-roman_to_int(current);
	else if(current=='C' && previous=='M') 	// CM = 900
		return roman_to_int(previous)-roman_to_int(current);
	else if(current=='X' && previous=='L')	// XL = 40
		return roman_to_int(previous)-roman_to_int(current);
	else if(current=='X' && previous=='C')	// XC = 90
		return roman_to_int(previous)-roman_to_int(current);
	else if(current=='I' && previous=='V')	// IV = 4
		return roman_to_int(previous)-roman_to_int(current);
	else if(current=='I' && previous=='X')	// IX = 9
		return roman_to_int(previous)-roman_to_int(current);
	else {
		error("invalid subtractive notation");
	}

}

int Roman_int::as_int()
{
	char previous_char{'z'};	//'z' no previous character
	char penultimate_char{'p'};	// before previous char : to not allow a second number of same digit placement e.g IVI or CDC
	int total_value{0};
	int prev_value{0};	// used to make sure right handside digit is not larger than left hand side e.g VX or IVV
	int current_value{0};	// same as above
	int repeat_char{1};	// following standard rules, alow up to 3 repeated chars for valid symbols e.g III and not IIII

	for(int i=roman_num.size()-1; i>=0 ; --i){	// read right to left
		
		char c{roman_num[i]};
		current_value=roman_to_int(c);

		if(previous_char=='z') {	//1st character in string
			previous_char=c;
			
			prev_value=current_value;
			total_value+=current_value;
		}
		else if(is_valid_additive(c) && previous_char==c && prev_value==current_value && repeat_char<3) {
			total_value+=current_value;
			penultimate_char=previous_char;
			previous_char=c;
			prev_value=current_value;
			++repeat_char;
		}
		else if(roman_to_int(c)>roman_to_int(previous_char) && prev_value<=current_value && penultimate_char!=c) {
			// if current Roman symbol is larger value than previous symbol
			total_value+=current_value;
			penultimate_char=previous_char;
			previous_char=c;
			prev_value=current_value;
			repeat_char=1;
		}
		else if(roman_to_int(previous_char)>roman_to_int(c) && repeat_char==1) {
			total_value-=roman_to_int(previous_char);
			total_value+=subtractive_notation(c, previous_char);
			prev_value=subtractive_notation(c, previous_char);
			penultimate_char=previous_char;
			previous_char=c;
			repeat_char=1;			
		}
		else {
			std::cout<<"invalid Roman numeral. Please try again:\n";
			break;
			//error("invalid Roman numeral - as_int_reverse()");
		}
	}
	return total_value;
}

std::istream& operator>>(std::istream& is, Roman_int& r)
{
	std::string rom_number;
	is>>rom_number;
	for(char& c : rom_number) {
		if(!is_valid_roman_num_symbol(c)) {
			std::cout<<"invalid Roman numeral\n";
			return is;
		}
	}
	r.roman_num=rom_number;
	r.int_number=r.as_int();
	
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
	while(std::cin>>num1){
		std::cout<<"You have entered: "<<num1<<" ("<<num1.int_number<<")\n";
		
	}
}

catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "exception\n";
}