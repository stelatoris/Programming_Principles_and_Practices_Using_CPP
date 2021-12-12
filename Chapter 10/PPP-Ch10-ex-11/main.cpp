// PPP Chapter 10 Exercise 11
/*
Write a program that produces the sum of all the whites pace-separated integers in a text file. 
For example, bears: 17 elephants 9 end should out- put 26.
*/

#include "std_lib_facilities.h"

const std::string input_file_name{"ch10-ex11.txt"};
const std::string error_msg_Input_file{"can't open input file"};

vector<int> file_readings;
vector<string> file_readings_string;

void print_int_vector(const vector<int>& v) 
// for testing purposes
{
	std::cout<<"Reading integers from file: \n";
	for (int n: v) {
		std::cout<<n<<'\n';
	}
}

void print_string_vector(const vector<std::string>& v)
// for testing purposes
{
	std::cout<<"Reading integers from file: \n";
	for (const std::string& n: v) {
		std::cout<<n<<'\n';
	}
}

int sum_of_ints_in_file(ifstream& ifs) 
{
	int n{0};
	int sum{0};
	while(!ifs.eof()) {
		if (ifs.fail()) {
			ifs.clear();

			std::string s;
			ifs>>s;

			file_readings_string.push_back(s);

		}
		if(ifs>>n) {
			sum+=n;
			file_readings.push_back(n);
		}
	}
	return sum;
}

int main()
try {

	std::ifstream ifs{input_file_name};
	if(!ifs) error(error_msg_Input_file, input_file_name);
	
	std::cout<<"Sum of al integers in file is: "<<sum_of_ints_in_file(ifs)<<'\n';
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}