//
//5.    Write a program that performs as a very simple calculator.Your calculator
//      should be able to handle the four basic math operations — add, subtract,
//      multiply, and divide — on two input values.Your program should prompt
//      the user to enter three arguments : two double valuesand a character to
//      represent an operation.If the entry arguments are 35.6, 24.1, and '+', the
//      program output should be The sum of 35.6 and 24.1 is 59.7.In Chapter 6
//      we look at a much more sophisticated simple calculator.



#include "../std_lib_facilities.h"


double calc(double x, double y, char oper) {

    if (oper == '+') {
        return x + y;
    }
    else if (oper == '-') {
        return x - y;
    }
    else if (oper == '*') {
        return x * y;
    }
    else if (oper == '/') {
        return x / y;
    }
    else {
        cout << "Please select only one of the following operators: +, -, *, /\n";
    }
}

int main()
{

    double val1;
    double val2;
    char oper;
    double result;

    cout << "Please enter two double values and one of the following operators: +, -, *, /\n";
    while (cin >> val1 >> oper >> val2) {

        cout << "=";
        cout << calc(val1, val2, oper) << '\n';
        cout << '\n';
        cout << "Please enter two double values and one of the following operators: +, -, *, /\n";
    }

    return 0;
}

