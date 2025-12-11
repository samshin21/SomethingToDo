#include <iostream>
#include <vector>
#include <string>

// having this namespace makes it so we don't have to put 'std::' on everything
using namespace std;

void printUserMenu () {
	// outputting the user menu
	cout << "\n*** What do YOU want to do? ***\n";
	cout << "0. Give me something to do!\n";
	cout << "1. Create something\n";
	cout << "2. Read something\n";
	cout << "3. Update something\n";
	cout << "4. Destroy something\n";
	cout << "5. Exit\n";
}

void printUserList (const vector<string>& todo) {
	if (todo.empty()) {cout << "You have nothing to do";}
	else {
		cout << "Here are some things you could do...\n";
		for (int i = 0; i < todo.size(); i++) {cout << i << ". " << todo[i] << "\n"; }
	}
}

int main () {
	// main function to get user choice
	vector<string> todo;
	int usrChoice = 0;
	
	// infinite loop
	for (;;) {
		// prompting and recieving user input
		printUserMenu();
		cin >> usrChoice;
		cin.ignore();

		// per ChatGPT switch statements are faster when dealing with ints compared tp regular if-else statements
		switch (usrChoice) {
			// Create
			case 1: {
				for(;;) {
					cout << "Enter something to do: ";
					string itemCreate;
					getline(cin, itemCreate);
					todo.push_back(itemCreate);
					cout << "\nDo you want to create something else to do (Yes/no)?\n";
					// going to use this variable name for generic user inputs
					string usr;
					cin >> usr;
					// leaving this loop if usr response does NOT contain 'y' or 'Y'
					if (usr.find("y") == string::npos ||
						usr.find("Y") == string::npos) {break;}
				}
			} break;
			// Read
			case 2:
				printUserList(todo);
				break;
			// Update
			case 3:
				break;
			// Destroy
			case 4:
				break;
			// Exit
			case 5:
				cout << "Goodbye!\n";
				// using return instead of exit() since I'm in the main function
				return 0;
				// good defensive measure even if you don't need the 'break' statement
				break;
			default:
				cout << "Invalid Input\n";
				break;
		}

	}
	return 0;
}

