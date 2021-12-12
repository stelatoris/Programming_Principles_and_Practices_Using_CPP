#include "std_lib_facilities.h"

class Name_value {
	public:
		string name;
		string score;
		Name_value(string n, string s)
			:name(n), score(s) {}
};


int main()
{
	vector<Name_value>record;

	bool quit = false;
	bool repeat = false;


	while (!quit) {
		cout << "Please enter a name and a number\n";
		string name;
		string score;
		cin >> name >> score;

		if (name == "NoName" && score == "0") {
			cout << "RESULTS:\n";

			for (Name_value n:record) {
				cout << "(" << n.name << " " << n.score << ")" << '\n';
			}
			quit = true;
		}
		else {
			for (Name_value n : record) {
				if (n.name == name) {
					repeat = true;
				}
			}
			if (repeat) {
				cout << "Error: duplicate number.\n";
				repeat = false;
			}
			else {
				record.push_back(Name_value{ name, score });				
			}
		}
	}

	while (cin) {

		string query = "";
		cout << "Who's score would you like to look up?\n";
		cin >> query;

		bool match = false;
		bool search_score = false;
		int log = 0;

		for (int i = 0; i < record.size();++i) {		// search by name
			if (record[i].name == query) {
				match = true;
				log = i;
			}
		}

		for (int ii = 0; ii < record.size();++ii) {		// search by score
			if (record[ii].score == query) {
				match = true;
				search_score = true;
				log = ii;
			}
		}

		if (match == false) {
			cout << "name not found\n";
		}
		else if (search_score == true) {
			cout << record[log].name << "'s score is " << record[log].score << '\n';
		}
		else {
			cout << query << "'s score is " << record[log].score << '\n';
		}
	}
}