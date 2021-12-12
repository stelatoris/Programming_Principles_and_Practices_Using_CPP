#include "std_lib_facilities.h"

vector<double>price = { 2.99,5.99,3.99,9.99,0.99,14.99,1.99 };
vector<double>weight = { 2,2.2,1.5,3,2,1.3,4 };
vector<string>some_words = { "one","two","three","four","five","six","seven","six","five","four","three","two","one" };

struct Vector_properties {
	double smallest=0;
	double largest = 0;
	double mean=0;
	double median=0;
};

double compute_sum(const vector<double>& price, const vector<double>& weight)
{
	double sum = 0;
	if (price.size() != weight.size()) error("Unequal vector sizes!");
	else {
		for (int i = 0; i < price.size(); ++i) {
			sum += price[i] * weight[i];
		}
	}
	return sum;
}

double maxv(const vector<double>& v)
{
	if (v.size() == 0) error("maxv: argument vector is empty");
	double largest = v[0];
	if (v.size() == 1) return largest;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > largest) largest = v[i];
	}
	return largest;
}

Vector_properties get_data(const vector<double>& v)
{
	Vector_properties data;
	vector<double>copy = v;
	sort(copy);
	double sum = 0;

	for (int i = 0; i < copy.size(); ++i) {
		sum += copy[i];
	}

	data.smallest = copy[0];
	data.largest = copy[copy.size() - 1];
	data.median = copy[copy.size() / 2];
	data.mean = sum / copy.size();

	return data;
}

void print_until_s(vector<string>v, string quit)
{
	for (string s : v) {
		if (s == quit)return;
		cout << s << '\n';
	}
}

void print_until_ss(vector<string>v, const string& quit)
{
	int count = 0;
	for (const string& s : v) {
		
		if (s == quit) ++count;
		if (count == 2) return;
		cout << s << '\n';
	}
}


vector<int> get_lengths(const vector<string>& v)
{
	vector<int> lengths;

	for (string str : v)
		lengths.push_back(str.size());

	return lengths;
}

int main()
try
{
	
	//print_until_ss(some_words, "five");

	cout << "Number of characters in each string of vector:\n";
	vector<int>lengths = get_lengths(some_words);
	for (int i = 0; i < lengths.size(); ++i) {
		cout << some_words[i] << " has " << lengths[i] << " characters.\n";
	}

	int count_chars = 0;
	string temp_string = "abracadabra";
	count_chars = temp_string.size();
	cout << temp_string << " has " << count_chars << " characters.\n";

	/*Vector_properties data = get_data(price);


	cout << "Sum of price*weight=" << compute_sum(price, weight) << '\n';
	//cout << "Largest element of vector is " << maxv(weight) << '\n';

	cout << "Smallest element of vector is " << data.smallest << '\n';
	cout << "Largest element of vector is " << data.largest << '\n';
	cout << "Median element of vector is " << data.median << '\n';
	cout << "Mean value of vector elements is " << data.mean << '\n';

	vector<double>copy = price;
	sort(copy);
	cout << "Vector:\n";
	for (int i = 0; i < copy.size(); ++i) {
		cout << copy[i] << ", ";
	}*/
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}