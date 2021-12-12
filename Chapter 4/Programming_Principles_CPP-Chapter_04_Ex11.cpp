// Programming_Principles_CPP-Chapter_04_Ex11.cpp : 

//      Create a program to find all the prime numbers between 1 and 100. One
//      way to do this is to write a function that will check if a number is prime
//      (i.e., see if the number can be divided by a prime number smaller than
//    itself) using a vector of primes in order(so that if the vector is called
//        primes, primes[0] == 2, primes[1] == 3, primes[2] == 5, etc.).Then write a
//    loop that goes from 1 to 100, checks each number to see if it is a prime,
//    and stores each prime found in a vector.Write another loop that lists the
//    primes you found.You might check your result by comparing your vector
//    of prime numbers with primes.Consider 2 the first prime.

#include "std_lib_facilities.h"

vector<int>prime_list = { 2 };

void add_to_prime_list(int n) 
{
    prime_list.push_back(n);
}

int main()
{
    int x = 0;
    int limit = 100;
    int div_x;
    bool not_prime = false;
    bool prime = false;
   
   
        for (int i = 2; i < limit; ++i) {
            x = i;
            //cout << "Trial division for number: " << x << '\n';    //for testing
            for (int i = 2; i < x; ++i) {
                prime = false;
                not_prime = false;
                div_x = x % i;
                //cout << div_x << " ,";                                //for testing

                if (div_x == 0) {
                    not_prime = true;
                    //cout << "bool is " << not_prime << '\n';          //for testing
                    break;
                }
                else {
                    prime = true;;
                }
                //cout << "bool is " << not_prime << '\n';              //for testing
            }
            if (prime == true) {
                add_to_prime_list(x);
            }
        }
        cout << "There are "<< prime_list.size()<<" prime numbers below "<<limit<<": ";
        for (int i = 0; i < prime_list.size(); ++i) { 
            cout << prime_list[i] <<", ";
        }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
