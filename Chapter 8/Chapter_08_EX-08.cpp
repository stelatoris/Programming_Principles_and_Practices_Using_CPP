// Programming_Principles_CPP-Chapter_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "std_lib_facilities.h"

namespace users_info {
    vector<string>v_name;
    vector<double>v_age;
    string name;
    double age;
}

// enter (name,age) pairs
int enter_values() 
{
    using users_info::name;
    using users_info::age;
    using users_info::v_name;
    using users_info::v_age;

    name = "";
    age = 0;
    bool end_name = false;   

    cout << "Please enter names. When done, enter \"End\"\n";
    while (cin>>name && name!="End" && name!="Exit") {          // enter names
        bool duplicate = false;
        for (int i = 0; i < v_name.size(); ++i) {
            if (name == v_name[i]) {
                cout << "Duplicate name. Please enter a new name\n";
                duplicate = true;               
            }
        }
        if (!duplicate) v_name.push_back(name);
        else {}
    }

    for (int i = 0; i < v_name.size(); ++i) {       // enter Age for each name entered
        cout << "Please enter " << v_name[i] << "'s age: ";
        cin >> age;
        v_age.push_back(age);
    }
    return 0;
}

// prints out vector
void vector_printer(const vector<string>& v_name, const vector<double>& v_age) 
{      
    cout << "\nCurrent users:\n"
        << "\n"
        << "Name, Age\n"
        << "---------\n";
    for (int i = 0; i < v_name.size(); ++i) {

        if (i == v_name.size() - 1) cout <<"("<< v_name[i] <<", \t"<< v_age[i] <<")"<<"\nEND\n";
        else {
            cout <<"("<< v_name[i] << ", \t" << v_age[i] <<")"<< '\n';
        }
    }
}

// sort names in alphabetical order
void vector_sort(vector<string>& v_name, vector<double>& v_age) {

    vector<string>v_name_orig;      //store copy of vector before sorting
    vector<double>v_age_orig;
    v_name_orig = v_name;
    v_age_orig = v_age;

    sort(v_name.begin(), v_name.end());

    for (int i = 0; i < v_name.size(); ++i) {       //compare sorted names vector with unsorted to help sort age appropriatly
        for (int j = 0; j < v_name.size(); ++j) {
            if (v_name[i] == v_name_orig[j]) {
                v_age[i] = v_age_orig[j];
            }
        }
    }
}

int main()

try 
{
    using users_info::name;
    using users_info::age;
    using users_info::v_name;
    using users_info::v_age;
    
    enter_values();
    vector_printer(v_name, v_age);
    vector_sort(v_name, v_age);
    vector_printer(v_name, v_age);  // print sorted names
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
