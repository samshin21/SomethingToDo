// SomethingToDo
// Date: 12.06.2025
// Author: Sam Shin

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <random>

using namespace std;												// declaring namespace so we don't need 'std::'

void printMenu () {
// function prints the menu for the user to select from
	cout << "\n--- What do you  want to do? ---\n";
	cout << "0. Give me something to do!\n";
	cout << "1. Create something\n";
	cout << "2. Read something\n";
	cout << "3. Update something\n";
	cout << "4. Destroy something\n";
	cout << "5. Exit\n";
}

int itemRead (const vector<string>& todo) {
// method reads the list (if there is any) and returns true(1) or false(0)
	if (todo.empty()) {
		cout << "You have nothing to do\n";
		return 0;
	}
	else {
		for (int i = 0; i < todo.size(); i++) {
			cout << i << ". " << todo[i] << "\n";								// cout the index and respective item from to do list
	      	}
	}
	return 1;
}

int main () {
// main method
	vector<string> todo;
	int usrIndex;
	
	for(;;) {													// infinite loop
		printMenu();
		
		while (!(cin >> usrIndex)) {										// checks if user entered an int
			cout << "\n*** INVALID INPUT: EXPECTING INTEGER ***\n";
			cin.clear();											// this clears the error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');						// this ignores the buffer
		}

		switch (usrIndex) {
			case 0: {											// PICKING a random item
					if (todo.empty()) {
						cout << "You have nothing to do\n";
					}
					else {
						static random_device itemRandomIndex;					// random_device: uniform -distributed random number generator
						static mt19937 gen(itemRandomIndex());					// mt19937: pseudo-random generator of 32-bit numbers with a state size of 19937 bits
						uniform_int_distribution<size_t> dist(0, todo.size()-1);		// setting the random number limits
						
						string itemRandom = todo[dist(gen)];
						cout << "Do this: " + itemRandom + "\n";
					}
				} break;
			
			case 1: {											// CREATE an item for to do list
					cout << "Enter something to do: ";
					string itemCreate;
					getline(cin >> ws, itemCreate);
					
					todo.push_back(itemCreate);							// adds an item to the end of the string vector
					cout << "Added: " + itemCreate + "\n";
				} break;

			case 2:												// READ the items in the current to do list
				cout << "Here are some things you could do...\n";
				itemRead(todo);
				break;

			case 3: {											// UPDATE an item in the current to do list
	  				cout << "Here are some things you can update...\n";
					if (itemRead(todo) == 0) {
						break;
					}
					
					cout << "Which index do you want to update?\n";
					int itemUpdateIndex;
					
					while (!(cin >> itemUpdateIndex)) {						// ensuring user input is a string
						cout << "\n*** INVALID INPUT: EXPECTING INTEGER ***\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					if (0 > itemUpdateIndex || itemUpdateIndex >= todo.size()) {			// ensuring user input falls within vector's size
						cout << "\n***INVALID INPUT: INDEX OUT OF RANGE ***\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						cout << "Enter your updated item: ";
						string itemNew, itemOld;
						getline(cin >> ws, itemNew);
						
						itemOld = todo[itemUpdateIndex];
						todo[itemUpdateIndex] = itemNew;
						cout << "Updated: " + itemOld + " to " + itemNew + "\n";
					}
				} break;

			case 4: {											// DESTROY an item from the current list
	  				cout << "Here are some things you can destroy...\n";
					if (itemRead(todo) == 0) {
						break;
					}
					
					cout << "Which index do you want to destroy\n";
					int itemDeleteIndex;
					
					while (!(cin >> itemDeleteIndex)) {						// ensuring user input is a string
						cout << "\n*** INVALID INPUT: EXPECTING INTEGER ***\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					if (0 > itemDeleteIndex || itemDeleteIndex >= todo.size()) {			// ensuring user input falls within vector's size
						cout << "\n***INVALID INPUT: INDEX OUT OF RANGE ***\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						string itemDelete = todo[itemDeleteIndex];
						todo.erase(todo.begin() + itemDeleteIndex);

						cout << "Deleted: " + itemDelete + "\n";
					}
				} break;
			case 5:
				cout << "Goodbye!\n";
				// using return instead of exit() since I'm in the main function
				return 0;
				// good defensive measure even if you don't need the 'break' statement
				break;
			default:
				cout << "\n*** INVALID INPUT: INDEX OUT OF RANGE ***\n";
				break;
		}
	}
	return 0;
}
