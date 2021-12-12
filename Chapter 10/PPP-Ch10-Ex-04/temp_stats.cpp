
/*
4. Modify the store_temps.cpp program from exercise 2 to include a 
temperature suffix c for Celsius or f for Fahrenheit temperatures. 
Then modify the temp_stats.cpp program to test each temperature, 
converting the Celsius readings to Fahrenheit before putting them into the vector.
*/

#include "std_lib_facilities.h"

struct Reading
{
	Reading (int d, int h, int t, char u );
	Reading () : day{1}, hour{0}, temperature{-777}, unit{'f'} {}
	
	int day;
	int hour;
	int temperature;
	char unit;
};

Reading::Reading (int d, int h, int t, char u)
	: day{d}, hour{h}, temperature{t}, unit{u}
{	
}

bool operator< (const Reading& lhs, const Reading& rhs) {
    return lhs.temperature < rhs.temperature;
}

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
	char u;
	int d;
	int h;
	int t;
	is>>d>>h>>t>>u>>ch2;
	if(!is||ch2!=')') error("bad reading in istream& operator>>");
	r.day=d;
	r.hour=h;
	r.temperature=t;
	r.unit=u;
	end_of_loop(is, '|', "bad end of file");
	return is;
}

ostream& operator<<(ostream& os, Reading r)
{
	return os<<'('<<r.day
			<<' '<<r.hour
			<<' '<<r.temperature
			<<' '<<r.unit<<')';
}

vector<Reading> new_temp_readings;		//vector to hold readings from file
vector<Reading> c_temp_readings;

Reading convert_temp(const Reading& r, char u)		// char u is either 'f' or 'c'
{
	Reading c=r;	//celcius
	if(u=='f') return r;	//fehrenheit
	else if(u=='c') {
		c.unit='c';
		c.temperature=((c.temperature-32)*(5.0/9.0));	// (32°F − 32) × 5/9 = 0°C *5.0/9.0 for double
		return c;

	}
	else {
		error("wrong conversion unit in file_to_vector() call");
	}
}

void file_to_vector (vector<Reading>& readings, const string& iname, char u)
{
	ifstream ifs {iname};
	if(!ifs) error("Can't open input file ", iname);

	for (Reading r; ifs>>r;) readings.push_back(convert_temp(r, u));
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

double median_temperature(const vector<Reading>& readings)
{
	double median={0};
	vector<Reading> v_temp=readings;
	sort(v_temp.begin(), v_temp.end());

	if(v_temp.size()%2==0) {	// if number of readings is even
	    return (v_temp[v_temp.size()/2].temperature +v_temp[(v_temp.size()/2)+1].temperature)/2;
	}
	else {	// if no. of readins is odd
        return v_temp[v_temp.size()/2].temperature;
	}
}

int main()
try 
{
	file_to_vector(new_temp_readings, "raw_temps.txt", 'f');

	cout<<"Temperature readings from raw_temp.txt:\n";
	for(Reading& r: new_temp_readings)
		cout<<r<<'\n';

	cout<<"Mean temperature is "<<mean_temperature(new_temp_readings)<<" degrees.\n";

	cout<<"Median temperature is "<<median_temperature(new_temp_readings)<<'\n';
	
	cout<<"Converting f to c: \n";
	file_to_vector(c_temp_readings, "raw_temps.txt", 'c');
	for(Reading& r: c_temp_readings)
		cout<<r<<'\n';

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}