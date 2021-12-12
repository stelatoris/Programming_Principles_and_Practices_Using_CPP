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

    int value{0};
    int current_value{0};
    int previous_value{0};
    int total_value{0};

    class Roman_int
    {
        public:
        Roman_int( std::string r_num, int n);
        Roman_int() : roman_num{"nulla"}, int_number{0}{}

        int as_int(std::string n);
        int roman_parser(char ch);
        int roman_int_parser(int n);

        std::string roman_num;
        int int_number;
        //void digits_parser(int n);

        int ones;
        int tens;
        int hundreds;
        int thousands;
    };

    Roman_int::Roman_int (std::string r_num, int n)
        : roman_num{r_num}, int_number{n}
    {
    }

}