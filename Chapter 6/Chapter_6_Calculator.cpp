#include "std_lib_facilities.h"


int counter = 0;
class Token_stream {
public:
    char get();
};

char Token_stream::get()
{    
        char ch;
        cin >> ch;        
        return ch;    
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------


int main()
try {   
  
    while (true) {

        vector<int> digits; 


        cout << "Enter an integer up to 4 digits long. Terminate with '|'.\n";
        int n_digits = 0;
        bool end = false;
        char garbage = ' ';        

        while (!end && n_digits < 4) {
            char ch = ts.get();
           
            switch (ch) {
            case'|':
                end = true;
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                digits.push_back(ch - '0');
                n_digits += 1;
                
                break;
            default:
                cout << "Wrong input. Please input numbers only.";
                garbage = ts.get();
                break;
            }
        }

        int vector_size = 0;
        vector_size = digits.size();

        int ones = 0;
        int tens = 0;
        int hundreds = 0;
        int thousands = 0;
       

        for (int i = 0; i < digits.size(); ++i) {
            int index = digits.size() - 1 - i;

            switch (index) {
            case 3:
                thousands = digits[i];
                break;
            case 2:
                hundreds = digits[i];
                break;
            case 1:
                tens = digits[i];
                break;
            case 0:
                ones = digits[i];
                break;
            default:
                error("out of range exponent");
            }
        }

        cout << thousands << " Thousands\n";
        cout << hundreds << " hundreds\n";
        cout << tens << " tens\n";
        cout << ones << " ones\n";
        

        //cout << "Number is:\n";
        //for (int i = 0; i < n_digits; i++) { //n_digits knows how many digits were given
        //    std::cout << digits[i];
        //}
        //cout << '\n';

        //digits = { 1 };     // "reset" vector size


        
        //This would be one "game round"
    }
    

    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}