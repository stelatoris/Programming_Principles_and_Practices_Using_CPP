//10. Write a program that plays the game “Rock, Paper, Scissors.” If you are not
//familiar with the game do some research(e.g., on the web using Google).
//Research is a common task for programmers.Use a switch - statement to
//solve this exercise.Also, the machine should give random answers(i.e.,
//	select the next rock, paper, or scissors randomly).Real randomness is too
//	hard to provide just now, so just build a vector with a sequence of values
//	to be used as “the next value.” If you build the vector into the program,
//	it will always play the same game, so maybe you should let the user enter
//	some values.Try variations to make it less easy for the user to guess
//	which move the machine will make next.

#include "std_lib_facilities.h"



vector<char>sequence = { 's','p','s','r','s','p','s','p','s' };

void instructions() {
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "******************************INFORMATION - HOW TO PLAY***********************************************\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << '\n';
	cout << "\t\tTo play this game, each player simultaneously chooses one of three items.\n"
		<< "\t\tThese items are \"Rock,\" \"Paper,\" and \"scissors\"\n"
		<< "\t\tA player who decides to play rock will beat another player who has chosen \n"
		<< "\t\tscissors (\"rock crushes scissors\" or sometimes \"blunts scissors\"), \n"
		<< "\t\tbut will lose to one who has played paper (\"paper covers rock\"); \n"
		<< "\t\ta play of paper will lose to a play of scissors (\"scissors cuts paper\").\n";
	cout << '\n';
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << '\n';
	cout << "Choose one to start: (R)ock, (P)aper, (S)cissors, or (q) to quit.\n";

}


		

string machine_input(int i) {
	string result="";
	switch (sequence[i]) {
	case 'r':
		result = "rock";
		break;
	case 'p':
		result = "paper";
		break;
	case 's':
		result = "scissors";
		break;
	default:
		break;
	}
	return result;
}

void print_score(int machine_score, int player_score) {
	cout<<"Score:\tComputer: " << machine_score << '\t' << "Player: " << player_score << '\n';
}

int main()
{
	string you_win("You win.\n");
	string i_win("I win!\n");
	string again("Let's go again!\n");

	int player_score = 0;
	int machine_score = 0;

	char player_item;
	char machine_item{};

	int machine_play_num = 0;

	cout << "Let's play Rock, Paper, Scissors!\n";
	cout << "For instructions on how to play, press (i).\n";
	cout << '\n';
	cout << "Choose one to start: (R)ock, (P)aper, (S)cissors, or (q) to quit.\n";

	while (cin >> player_item) {
	
		machine_item = sequence[machine_play_num];

		int state = 0;
		if (player_item == machine_item) {
			state = 'd';
		}
		else {
			state = player_item;
		}

		switch (state) {

		case'd':
			cout << "It's a draw!\n";
			print_score(player_score, machine_score);
			cout << again;
			machine_play_num += 1;
			sequence.push_back(player_item); // to add randomness to computer moves
			break;
		case'r':
			cout << "I played " << machine_input(machine_play_num) << '\n';
			cout << "You played Rock!\n";
			if (machine_item == 'p')
			{
				machine_score += 1;
				cout << i_win;
			}
			else {
				player_score += 1;
				cout << you_win;
			}
			print_score(player_score, machine_score);
			cout << again;
			machine_play_num += 1;
			sequence.push_back(player_item); // to add randomness to computer moves

			break;

		case'p':
			cout << "I played " << machine_input(machine_play_num) << '\n';
			cout << "You played Paper!\n";
			if (machine_item == 's')
			{
				machine_score += 1;
				cout << i_win;
					
			}
			else {
				player_score += 1;
				cout << you_win;
			}
			print_score(player_score, machine_score);
			cout << again;
			machine_play_num += 1;
			sequence.push_back(player_item); // to add randomness to computer moves
			break;
		case's':
			cout << "I played " << machine_input(machine_play_num) << '\n';
			cout << "You played Scissors!\n";
			if (machine_item == 'r')
			{
				machine_score += 1;
				cout << i_win;
			}
			else {
				player_score += 1;
				cout << you_win;
			}
			print_score(player_score, machine_score);
			cout << again;
			machine_play_num += 1;
			sequence.push_back(player_item); // to add randomness to computer moves
			break;
		case'q':
			cout << "Oh too bad. But thanks for playing!\n";
			exit(1);
			break;
		case'i':
			instructions();
			break;
		case'v':  //prints out Vector values
			for (int i = 0; i < sequence.size(); ++i) {
				cout << i << ":" << sequence[i] << " ";
			}
			cout << '\n';
			break;
		default:
			cout << "Sorry, I don't recognise your choice. Please choose one of the following items: (R)ock, (P)aper, or (S)cissors.\n";
			break;

	}
		
		
}
}