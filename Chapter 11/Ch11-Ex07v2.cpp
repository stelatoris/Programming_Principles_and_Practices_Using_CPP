/* 
	Hasan Z. Programmer
	Aug 16th 2021
	
	Programmingm: Principles and Practices Using C++ Book
	Chapter 11 Exercise 07

	7. Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.; 
    leaves hyphens within words intact (so that we get " do not use the as-if rule "); and converts all characters to lower case.
*/

#include "std_lib_facilities.h"

const std::string iname{"textsample.txt"};
const std::string oname{"textoutput.txt"};
const std::string puncuation_list{"!.;,?-'"};

void to_lowercase(std::string& s)
{
	if (s.size()==0) return;
	for (char& ch: s) ch=std::tolower(ch);
}

bool is_puncuation(char ch)
{
	for (char c: puncuation_list) {
		if (ch==c) return true;
	}
	return false;
}

/*
std::string remove_punct(const std::string& line, std::string& line_quotes, std::string& converted_line, bool& quotation)
{
	if (line.size()==0) return;
	for (char ch : line) {
	
		if (ch=='"' && quotation==true) {		// 2nd '"' found
			line_quotes+='"';
			converted_line+=line_quotes;
			quotation=false;
			line_quotes="";							// flush buffer
		}
		else if (ch=='"' && quotation==false) {		// 1st '"' detected
			quotation=true;
			line_quotes+='"';					// add to line without removing puncuation
		}
		else if (quotation==true) {
			line_quotes+=ch;	
		}
		else if (ch!=' ' && is_puncuation(ch) && quotation==false) converted_line+=' ';
		else converted_line+=ch;	
	}	
}
*/

std::string in_quotes(std::istringstream& ist, std::ostringstream& ost)
// keep parsing until a 2nd '"' is found.
// if single '"' found, then continue replacing puncuation with whitespace
// if another '"' found, then do not replace puncuation
{
	std::string line;
	while (!ist.eof()) {
		for (char ch; ist.get(ch);) {
			line+=ch;
			if (ch=='"') return line;				
		}
		for (char& c: line) {
			if (is_puncuation(c)) c=' ';
		}
		return line;				
	}	
}

void convert_file2(const std::string& iname, const std::string& oname)
{
    ifstream ifs{iname};
	if (!ifs) error("can't open input file", iname);
	ofstream ofs{oname};
	if (!ofs) error("can't open output file", oname);

    std::string line_input;						// line from ifstream
    std::string line_output;
    while (std::getline(ifs, line_input)) {
        std::istringstream ist{line_input};
        std::ostringstream ost{line_output};

        while (!ist.eof()) {
            for (char ch; ist.get(ch);) {
                if (ch=='"') {
                    std::string temp_line;
                    ofs<<'"';
                    temp_line=in_quotes(ist, ost);	// keeps replacing puncuation with whitespace unless found a 2nd 
                                                // '"' then return the characters between double qoutation unchanged.
                    ofs<<temp_line;
                }			
                else if (is_puncuation(ch)) ofs<<' ';
                else ofs<<ch;			
            }
	    }
        ofs<<'\n';
    }    
}

/*
void convert_file(const std::string& iname, const std::string& oname)
{
	ifstream ifs{iname};
	if (!ifs) error("can't open input file", iname);
	ofstream ofs{oname};
	if (!ofs) error("can't open output file", oname);

	std::string line;						// line from ifstream
	std::string line_in_quotes;				// buffer for adding chars in between double quotation
	std::string converted_line;				// converted output
    std::string temp_line;
	bool quotation_found{false};			// to carry the effect of double quotations into new lines
	while (std::getline(ifs, line)) {
		temp_line=remove_punct(line, line_in_quotes, converted_line, quotation_found);
		if (quotation_found) {				// if one double quotation found, keep reading without
			line_in_quotes+='\n';			// converting puncuation to whitespace				
		}
		else {
			converted_line+='\n';
			to_lowercase(converted_line);
			ofs<<converted_line;
			converted_line="";		
		}					
	}
}
*/

int main()                        
try {

convert_file2(iname, oname);
std::cout<<"done.\n";
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}