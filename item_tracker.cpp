#include "cornergrocer.h"
using namespace std;

int main() {
	// Initialize an object of type class grocerystore
	grocerystore itemTracker;
	// Import contents from source file.
	itemTracker.storeItems();
	// Create a backup item-frequency list
	itemTracker.backup();
	// Run the main program
	itemTracker.run();
	
	return 0;
}
