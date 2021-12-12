//Programmingm: Principles and Practices Using C++
//Chapter 11 Exercise 03
//3. Write a program that removes all vowels from a file (“disemvowels”). 
//For example, Once upon a time! becomes nc pn tm!. Surprisingly often, the result is still readable; 
//try it on your friends.

#include "std_lib_facilities.h"

const std::string iname{"textsample.txt"};
const std::string oname{"textoutput.txt"};

bool is_vowel(char ch)
{
    if(ch=='A'||ch=='a'||ch=='E'||ch=='e'
        ||ch=='I'||ch=='i'||ch=='O'||ch=='o'
        ||ch=='U'||ch=='u')
            return true;
            
    else { return false; }
}

void del_vowels(ifstream& ifs, ofstream& ofs)
{
    while(!ifs.eof()) {
        for(char ch; ifs.get(ch);) {
            if(is_vowel(ch)) {
                // do nothing
            }
            else {
                ofs<<ch;
            }
        }
    }
}

int main()
try {

ifstream ifs{iname};
if(!ifs) error("can't open input file");

ofstream ofs{oname};
if(!ofs) error("can't open output file");

std::cout<<"Removing vowels.....";
del_vowels(ifs, ofs);
std::cout<<"Complete.\n";

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
