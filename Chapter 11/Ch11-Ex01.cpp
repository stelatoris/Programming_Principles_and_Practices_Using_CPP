//Programmingm: Principles and Practices Using C++
//Chapter 11 Exercise 01
//Write a program that reads a text file and converts its input to all 
//lower case, producing a new file.

#include "std_lib_facilities.h"

const std::string iname{"textsample.txt"};
const std::string oname{"textoutput.txt"};

void file_to_lowercase(ifstream& ifs, ofstream& ofs)
{
	while(!ifs.eof()) {

		for(char ch; ifs.get(ch); ) {

			if(isupper(ch)) {
				char lower_ch;
				lower_ch=tolower(ch);
				
				ofs<<lower_ch;
				break;
			}

			else {
				ofs<<ch;
			}
		}

	}
	
}

int main()
try {

	ifstream ifs {iname};
	if(!ifs) error("can't open inout file");

	ofstream ofs {oname};
	if(!ofs) error("can't open output file");

	std::cout<<"Converting text to lowercase:\n";

	file_to_lowercase(ifs, ofs);

	std::cout<<"Conversion complete.\n";


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}