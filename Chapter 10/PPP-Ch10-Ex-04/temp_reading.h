// temp_reading.h

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