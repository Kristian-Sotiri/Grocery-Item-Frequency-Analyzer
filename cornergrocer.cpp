#include "cornergrocer.h"
#include <stdexcept>
using namespace std;



void grocerystore::storeItems() {
	ifstream inFS;
	string tempItem;

	try {
		inFS.open(fileName); // Open file
		if (!inFS.is_open()) {
			throw runtime_error("Error: Could not open file.");
		}
		while (inFS >> tempItem) {
			this->Products.push_back(tempItem);
		}
		// Check for input stream errors
		if (inFS.bad()) {
			throw runtime_error("Error: Could not read from file.");
		}
		if (!inFS.eof()) {
			throw runtime_error("Error: Could not reach end of file.");
		}
		inFS.close(); // Close file afer reading
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		return; // Exit the function if there's an error
	}
}

void grocerystore::backup() {
	ofstream outFS; // Output file stream variable

	try {
		outFS.open(backupFile);
		if (!outFS.is_open()) {
			throw runtime_error("Error: Could not open file.");
		}
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		return; // Exit the function if there's an error
	}

	// Calculate the frequency of each item
	for (const string& item : this->Products) {
		itemFrequency[item]++;
	}

	// Write the items and frequencies to backupFile
	for (const auto& itm : itemFrequency) {
		outFS << itm.first << " " << itm.second << endl;
	}

	outFS.close();
}

void grocerystore::run() {
	userInput = "";

	while (userInput != "Quit") {
		cout << "\nCorner Grocer Menu" << endl
			<< "Please choose an option:" << endl
			<< "1 - Item Frequency Lookup" << endl
			<< "2 - Item Frequency List" << endl
			<< "3 - Item Frequency Histogram" << endl
			<< "4 - Exit the Menu" << endl;
		cin >> userInput;

		try {
			if (userInput == "1") {
				cout << "Please input the item you wish to track:" << endl;
				cin.ignore();
				getline(cin, userInput);
				// Check the frequency of the chosen item
				auto itm = itemFrequency.find(userInput);
				if (itm != itemFrequency.end()) {
					cout << "Frequency of " << userInput << ": " << itm->second << endl;
				}
				else {
					throw runtime_error("Item was not found.");
				}
			}
			else if (userInput == "2") {
				cout << "\nItem Frequency List:" << endl;
				// Print the items with their frequencies as a list
				for (const auto& itm : itemFrequency) {
					cout << itm.first << " " << itm.second << endl;
				}
			}
			else if (userInput == "3") {
				cout << "\nItem Frequency Histogram:" << endl;
				// Print the items with their frequencies as a histogram
				for (const auto& itm : itemFrequency) {
					cout << itm.first << " ";
					for (int i = 0; i < itm.second; ++i) {
						cout << "*";
					}
					cout << endl;
				}
			}
			else if (userInput == "4") {
				cout << "\nClosing the menu.\nThank you" << endl;
				break;  // Exits the while loop
			}
			else {
				cout << "Invalid option. Please choose a valid option from the menu." << endl;
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
	}
}
