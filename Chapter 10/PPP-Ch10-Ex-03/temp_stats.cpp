// PPP-Ch10-Ex-02.cpp
/*
3. Write a program that reads the data from raw_temps.txt created in ex- ercise 2 
into a vector and then calculates the mean and median tempera- tures in your data set. 
Call this program temp_stats.cpp.

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

vector<Reading> temp_readings;			// vector to copy readings into file
vector<Reading> new_temp_readings;		//vector to hold readings from file

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
	ofstream ofs {oname};
	if(!ofs) error("Can't open output file ", oname);

	for(const Reading& r: readings) 
		ofs<<r<<'\n';
	ofs<<end_of_file;
}

void file_to_vector (vector<Reading>& readings, const string& iname)
{
	ifstream ifs {iname};
	if(!ifs) error("Can't open input file ", iname);

	for (Reading r; ifs>>r;) readings.push_back(r);
	if (ifs.eof()) return;
}

double mean_temperature(const vector<Reading>& readings)
{
	double sum=0;
	for(const Reading& r: readings) {
		sum+=r.temperature;
	}
	sum/=readings.size();
	return sum;
}

void median_temperature(vector<Reading>& readings)
{
	double median={0};
	vector<Reading> v_temp=readings;
	sort(v_temp.begin(), v_temp.end());
	for(Reading& r: v_temp) cout<<r<<'\n';
}

int main()
try 
{
	/*
	cout<<"Please enter temperature readings: '(day hour temperature)'\n";
	Reading input;
	while(cin>>input) {
		temp_readings.push_back(input);
	}
	
	vector_to_file(temp_readings, "raw_temps.txt", '|');
	*/

	file_to_vector(new_temp_readings, "raw_temps.txt");

	cout<<"Temperature readings from raw_temp.txt:\n";
	for(Reading& r: new_temp_readings)
		cout<<r<<'\n';

	cout<<"Mean temperature is "<<mean_temperature(new_temp_readings)<<" degrees.\n";

	median_temperature(new_temp_readings);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}