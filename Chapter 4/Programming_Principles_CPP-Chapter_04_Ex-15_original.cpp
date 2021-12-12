// Chapter 4 Ex 13.cpp : Find prime numbers using “Sieve of Eratosthenes.”

#include "std_lib_facilities.h"

vector<double>v_numbers;

vector<double>v_prime_numbers;

int main()
{
    double max = 0;
    double number;
    double multiple;
    double prime_num;
    double n = 0;

    cout << "Enter the number of prime numbers you'd like to be listed?\n";
    cin >> n;

    max = n * 10;

    for (int i = 0; i < max; ++i) {
        v_numbers.push_back(i);
    }

    for (int i = 2; i < max; ++i) { // p
        for (int ii = 2; ii < max; ++ii) { // p*ii, p*ii+1, p*ii+2 etc
            multiple = (i * ii);
            if (multiple >= max) {
                break;
            }
            v_numbers[(multiple)] = 1;
            //cout << "multiple=" << multiple << "\n";  // to check if it works
        }
    }

    for (int i = 0; i < max; ++i) {
        if (v_numbers[i] != 1) {
            prime_num = v_numbers[i];
            v_prime_numbers.push_back(prime_num);
        }
    }

    for (int i = 0; i <= n; ++i) {
        cout << i << ": " << v_prime_numbers[i] << "\n ";
    }
}