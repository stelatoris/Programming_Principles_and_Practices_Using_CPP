/*
4. Modify the store_temps.cpp program from exercise 2 to include a temperature 
suffix c for Celsius or f for Fahrenheit temperatures. 
Then mod- ify the temp_stats.cpp program to test each temperature, 
converting the Celsius readings to Fahrenheit before putting them into the vector.
*/

#include "std_lib_facilities.h"
#include "temp_reading.h"


vector<Reading>temp_readings;

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