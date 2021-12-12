/* 
	Hasan Z. Programmer
	Aug 13th 2021
	
	Programmingm: Principles and Practices Using C++ Book
	Chapter 11 Exercise 06

	6. Write a program that replaces punctuation with whitespace. 
	Consider . (dot), ; (semicolon), , (comma), ? (question mark), - (dash), ' (singlequote) punctuation characters. 
	Don’t modify characters within a pair of double quotes ("). 
	For example, “ - don't use the as-if rule.” becomes “ don t use the as if rule ”.
*/

#include "std_lib_facilities.h"

const std::string iname{"textsample.txt"};
const std::string oname{"textoutput.txt"};
const std::string puncuation_list{"!.;,?-'"};

bool is_puncuation(char ch)
{
	for (char c: puncuation_list) {
		if (ch==c) return true;
	}
	return false;
}

/*
std::string in_quotes(ifstream& ifs, ofstream& ofs)
// keep parsing until a 2nd '"' is found.
// if single '"' found, then continue replacing puncuation with whitespace
// if another '"' found, then do not replace puncuation
{
	std::string line;
	while (!ifs.eof()) {
        std::string word_buffer;
		for (char ch; ifs.get(ch);) {
            if (ch==' ') {
                line+=word_buffer;
                line+=' ';
                for (char c : word_buffer) {
                    if (c=='"') return line;
                }                	
            }
            else {
                word_buffer+=ch;
            }
						
		}
		for (char& c: line) {
			if (is_puncuation(c)) c=' ';
		}
		return line;				
	}	
}


void to_whitespace(ifstream& ifs, ofstream& ofs)
{
	while (!ifs.eof()) {
        std::string word_buffer;
		for (char ch; ifs.get(ch);) {
            if (ch==' ') {
                for (char& c : word_buffer) {
                    if (c=='"') {
                        std::string line;
                        line=in_quotes(ifs, ofs);	// keeps replacing puncuation with whitespace unless found a 2nd 
                                                    // '"' then return the characters between double qoutation unchanged.
                        ofs<<line;
			        }
                    else if (is_puncuation(c)) c=' ';
			        else word_buffer+=c;		
                }
                ofs<<word_buffer<<' ';
            }
            else {
                word_buffer+=ch;
            }
		}
	}
}
*/

std::string in_quotes(ifstream& ifs, ofstream& ofs)
// keep parsing until a 2nd '"' is found.
// if single '"' found, then continue replacing puncuation with whitespace
// if another '"' found, then do not replace puncuation
{
	std::string word;
	std::string line;
	while (!ifs.eof()) {
		ifs>>word;
		line+=word;
		line+=' ';
		for (char ch : word) {
			if (ch=='"') return line;				
		}				
	}
	for (char& c: line) {
		if (is_puncuation(c)) c=' ';
	}
	return line;
}

void test2(ifstream& ifs, ofstream& ofs)
{
	std::string word;
	while(ifs>>word){
		for (char ch : word) {
    		if (ch=='"') {
				std::string line;
				line=in_quotes(ifs, ofs);	// keeps replacing puncuation with whitespace unless found a 2nd 
											// '"' then return the characters between double qoutation unchanged.
				ofs<<line;
			}			
			else if (is_puncuation(ch)) ofs<<' ';
			else ofs<<ch;			
		}
		ofs<<' ';
	}
}

void test(ifstream& ifs, ofstream& ofs)
{
	std::string word_buffer;
    while (!ifs.eof()) {
        
		for (char ch; ifs.get(ch);) {
            if (ch==' ') {

                ofs<<word_buffer<<' ';
                word_buffer="";
            }
            else {
                word_buffer+=ch;
            }
		}
	}
    ofs<<word_buffer;   //last word in file
}

int main()                        
try {

ifstream ifs{iname};
if (!ifs) error("can't open input file");
ofstream ofs{oname};
if (!ofs) error("can't open output file");

std::cout<<"Removing puncuation....";
test2(ifs, ofs);
std::cout<<"done.\n";
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}