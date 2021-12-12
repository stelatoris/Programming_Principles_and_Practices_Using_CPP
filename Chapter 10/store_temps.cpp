// PPP-Ch10-Ex-02.cpp
/*
2. Write a program that creates a file of data in the form of the 
temperature Reading type defined in §10.5. For testing, 
fill the file with at least 50 “temperature readings.” 
Call this program store_temps.cpp and the file it creates raw_temps.txt.
*/

#include "std_lib_facilities.h"

struct Reading
{
	Reading (int d, int h, double t );
	Reading () : day{1}, hour{0}, temperature{-777} {}
	
	int day;
	int hour;
	double temperature;
};

Reading::Reading (int d, int h, double t)
	: day{d}, hour{h}, temperature{t}
{	
}

vector<Reading>temp_readings;

void end_of_loop(istream& is, char term, string message)
{
	if(is.fail()) {
		is.clear();
		char ch;
		if(is>>ch && ch==term) return;
		error(message);
	}
}

istream& operator>>(istream& is, Reading& r)	//(1 1 60.5) reading template
{
	char ch1;
	if(is>>ch1&&ch1!='(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is>>d>>h>>t>>ch2;
	if(!is||ch2!=')') error("bad reading in istream& operator>>");
	r.day=d;
	r.hour=h;
	r.temperature=t;
	end_of_loop(is, '|', "bad end of file");
	return is;
}

ostream& operator<<(ostream& os, Reading r)
{
	return os<<'('<<r.day
			<<' '<<r.hour
			<<' '<<r.temperature<<')';
}

void vector_to_file(const vector<Reading>& readings, const string& oname, char end_of_file )
{
	ofstream ost {oname};
	if(!ost) error("Can't open output file ", oname);

	for(const Reading& r: readings) 
		ost<<r<<'\n';
	ost<<end_of_file;
}

int main()
try 
{
	cout<<"Please enter temperature readings: '(day hour temperature)'\n";
	Reading input;
	while(cin>>input) {
		temp_readings.push_back(input);
	}
	
	vector_to_file(temp_readings, "raw_temps.txt", '|');

	cout<<"Temperature readings:\n";
	for(Reading& r: temp_readings)
		cout<<r<<'\n';

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}