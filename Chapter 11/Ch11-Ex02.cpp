//Programmingm: Principles and Practices Using C++
//Chapter 11 Exercise 02
//Write a program that given a file name and a word outputs each line 
//that contains that word together with the line number. Hint: getline().

#include "std_lib_facilities.h"

const std::string iname{"textsample.txt"};
const std::string keyword{"i/o"};
const std::string whitespace_chars{";:,.-?!()\"{}<>&$@#%^*|~"};

class Punct_stream {

    public:
    Punct_stream(istream& is) : source {is}, sensitive{true} {}         

    void whitespace(const string& s) {white=s;}     // make s the whitespace set
    void add_white(char c) {white+=c;}              // add to the white space set
    bool is_whitespace(char c);                     // is c in the whitespace set?
    void case_sensitive(bool b) { sensitive=b;}     
    bool is_case_sensitive() { return sensitive;}

    Punct_stream& operator>>(std::string& s);
    operator bool();

    private:
        istream& source;        // character source
        istringstream buffer;   // let buffer do our formatting
        string white;           // characters considered "whitespace"
        bool sensitive;         // is the stream case-sensitive?
};

bool Punct_stream::is_whitespace(char c)
{
    for(char w:white)
        if(c==w) return true;
    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail()||source.bad()) && buffer.good();
}

void print_line( int n, const string& line)
{
    std::cout<<"Line "<<n<<": \""
        <<line<<"\"\n";
}

string tolower_string(const string& s)  // converts search keyword to lowercase
{
    string low_s=s;
    for(char& c: low_s)
        c=tolower(c);

    return low_s;
}

Punct_stream& Punct_stream::operator>>(std::string& s)
{
    while(!(buffer>>s)) {               // try to read from buffer
        if(buffer.bad()||!source.good()) return *this;
        buffer.clear();

        std::string line;
        getline(source, line);          // get a line from source

        for(char& ch: line)
            if(is_whitespace(ch))
                ch=' ';                 // to space
            else if(!sensitive)
                ch=tolower(ch);         // to lower case

        buffer.str(line);               //put string into stream
    }
    return *this;
}

void search_words(ifstream& ifs, const string& keyword)
// need to impliment seperating words from puncuation
{ 
    int line_num{0};
    string low_keyword=tolower_string(keyword);
  
    while(!ifs.eof()) {
        string line_input;
        getline(ifs, line_input);
        ++line_num;

        stringstream ss {line_input};
        Punct_stream ps{ss};
        ps.whitespace(whitespace_chars);
        ps.case_sensitive(false);

        for(string s; ps>>s;) 
            if(s==low_keyword)
                print_line(line_num, line_input);                     
    }
}

int main()
try {

    ifstream ifs{iname};
    if(!ifs) error("can't open input file");

    std::cout<<"Search results for word \""<<keyword<<"\":\n";
    search_words(ifs, keyword);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
