// Programming_Principles_CPP-Chapter_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "std_lib_facilities.h"


vector<double>v_fibonacci;
vector<double>V_fibonacci_reveresed;

void fibonacci(double x, double y, vector<double>& v, int n) {

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = x + y;
        v.push_back(sum);
        x = y;
        y = v[v.size() - 1];
    }
}

void vector_printer(string label, vector<double>& v) {
    cout << label<<":\n";
    for (int i = 0; i < v.size(); ++i) {

        if (i == v.size() - 1) cout << v[i] << "\n END\n";
        else {
            cout << v[i] << '\n';
        }
    }
}

void vector_reverse(vector<double>& v) {
    for (int i = v.size() - 1; i > -1; --i) {
        V_fibonacci_reveresed.push_back(v[i]);
    }
}

void vector_rev_swap(vector<double>& v) {       // reverse vector using swap()
    for (int i = 0; i < v.size() / 2; ++i) {    // stop as it reaches middle of vector
        swap(v[i], v[v.size()-1-i]);
    }
}



int main()
{
    int n_fibon = 0;        // number of Fibonacci elements
    cout << "Please enter the number of Fibonacci numbers you would like printed.";
    cin >> n_fibon;

    fibonacci(1, 2, v_fibonacci, n_fibon);
    vector_printer("Fibonacci numbers", v_fibonacci);

    //vector_reverse(v_fibonacci);
    //vector_printer("Fibonacci numbers reversed", V_fibonacci_reveresed);

    vector_rev_swap(v_fibonacci);
    vector_printer("Fibonacci numbers reversed", v_fibonacci);

    return 0;
}
