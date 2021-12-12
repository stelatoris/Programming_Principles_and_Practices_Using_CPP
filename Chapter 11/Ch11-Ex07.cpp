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
const std::string puncuation_list{"!.;,?-\""};

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

std::string contractions(const std::string& s)
{
	if (s=="aren't") return "are not";
	else if (s=="can't") return "cannot";
	else if (s=="don't") return "do not";
	else if (s=="couldn't") return "could not";
	else if (s=="didn't") return "did not";
	else if (s=="hasn't") return "has not";
	else if (s=="haven't") return "have not";
	else if (s=="isn't") return "is not";
	else if (s=="shouldn't") return "should not";
	else if (s=="wasn't") return "was not";
	else if (s=="weren't") return "were not";
	else if (s=="won't") return "will not";
	else if (s=="wouldn't") return "would not";
	else if (s=="mustn't") return "must not";
	else if (s=="shan't") return "shall not";
	else return s;
}

std::string uncontract(std::string& line)
{
	std::istringstream ist(line);
	std::string new_line;
	std::string word;
	std::string new_word;
	while (ist>>word) {
		new_word=contractions(word);
		new_line+=new_word;
		new_line+=' ';
	}
	new_line+='\n';
	return new_line;
}

void remove_punct(const std::string& line, std::string& line_quotes, std::string& converted_line, bool& quotation1, bool& quotation2)
{
	if (line.size()==0) return;
	for (char ch : line) {
	
		if (ch=='"' && quotation1==true) {		// 2nd '"' found
			line_quotes+='"';
			converted_line+=line_quotes;
			quotation1=false;
			quotation2=true;
			line_quotes="";							// flush buffer
		}
		else if (ch=='"' && quotation1==false) {		// 1st '"' detected
			quotation1=true;
			quotation2=false;
			line_quotes+='"';					// add to line without removing puncuation
		}
		else if (quotation1==true) {
			line_quotes+=ch;	
		}
		else if (std::isalpha(ch)) converted_line+=ch;
		else if (ch!=' ' && is_puncuation(ch) && quotation1==false) converted_line+=' ';
		else converted_line+=ch;	
	}	
}

void convert_file(const std::string& iname, const std::string& oname)
{
	ifstream ifs{iname};
	if (!ifs) error("can't open input file", iname);
	ofstream ofs{oname};
	if (!ofs) error("can't open output file", oname);

	std::string line;						// line from ifstream
	std::string line_in_quotes;				// buffer for adding chars in between double quotation
	std::string converted_line;				// converted output
	std::string final_conversion;
	std::string uncontracted_line;
	bool quotation1{false};
	bool quotation2{false};			// to carry the effect of double quotations into new lines
	while (std::getline(ifs, line)) {
		
		remove_punct(line, line_in_quotes, converted_line, quotation1, quotation2);
		if (quotation1) {	
			//line_in_quotes=uncontract(line_in_quotes);	// if one double quotation found, keep reading without
			line_in_quotes+='\n';						// converting puncuation to whitespace				
		}
		else if (!quotation1) {
			converted_line+='\n';
			to_lowercase(converted_line);
			ofs<<converted_line;
			converted_line="";		
		}
	}

	if (ifs.eof() && quotation2==false) {			// if file ends without finding a 2nd quotation
		for (char& ch : line_in_quotes) {
			if (is_puncuation(ch)) ch=' ';
		}
		to_lowercase(line_in_quotes);
		converted_line+=line_in_quotes;
		ofs<<converted_line;
		line_in_quotes="";
		converted_line="";
	}			
}

int main()                        
try {

convert_file(iname, oname);
std::cout<<"done.\n";
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}