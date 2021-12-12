#include "../std_lib_facilities.h"

int main() {
	double grains = 1;
	double grains_asked;
	double grains_total = 0;

	cout << "How many grains do you want?";

	cin >> grains_asked;

	int vi = 0;

	while (grains_total < grains_asked && vi < 64) {
		grains_total += grains;
		grains = grains * 2;
		++vi;
	}

	cout << "You will get " << grains_asked << " grains from " << vi << " squares\n";
}