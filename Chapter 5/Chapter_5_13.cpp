#include "std_lib_facilities.h"

int main()
try {
    // Bulls and Cows
    vector<int> hidden(4);
    
    bool new_game = false;

    cout << "Let's play Bulls & Cows!\n";

    while (!new_game) {

        bool success = false;
        int n = 0;  //to seed randint

        cout << "Please enter any number to generate a random secret number:\n";
        cin >> n;

        seed_randint(n);

        bool vector_full = false;
        int index_count = 0;


        while (!vector_full) {

            if (index_count == 4) {
                vector_full = true;
                break;
            }
            n = randint(10);
            if (n < 10) {
                hidden[index_count] = n;
                index_count += 1;
            }
        }

        for (int i = 0; i < hidden.size(); ++i) {       // to check vector
            cout << hidden[i];
        }
        cout << '\n';

        while (!success) {
            vector<int> guess;

            int bulls = 0;
            int cows = 0;           

            cout << "Guess 4 integers w/o repeating:\n";

            for (int val; guess.size() < 4; ) {
                cin >> val;
                if (!cin) error("Couldn't read integer from input\n");
                guess.push_back(val);
            }

            for (int i = 0; i < guess.size(); ++i)
                for (int j = 0; j < hidden.size(); ++j)
                    if (guess[i] == hidden[j]) {
                        if (i == j)
                            ++bulls;
                        else
                            ++cows;
                    }

            cout << bulls << " bulls, " << cows << " cows.\n";

            if (bulls == 4) success = true;
        }
        cout << "Success!!\n";

       
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
