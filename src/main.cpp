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

// using 'addressof' because the coding jesus mentioned it
void onCreate (const vector<string> addressof(todo)) {
	
}

void onRead (const vector<string> addressof(todo)) {
}
void onUpdate (const vector<string> addressof(todo)) {
}
void onDestroy (const vector<string> addressof(todo)) {
}

int main () {
	// main function to get user choice
	vector<string> todo
	usrChoice = 0;
	printUserMenu();

	// inputting the user choice and clearing 'cin' buffer
	cin >> usrChoice;
	cin.ignore ();
	
	// infinite loop
	for (;;) {
		// per ChatGPT switch statements are faster when dealing with ints
		// compared to regular if-else statemetns
		switch (usrChoice) {
			case 1:

			case 2:
			case 3:
			case 4:
			case 5:
			default:
				cout << "Invalid Input
		}

	}
	return 0;
}

