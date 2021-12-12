#include "std_lib_facilities.h"

void end_of_loop(ifstream& ifs, char term, const string& message )
{
	if(ifs.fail()) {
		ifs.clear();
		char ch;
		if(ifs>>ch && ch==term) return;
		error(message);
	}
}

double sum_from_file(const string& iname)
{
	ifstream ifs {iname};
	if(!ifs) error("can't open input file", iname);

	ifs.exceptions(ifs.exceptions()|ios_base::badbit);
	
	double n{0.0};
	double sum;
	while(ifs>>n){
			
		sum+=n;
	}

	end_of_loop(ifs, '|', "bad end of file");	
	return sum;
}



int main()
try {
	cout<<"Please enter input file name\n";
	string iname{"numbers.txt"};
	//cin>>iname;

	cout<<"Sum of all numbers in "<<iname<<" is: "<<sum_from_file(iname);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}