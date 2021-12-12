// Programming_Principles_CPP-Chapter_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "std_lib_facilities.h"



namespace users_info {
    vector<string>v_name;
    vector<double>v_age;
    string name;
    double age;
}

void vector_printer(const vector<string>& v_name, const vector<double>& v_age) {      // prints out vector
    cout << "Current users:\n"
        << "\n"
        << "Name, Age\n"
        << "---------\n";
    for (int i = 0; i < v_name.size(); ++i) {

        if (i == v_name.size() - 1) cout << v_name[i] <<", "<< v_age[i] <<"\n END\n";
        else {
            cout << v_name[i] << ", \t" << v_age[i] << '\n';
        }
    }
}

void vector_rev_swap(vector<string>& v) {       // reverse vector using swap()
    for (int i = 0; i < v.size() / 2; ++i) {    // stop as it reaches middle of vector
        swap(v[i], v[v.size()-1-i]);
    }
}

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
    name = "";
    age = 0;
    int i_name = 0;

    cout << "Please enter 5 names:";
    while (i_name < 5) {
        cin >> name;
        v_name.push_back(name);
        i_name += 1;
    }

    for (int i = 0; i < v_name.size(); ++i) {
        cout << "Please enter " << v_name[i] << "'s age: ";
        cin >> age;
        v_age.push_back(age);
    }

    vector_printer(v_name, v_age);

    vector_sort(v_name, v_age);

    vector_printer(v_name, v_age);


    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
