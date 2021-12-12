#include "std_lib_facilities.h"

int main()
{
	vector<string>v_names;
	vector<string>v_scores;

	string names="";
	string scores = "0";
	bool quit = false;
	bool repeat = false;

	
	while (!quit){
		cout << "Please enter a name and a number\n";
		cin >> names>> scores;

		if (names=="NoName"&&scores=="0"){
			//cout << "RESULTS:\n";

			//for (int i = 0; i < v_names.size(); i++) {
			//	cout << "(" << v_names[i] << " " << v_scores[i] << ")" << '\n';
			//}
			quit=true;
		}
		else {
			for (string n : v_names) {
				if (n == names) {
					repeat = true;
				}				
			}
			if (repeat) {
				cout << "Error: duplicate number.\n";
				repeat = false;
			}
			else {
				v_names.push_back(names);
				v_scores.push_back(scores);
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

		for (int i = 0; i < v_names.size(); ++i) {
			if (v_names[i] == query) {
				match = true;
				log = i;
			}

		}
		for (int ii = 0; ii<v_scores.size(); ++ii) {
			if (v_scores[ii] == query) {
				match = true;
				search_score = true;
				log = ii;
			}
		}

		if (match == false) {
			cout << "name not found\n";
		}
		else if (search_score == true) {
			cout << v_names[log] << "'s score is " << v_scores[log] << '\n';
		}
		else {
			cout << query << "'s score is " << v_scores[log] << '\n';
		}

	}

	
	


	



}