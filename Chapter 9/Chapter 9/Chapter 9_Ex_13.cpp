// Chapter 9.cpp 
/*
 13. Design and implement a rational number class, Rational. A rational
number has two parts: a numerator and a denominator, for example, 5/6
(five-sixths, also known as approximately .83333). Look up the definition
if you need to. Provide assignment, addition, subtraction, multiplication,
division, and equality operators. Also, provide a conversion to double.
Why would people want to use a Rational class?
*/

#include "std_lib_facilities.h"

int gcd(int a, int b)
{
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

class Rational
{
public:
	Rational(int n, int d);
	Rational(int n) :numerator{n}, denominator{ 1 }{}
	Rational() : numerator{ 0 }, denominator{ 1 } {}

    
	int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }

	double rat_convert() const { return double (numerator) / denominator; }
	void reduce_ration();

private:
    int numerator;
    int denominator;
};

Rational::Rational(int n, int d)
    :numerator{ n }, denominator{ d }
{
	if (denominator == 0) error("denominator cannot be 0");
}

ostream& operator<<(ostream& os, const Rational& n)
{
    return os << n.get_numerator() << '/' << n.get_denominator();
}

istream& operator>>(istream& is, Rational& n)
{
	int numer, denomin;
	char ch1;
	is >> numer >> ch1 >> denomin;
	if (!is) return is;
	if (ch1 != '/') {
		is.clear(ios_base::failbit);
		cout << "Please enter the following format: (n1/n2)\n";
		return is;
	}
	n = Rational(numer, denomin);
	return is;
}

bool operator==(const Rational& a, const Rational& b)
{
	return a.get_numerator() == b.get_numerator()
		&& a.get_denominator() == b.get_denominator()
		|| (a.get_numerator() * b.get_denominator()) == (a.get_denominator() * b.get_numerator());
}

Rational operator+(const Rational& a, const Rational& b)
{
	if (a.get_denominator() == b.get_denominator()) {
		Rational r((a.get_numerator() + b.get_numerator()), a.get_denominator());
		r.reduce_ration();
		return r;
	}
	Rational r((a.get_numerator() * b.get_denominator()) + (a.get_denominator() * b.get_numerator())
		, a.get_denominator() * b.get_denominator());
	r.reduce_ration();
	return r;
}

Rational operator-(const Rational& a, const Rational& b)
{
	if (a.get_denominator() == b.get_denominator()) {
		Rational r((a.get_numerator() - b.get_numerator()), a.get_denominator());
		r.reduce_ration();
		return r;
	}
	Rational r((a.get_numerator() * b.get_denominator()) - (a.get_denominator() * b.get_numerator())
		, a.get_denominator() * b.get_denominator());
	r.reduce_ration();
	return r;
}

Rational operator*(const Rational& a, const Rational& b)
{
	Rational r((a.get_numerator() * b.get_numerator()), (a.get_denominator() * b.get_denominator()));
	r.reduce_ration();
	return r;
}

Rational operator/(const Rational& a, const Rational& b)
{
	if (a.get_denominator() != 0 || b.get_numerator() != 0 || b.get_denominator() != 0) {
		Rational r((a.get_numerator() * b.get_denominator()), (a.get_denominator() * b.get_numerator()));
		r.reduce_ration();
		return r;
	}
	
}

void Rational::reduce_ration()
{ 
	int n = 0;
	n=gcd(numerator, denominator);
	numerator = numerator / n;
	denominator = denominator / n;
}

int main()
try
{

	Rational num1;
	Rational num2;
	Rational num3;
	Rational num4{ 5,6 };
	num4 = { 3, 8 };

	cout << num4 << '\n';
	num4 = { 3 , 4 };

	cout << num4 << '\n';
	cout << "Enter number1: n/d\n";
	cin >> num1;
	cout << "Enter number2: n/d\n";
	cin >> num2;

	num3 = num1 + num2;
	cout << num1 << " + " << num2 << " = " << num3 << '\n';	

	num3 = num1 - num2;
	cout << num1 << " - " << num2 << " = " << num3 << '\n';

	num3 = num1 * num2;
	cout << num1 << " * " << num2 << " = " << num3 << '\n';

	num3 = num1 / num2;
	cout << num1 << " / " << num2 << " = " << num3 << '\n';

	cout << "Converted double: " << num3.rat_convert() << '\n';

	if (num1 == num2) {
		cout << num1 << " = " << num2 << '\n';
	}
	else{ cout << num1 << " != " << num2 << '\n'; }


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
