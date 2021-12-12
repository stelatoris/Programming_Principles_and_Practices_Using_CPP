// Chapter 9.cpp 
/*

*/

#include "std_lib_facilities.h"

int round_cents(double n)
{
	double d3 = n * 1000;
	double d2 = n * 100;
	int d3i = d3;	// get rid of more than 2 decimal digits
	int d2i = d2;	

	int t = d3i - (d2i*10);		
	int t2 = 10 - t;		//amount needed to round to 10

	if (t > 4) d3i += t2;
	else { d3i -= t; }
	
	d3i/=10;
	return d3i;
}

class Money
{
public:

	long int cents;
	double dollars;


	Money(long int cents);

	Money() : cents{ 0 } {}

	int get_cents() { return cents; }
	double get_dollars() { return cents / 100.0; }


	//bool operator <(const Money& d); 
	//bool operator >(const Money& d);

};

Money::Money(long int m)
	: cents{ m }
{
}



ostream& operator<<(ostream& os, Money& c)
{

	return os << '$' << c.get_dollars();
}

istream& operator>>(istream& is, Money& m)
{
	double d;
	char ch1;
	is >> d;
	//is >> ch1 >> d;
	if (!is) return is;
	/*if (ch1 != '$') {
		is.clear(ios_base::failbit);
		cout << "Please enter the following format: $0.0 \n";
		return is;
	}*/
	m = Money( round_cents(d) );

	return is;
}

int main()
try
{
	Money m1;

	while (cin) {
		cout << "Enter dollar amount:\n";
		cin >> m1;
		cout << m1 << '\n';
		cout << m1.get_cents()<<'\n';
	}




}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}


//

//
//bool Money::operator <(const Money& d) {
//	if (cents < d.cents) {
//		return true;
//	}
//	if (cents == d.cents) {
//		return true;
//	}
//	return false;
//}
//
//bool Money::operator >(const Money& d) {
//	if (cents > d.cents) {
//		return true;
//	}
//	if (cents == d.cents) {
//		return true;
//	}
//	return false;
//}