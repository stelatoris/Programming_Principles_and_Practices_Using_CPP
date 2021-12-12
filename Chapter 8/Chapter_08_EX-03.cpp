// Programming_Principles_CPP-Chapter_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "std_lib_facilities.h"




vector<int>v_fibonacci;

void fibonacci(int x, int y, vector<int>& v, int n) {

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = x + y;
        v.push_back(sum);
        x = y;
        y = v[v.size() - 1];
    }
}

void vector_printer(string label, vector<int>& v) {
    cout << label<<": ";
    for (int i = 0; i < v.size(); ++i) {

        if (i == v.size() - 1) cout << v[i] << ".\n";
        else {
            cout << v[i] << ", ";
        }
    }
}

int main()
{
    int n_fibon = 0;        // number of Fibonacci elements
    cout << "Please enter the number of Fibonacci numbers you would like printed.";
    cin >> n_fibon;

    fibonacci(1, 2, v_fibonacci, n_fibon);
    vector_printer("Fibonacci numbers", v_fibonacci);

    return 0;
}
