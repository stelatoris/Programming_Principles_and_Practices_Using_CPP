// PPP-Chapter 10 Exercise 08:
/*
8. Write a program that accepts two file names and produces a new file that is the contents
 of the first file followed by the contents of the second; that is, the program concatenates
  the two files.
*/

#include "std_lib_facilities.h"

void end_of_loop(istream& ist, char term, const std::string& message)
{
	if (ist.fail()) {
		ist.clear();
		char ch;
		if(ist>>ch && ch==term) return;
		error(message);
	}
}

void copy_file_content( const std::string& in_file1_name, const std::string& in_file2_name, const std::string out_file_name)
{
	ifstream ifs1{in_file1_name};
	if(!ifs1) error("can't open input file ", in_file1_name);

	ifstream ifs2{in_file2_name};
	if(!ifs1) error("can't open input file ", in_file1_name);

	ofstream ofs{out_file_name};
	if(!ofs) error("can't open output file ", out_file_name);

	string read_string;
	for(char c; ifs1>>read_string;){
		ofs<<read_string<<" ";	//for white space between words
	}
	ofs<<'\n';

	for(char c; ifs2>>read_string;){
		ofs<<read_string<<" ";	//for white space between words
	}
	
}

//void combine_files(const std::string& in_file_01, const std::string& in_file_02, const std::string& out_file )
//{

//\\}

int main()
try {

	cout<<"File content copied.";
	copy_file_content("file01.txt", "file02.txt", "output.txt");

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}