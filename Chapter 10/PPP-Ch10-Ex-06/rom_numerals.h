#include <iostream>
#include <vector> 

namespace Roman_nums {

    constexpr int I=1;
    constexpr int V=5;
    constexpr int X=10;
    constexpr int L=50;
    constexpr int C=100;
    constexpr int D=500;
    constexpr int M=1000;

    class Roman_int
    {
        public:
        Roman_int( std::string r_num, int n);
        Roman_int() : roman_num{"nulla"}, int_number{0}{}

        int as_int();


        std::string roman_num;
        int int_number;
    };

    Roman_int::Roman_int (std::string r_num, int n)
        : roman_num{r_num}, int_number{n}
    {
    }

    //-------------------------------------------------------------

    class Roman_symbol
    {
        public:

        Roman_symbol( char s, int n);
        char symbol;
        int value;
    
    };

    Roman_symbol::Roman_symbol (char s, int n)
        : symbol{s}, value{n}
        {
        }

}