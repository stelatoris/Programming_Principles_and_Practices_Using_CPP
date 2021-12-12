// Chapter 4 Ex 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

vector<double>v_numbers;

vector<double>v_prime_numbers;

int main()
{
    double max = 0;
    double number;
    double multiple;
    double vec;
    double prime_num;

    cout << "Please enter the highest number you'd like to list the prime numbers:\n";
    cin >> max;
    
    for (int i = 0; i < max; ++i) {
        v_numbers.push_back(i);

    }

    for (int i= 2; i < max; ++i) { // p
        number = i;
        
        for (int i = 2; i < max; ++i) { // p*i, p*i+1, p*i+3 etc
            vec = i - 2;
            multiple = number * i;
            if (multiple < max) {
               v_numbers[(multiple)] = 1;
                cout << "multiple=" << multiple << "\n";
            }
            else {
                break;
            }
            
                

        }
       

       
    }

    for (int i = 0; i < max; ++i) {
        if (v_numbers[i] != 1) {
            prime_num = v_numbers[i];
            v_prime_numbers.push_back(prime_num);
        }
        else {}
    }

    //for (int i = 0; i < max; ++i) {
    //    cout <<"index:"<<i<<":"<< v_numbers[i] << "\n ";
    //}

    
    for (int i = 0; i < v_prime_numbers.size(); ++i) {
        cout << "Prime number index:" << i << ":" << v_prime_numbers[i] << "\n ";
    }

}
