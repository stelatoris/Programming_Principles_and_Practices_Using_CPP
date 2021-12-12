
/*
5. Write the function print_year() mentioned in §10.11.2.
*/

#include "std_lib_facilities.h"


constexpr char kFah{'f'};
constexpr char kCel{'c'};
const int not_a_reading=-7777;
const int not_a_month=-1;
constexpr int implausible_min=-200;
constexpr int implausible_max=200;

const std::string kFile_name{"raw_temps.txt"};
const std::string temps_input{"temp_input.txt"};
const std::string temps_ouput{"temp_output.txt"};

//------------------------------------------------------------
struct Day 
{
   Day(const vector<double>& h);
   Day() : hour{vector<double>(24, not_a_reading)}{}

   vector<double>hour;
};

Day::Day(const vector<double>& h) : hour{h} 
{
}

//------------------------------------------------------------

struct Month	// month of temperature readings
{
	Month (int m, const vector<Day>& d);
	Month () : month{not_a_month}, day{32} {} 

	int month {not_a_month};	// January is 0
	vector<Day> day {32};		//[1:31] one vector per day matching index number
};

Month::Month (int m, const vector<Day>& d)
	: month{m}, day{d}
{
}

//------------------------------------------------------------

struct Year		// a year of temperature readinsm organized by months
{
	Year (int y, const vector<Month>& m);
	Year () : year{-1}, month{12} {}
	int year;
	vector<Month> month{12};	//[0:11] January is 0
};

Year::Year (int y, const vector<Month>& m)
	: year{y}, month{m}
{
}

//------------------------------------------------------------

struct Reading
{
	Reading (int d, int h, double t, char u );
	Reading () : day{1}, hour{0}, temperature{-7777}, unit{'f'} {}
	
	int day;
	int hour;
	double temperature;
	char unit;
};

Reading::Reading (int d, int h, double t, char u)
	: day{d}, hour{h}, temperature{t}, unit{u}
{	
}

//------------------------------------------------------------

bool is_valid(const Reading& r)
{
	if (r.day<1||31<r.day) return false;
	if (r.hour<0||23<r.hour) return false;
	//if (r.unit==kFah||r.unit==kCel) return true;
	if(r.temperature<implausible_min||implausible_max<r.temperature)
		return false;
	return true;
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

std::istream& operator>>(std::istream& is, Reading& r)	//(1 1 60.5) reading template
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
	double t;
	is>>d>>h>>t>>u>>ch2;
	if(!is||ch2!=')') error("bad reading in istream& 'Reading' operator>>");
	r.day=d;
	r.hour=h;
	r.temperature=t;
	r.unit=u;
	end_of_loop(is, '|', "bad end of file");
	return is;
}

//-------------------------------------------------------

vector<std::string> month_input_tbl={
	"jan", "feb", "mar", "apr", "may", "jun",
	 "jul", "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(std::string s)
{
	for(int i=0;i<12;++i) if(month_input_tbl[i]==s) return i;
	return -1;
	
}

vector<std::string> month_print_tbl={
	"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December" 
};

std::string int_to_month(int i)
// months [0:11]
{
	if(i<0||12<i) error("bad month index");
	return month_print_tbl[i];
}

std::ostream& operator<<(ostream& os, Reading r)
{
	return os<<'('<<r.day
			<<' '<<r.hour
			<<' '<<r.temperature
			<<' '<<r.unit<<')';
}

std::ostream& operator<<(ostream& os, Day d)
// (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)
{
	if(d.hour.size()!=24) error("Day 'hour' vector size not 24");
	for(int i=0;i<24;++i) {
		os<<'('<<i<<' '<<d.hour[i]<<')';
	}
	return os;

}

std::ostream& operator<<(ostream& os, Month m)
// {year 2000
// { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}
// {month dec (15 15 –9.2 ) (15 14 –8.8) (14 0 –2) } }
{
	os<<"{ month "<<m.month<<' ';
	if(m.day.size()!=32) error("Month 'day' vector size not 32");
	for(int i=1;i<32;++i) {
		os<<" Day "<<i<<' '<<m.day[i]<<'}';
	}
	return os;
}

std::ostream& operator<<(ostream& os, Year y)
// { year 1990 } {year 1991 { month jun }}
{
	os<<"{ year "<<y.year<<' ';
	if(y.month.size()!=12) error("Year 'month' vector size not 12");
	for(int i=0;i<12;++i) {
		os<<' '<<y.month[i]<<'}';
	}
	return os;
}

/*
struct Year		// a year of temperature readinsm organized by months
{
	Year (int y, vector<Month> m);
	Year () : year{-1}, month{12} {}
	int year;
	vector<Month> month{12};	//[0:11] January is 0
};

Year::Year (int y, vector<Month> m)
	: year{y}, month{m}
{
}
*/

//--------------------------------------------------



std::istream& operator>>(istream& is, Month& m)
// format: { month feb...}
{
	char ch=0;
	if(is>>ch&&ch!='{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	std::string month_marker;
	std::string mm;
	is>>month_marker>>mm;
	if(!is||month_marker!="month") error("bad start of month");
	m.month=month_to_int(mm);
	int duplicates=0;
	int invalids=0;
	for(Reading r; is>>r;) {
		if (is_valid(r)) {
			if(m.day[r.day].hour[r.hour]!=not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour]=r.temperature;
		}
		else
			++invalids;
	}
	if(invalids) error("invalid readings in month", invalids);
	if(duplicates) error("duplicate readins in month", duplicates);
	end_of_loop(is,'}',"bad end of month");
	return is;
}

std::istream& operator>>(std::istream& is, Year& y)
// format: { year 1972 . . . }
{
	char ch;
	is>>ch;
	if(ch!='{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	
	std::string year_marker;
	int yy;
	is>>year_marker>>yy;
	if(!is||year_marker!="year") error("bad start of year");
	y.year=yy;

	while(true) {
		Month m;
		if(!(is>>m)) break;
		y.month[m.month]=m;
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}



vector<Reading> new_temp_readings;		//vector to hold readings from file
vector<Reading> c_temp_readings;

Reading convert_temp(const Reading& r, char u)		// char u is either 'f' or 'c'
{
	Reading c=r;	//celcius
	if(u==kFah&&r.unit==kFah) return r;	//fehrenheit
	else if(u==kFah&&r.unit==kCel) {	// c to f
		c.unit=kFah;
		c.temperature=(c.temperature*(9.0/5.0))+32; // (0°C × 9/5) + 32 = 32°F
		return c;
	}
	else if(u==kCel&&r.unit==kFah) {	// f to c
		c.unit=kCel;
		c.temperature=((c.temperature-32)*(5.0/9.0));	//(32°F − 32) × 5/9 = 0°C type 5.0/9.0 for double
		return c;

	}
	else if(u==kCel&&r.unit==kCel) return r;	// Celcius to Celcius
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

void print_year(std::ofstream &ost, Year y) {

    ost << y.year << ":\n";
    for (Month m : y.month)
        if (m.month != not_a_month) {
            ost << '\t' << int_to_month(m.month) << '\n';
			ost<<"\t\tDay     Hour    Temperature\n";

            for (int d = 1; d < m.day.size(); ++d)
                for (int h = 0; h < m.day[d].hour.size(); ++h)

                    if (m.day[d].hour[h] != not_a_reading)
                        ost << "\t\t" << d << "\t\t" << h << "\t\t"
                            << m.day[d].hour[h] << '\n';
        }
}

int main()
try 
{
	/*
	file_to_vector(new_temp_readings, kFile_name, kFah);

	std::cout<<"Temperature readings from raw_temp.txt:\n";
	for(Reading& r: new_temp_readings)
		std::cout<<r<<'\n';

	std::cout<<"Mean temperature is "<<mean_temperature(new_temp_readings)<<" degrees.\n";

	std::cout<<"Median temperature is "<<median_temperature(new_temp_readings)<<'\n';
	
	std::cout<<"Converting f to c: \n";
	file_to_vector(c_temp_readings, kFile_name, kCel);
	for(Reading& r: c_temp_readings)
		std::cout<<r<<'\n';
		*/

	// open an input file:
	
	//cout << "Please enter input file name\n"; string iname;
	//cin >> iname;
	ifstream ifs {temps_input};
	if (!ifs) error("can't open input file",temps_input);

	ifs.exceptions(ifs.exceptions()|ios_base::badbit);

	// open an output file:
	//cout << "Please enter output file name\n"; string oname;
	//cin >> oname;
	ofstream ofs {temps_ouput};
	if (!ofs) error("can't open output file",temps_ouput);

	// read an arbitrary number of years: 
	vector<Year> ys;
	while(true) {
		Year y; // get a freshly initialized Year each time around 
		if (!(ifs>>y)) break;
		ys.push_back(y);
	}

	cout << "read " << ys.size() << " years of readings\n";
	
	//for (Year& y: ys) cout<<y<<'\n'; 
	for (Year& y : ys) print_year(ofs,y);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}