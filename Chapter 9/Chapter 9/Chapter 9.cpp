// Chapter 9.cpp 
/*

*/

#include "std_lib_facilities.h"

int round_cents(double n)
{
	double d3 = n * 1000;
	double d2 = n * 100;	//isolate last digit from d3
	int d3i = d3;	// truncate d3 to get rid of more than 2 decimal digits
	int d2i = d2;	// truncate d2

	int t = d3i - (d2i*10);		
	int t2 = 10 - t;		//amount needed to round to 10

	if (t >= 5) d3i += t2;
	else { d3i -= t; }	
	d3i/=10;
	return d3i;
}

enum class Currency {
	USD, EUR, CNY
};

class Currency_data
{
public:
	
	struct Data
	{
		Currency id;
		string name;
		double ratio;
	};

	Currency currency(const string& name) const;	// get currency by name
	const string& name(Currency currency) const;	// get name by id
	double ratio(Currency currency) const;			// get ratio to US Dollar
	double ratio(Currency a, Currency b) const;	// get conversion ratio
	bool currency_check(const string& name) const;	//check valid currencies

private:
	static const vector<Data> data;
};

const vector<Currency_data::Data> Currency_data::data{
	Data{Currency::USD, "USD", 1.0},	// id, name, ratio
	Data{Currency::EUR, "EUR", 1.12},
	Data{Currency::CNY, "CNY", 0.15}
};

const Currency_data currency_data{};

// << Currency
ostream& operator<<(ostream& os, const Currency c)
{
	os << currency_data.name(c);
	return os;
}

const string& Currency_data::name(Currency currency) const
{
	for (const Data& d : data)
		if (d.id == currency) return d.name;
}

Currency Currency_data::currency(const string& name) const
{
	for (const Data& d : data)
		if (d.name == name) return d.id;
}

double Currency_data::ratio(Currency currency) const
{
	for (const Data& d : data)
		if (d.id == currency) return d.ratio;
}

double Currency_data::ratio(Currency a, Currency b) const
{
	if (a == b) return 1;
	double cur_a{ currency_data.ratio(a) };
	double cur_b{ currency_data.ratio(b) };
	return (cur_a / cur_b);
}

bool Currency_data::currency_check(const string& name) const
{
	bool found = false;
	for (const Data& d : data) {
		if (d.name == name) return found;
	}
	return false;
}

istream& operator>>(istream & is,  Currency& c)
{
	string cur_id;
	is >> cur_id;
	if (!is) return is;
	bool cur_found = currency_data.currency_check(cur_id);
	
	if (!cur_found) {
		is.clear(ios_base::failbit);
		cout << "Please enter one of the following currencies: (USD, EUR, CNY) \n";
		return is;
	}
	c = currency_data.currency(cur_id);	
}

class Money
{
public:	
	Money(long int amount) : p_amount{ amount } {}
	Money(Currency cur, long int amount) : currency{ cur }, p_amount{ amount }{}

	Money() : currency{ Currency::USD }, p_amount{ 0 } {}

	long int amount() const { return p_amount; }
	long int get_cents()  { return p_amount; }
	double get_dollars()  { return p_amount / 100.0; }
	Currency get_currency() const { return currency; }

private:
	long int p_amount;
	Currency currency;
};




// << Money 
//ostream& operator<<(ostream& os, Money& c)
//{
//	return os << c.get_currency()<<" " << c.get_dollars();
//}

//Money operator+( Money& a, Money& b) {
//	return Money(a.get_currency(), round_cents(a + b) );
//}

// >> Money
//istream& operator>>(istream& is, Money& m)
//{
//	double d;	// dollars
//	string c;	//currency
//
//	is >> c >> d;
//	if (!is) return is;
//
//	int currency = 0;
//	bool cur_found = false;		// validate currency
//	for (int i = 0; i < currency_tbl.size(); ++i) {
//		if (c == currency_tbl[i]) {
//			currency = i;
//			cur_found=true;
//		}
//	}
//	if (!cur_found) {
//		is.clear(ios_base::failbit);
//		cout << "Please enter the following format: USD 0.0 (USD, EUR, CNY) \n";
//		return is;
//	}
//	
//	m = Money(Currency(currency), round_cents(d) );
//
//	return is;
//}



int main()
try
{
	Money m1;
	Money m2;
	Money m3{ Currency::EUR,23 };
	
	cout << m3.get_currency();


	while (cin) {
/*		cout << "Enter first currency ammount:\n";
		cin >> m1;
		cout << m1 << '\n';

		cout << "Enter second currency ammount:\n";
		cin >> m2;
		cout << m2 << '\n';
		m3 = m1 + m2;
		cout << m3<<'\n';	*/	
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