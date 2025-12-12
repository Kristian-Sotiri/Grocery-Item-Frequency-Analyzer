#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class grocerystore {
public:
	void storeItems();
	void backup();
	void run();

private:
	string userInput;
	const string fileName = "CS210_Project_Three_Input_File.txt";
	const string backupFile = "frequency.dat";
	vector<string> Products; // Vector to store items
	map<string, int> itemFrequency; // Map to track item frequencies
};
#endif
