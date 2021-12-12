/* 
	Hasan Z. Programmer
	Aug 22nd 2021
	
	Programmingm: Principles and Practices Using C++ Book
	Chapter 11 Exercise 09

    9. Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary 
    text file into binary and one program that reads binary and converts it to text. 
    Test these programs by comparing a text file with what you get by converting it to binary and back.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <system_error>
#include <vector>
#include "std_lib_facilities.h"

using std::string;


const string input1{"input1.txt"};
const string output1{"output1.txt"};
const string input2{"input2.txt"};
const string output2{"output2.txt"};

void text_to_binary( const string& input, const string& output)
{
    std::ifstream ifs{input1, std::ios_base::binary};
    if (!ifs) throw std::runtime_error("can't open input1 file");
    std::ofstream ofs{output1, std::ios_base::binary};
    if (!ofs) throw std::runtime_error("can't open output1 file");

    vector<int> v;

    for (int x;ifs.read(as_bytes(x),sizeof(int));)
        v.push_back(x);

    for (int x : v)
        ofs<<x<<' ';   

    for (int x : v) std::cout<<x<<'\n';
}

void binary_to_text( const string& input, const string& output)
{
    std::ifstream ifs{input2};
    if (!ifs) throw std::runtime_error("can't open input1 file");
    std::ofstream ofs{output2, std::ios_base::binary};
    if (!ofs) throw std::runtime_error("can't open output1 file");

    vector<int> v;
    
    for(int x; ifs.read(as_bytes(x),sizeof(int)); )
        v.push_back(x);
    for(int x : v) {
        ofs.write(as_bytes(x),sizeof(int));
        ofs<<' ';
    }
     

}

int main()
try {
    
    text_to_binary(input1, output1);
    binary_to_text(output1, output2);
    std::cout<<"Done.";

    return 0;

    
}

catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "exception\n";
}