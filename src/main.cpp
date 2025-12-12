#include <iostream>
#include <vector>
#include <string>
#include <limits>

// having this namespace makes it so we don't have to put 'std::' on everything
using namespace std;

// DO NOT USE YET
struct ItemData {
	string item;
	double weight;
};

// outputting user menu
void printUserMenu () {
	cout << "\n--- What do YOU want to do? ---\n";
	cout << "0. Give me something to do!\n";
	cout << "1. Create something\n";
	cout << "2. Read something\n";
	cout << "3. Update something\n";
	cout << "4. Destroy something\n";
	cout << "5. Exit\n";
}

// printing user somethingToDo list
void printUserList (const vector<string>& todo) {
	if (todo.empty()) {
		cout << "You have nothing to do";
	}
	else {
		for (int i = 0; i < todo.size(); i++) {
			cout << i << ". " << todo[i] << "\n";
	      	}
	}
}

int main () {
	// main function to get user choice
	vector<string> todo;
	int usrChoice;
	bool validInput = false;
	
	// infinite loop
	for (;;) {
		// prompting and recieving user input
		printUserMenu();
		
		// error handling for incorrect input type
		while (!validInput) {
			if (cin.fail()) {
				cout << "\n*** INVALID INPUT: EXPECTING INTEGER ***\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				validInput = true;
				cin >> usrChoice;
			}
		}
		validInput = false;

		// per ChatGPT switch statements are faster when dealing with ints compared tp regular if-else statements
		switch (usrChoice) {
			// Create
			case 1: {
					cout << "Enter something to do: ";
					string itemCreate;
					getline(cin >> ws, itemCreate);
					todo.push_back(itemCreate);
					cout << "Added something to do\n";
				} break;
			// Read
			case 2:
				cout << "Here are some things you could do...\n";
				printUserList(todo);
				break;
			// Update
			case 3: {
					cout << "Here is your current to do list...\n";
					printUserList(todo);
					cout << "which index do you want to update?\n";
					int index;
					cin >> index;
					// error handling for user input
					while (!validInput) {
						if (cin.fail()) {
							cout << "\n*** INVALID INPUT: EXPECTING INTEGER ***\n";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							validInput = true;
							cin >> usrChoice;
						}
					}
					validInput = false;
					
					// checking to see if index is within the todo list
					if (index >= 0 && index < todo.size()) {
						cout << "Enter the updated task: ";
						string itemUpdate;
						getline(cin, itemUpdate);
						todo[index] = itemUpdate;
					}
					else {
						cout << "*** INVALID INPUT: INTEGER OUT OF RANGE ***\n";
					}
				} break;
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
				cout << "*** INVALID INPUT: INTEGER OUT OF RANGE ***\n";
				break;
		}

	}
	return 0;
}

