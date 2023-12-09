///////////////////////////////////////////////////////////////////////////
// Garret(Alex) Mizway / CS-499 / DataStructures / BinarySearchTree.cpp //
/////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <string>
#include "BinarySearchTree/CSVparser.hpp"
#include <functional>
#include <queue>
#include <stack>

using namespace std;

// Global definitions visible to all methods and classes

// define a structure to hold bid information
struct Bid {
	string bidId; // unique identifier
	string title;
	string fund;
	double amount;
	Bid() {
		amount = 0.0;
	}
};

// forward declarations
double strToDouble(string str, char ch);
void displayBid(Bid bid);


struct Node {
	Bid bid;
	std::shared_ptr<Node> left, right;
};

// Binary Search Tree class definition

/**
* Define a class containing data members and methods to
* implement a binary search tree
*/
class BinarySearchTree {

private:
	// Internal method to insert a bid using shared_ptr
	void Insert(std::shared_ptr<Node>& node, Bid bid) {
		// Implement insertion logic using shared_ptr
	}
	// Internal method to remove a bid using shared_ptr
	void Remove(std::shared_ptr<Node>& node, string bidId) {
		// Implement removal logic using shared_ptr
	}
	// Internal method to search for a bid using shared_ptr
	Bid Search(std::shared_ptr<Node>& node, string bidId) {
		// Implement search logic using shared_ptr
	}
	void addNode(Node* node, Bid bid);
	void inOrder(Node* node);
	Node* removeNode(Node* node, string bidId);
	void inOrderDFS(std::shared_ptr<Node> node);
	int insertCounter;
	int deleteCounter;
	int searchCounter;

public:
	std::shared_ptr<Node> root;
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	// External method to insert a bid using regular pointers
	void Insert(Bid bid);
	// External method to remove a bid using regular pointers
	void Remove(string bidId);
	// External method to search for a bid using regular pointers
	Bid Search(string bidId);
	// Methods to access efficiency counters
	int getInsertCounter() const { return insertCounter; }
	int getDeleteCounter() const { return deleteCounter; }
	int getSearchCounter() const { return searchCounter; }
	// Method for Breadth First Search
	void BFS() {
		if (root == nullptr) {
			cout << "Tree is empty." << endl;
			return;
		}

		queue<shared_ptr<Node>> q;
		q.push(root);

		while (!q.empty()) {
			shared_ptr<Node> current = q.front();
			q.pop();

			// Process the current node
			displayBid(current->bid);

			// Enqueue left child
			if (current->left != nullptr) {
				q.push(current->left);
			}

			// Enqueue right child
			if (current->right != nullptr) {
				q.push(current->right);
			}
		}
	}
	// method for In Order Depth First Search
	void InOrderDFS();
	// Reset efficiency counters
	void resetCounters() {
		insertCounter = 0;
		deleteCounter = 0;
		searchCounter = 0;
	}
};
	
	

	

/**
* Default constructor
*/
	BinarySearchTree::BinarySearchTree() {
		// initialize housekeeping variables
		cout << "INITIALIZING" << endl;
		Node* root = NULL;
}

/**
* Destructor
*/
BinarySearchTree::~BinarySearchTree() {
	// recurse from root deleting every node
}
/**
* Traverse the tree in order
*/
void BinarySearchTree::inOrder(Node* node) {
	std::shared_ptr<Node> currentNode = std::shared_ptr<Node>(node); // Convert to shared_ptr

	if (currentNode == nullptr) {
		return;
	}

	displayBid(currentNode->bid);

	if (currentNode->left) {
		inOrder(currentNode->left.get()); // Call inOrder with raw pointer
	}
	if (currentNode->right) {
		inOrder(currentNode->right.get()); // Call inOrder with raw pointer
	}
}


void BinarySearchTree::InOrder() {
	std::shared_ptr<Node> sharedRoot = std::shared_ptr<Node>(root); // Convert to shared_ptr
	inOrder(sharedRoot.get()); // Pass raw pointer to inOrder
}


/**
* Insert a bid
*/
void BinarySearchTree::Insert(Bid bid) {
	insertCounter++;
	if (!root) {
		root = std::make_shared<Node>(); // Create a new shared_ptr for root if it's empty
		root->bid = bid;
		return;
	}

	std::shared_ptr<Node> current = root;
	std::shared_ptr<Node> prev = nullptr;

	while (current != nullptr) {
		prev = current;
		if (bid.bidId < current->bid.bidId)
			current = current->left;
		else
			current = current->right;
	}

	current = std::make_shared<Node>(); // Create a new node
	current->bid = bid;
	if (bid.bidId < prev->bid.bidId)
		prev->left = current;
	else
		prev->right = current;
}

void BinarySearchTree::Remove(string bidId) {
	deleteCounter++;
	// Implement removing a bid from the tree
	std::shared_ptr<Node> current = root;
	std::shared_ptr<Node> parent = nullptr;
	std::shared_ptr<Node> nodeToDelete = nullptr;

	// Search for the node to delete
	while (current != nullptr && current->bid.bidId != bidId) {
		parent = current;
		if (bidId < current->bid.bidId)
			current = current->left;
		else
			current = current->right;
	}

	if (!current) // If node doesn't exist
		return;

	nodeToDelete = current;

	if (!nodeToDelete->left && !nodeToDelete->right) { // No children
		if (nodeToDelete == root)
			root.reset();
		else if (parent->left == nodeToDelete)
			parent->left.reset();
		else
			parent->right.reset();
	}
	else if (!nodeToDelete->left || !nodeToDelete->right) { // One child
		std::shared_ptr<Node> child = nodeToDelete->left ? nodeToDelete->left : nodeToDelete->right;
		if (nodeToDelete == root)
			root = child;
		else if (parent->left == nodeToDelete)
			parent->left = child;
		else
			parent->right = child;
	}
	else { // Two children
		std::shared_ptr<Node> successor = nodeToDelete->right;
		std::shared_ptr<Node> successorParent = nullptr;

		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		if (successorParent != nullptr)
			successorParent->left = successor->right;

		nodeToDelete->bid = successor->bid;
		nodeToDelete = successor;
	}
}

Bid BinarySearchTree::Search(string bidId) {
	searchCounter++;
	std::shared_ptr<Node> current = root;

	while (current != nullptr) {
		if (current->bid.bidId == bidId)
			return current->bid;
		else if (bidId < current->bid.bidId)
			current = current->left;
		else
			current = current->right;
	}

	return Bid();
}
void BinarySearchTree::inOrderDFS(std::shared_ptr<Node> node) {
	if (node == nullptr)
		return;

	std::stack<std::shared_ptr<Node>> stack;
	stack.push(node);

	while (!stack.empty()) {
		auto current = stack.top();
		stack.pop();

		displayBid(current->bid);

		if (current->right != nullptr)
			stack.push(current->right);

		if (current->left != nullptr)
			stack.push(current->left);
	}
}

void BinarySearchTree::InOrderDFS() {
	inOrderDFS(root); //Starts the DFS on the root node
}


/**
* Add a bid to some node (recursive)
*
* @param node Current node in tree
* @param bid Bid to be added
*/
void BinarySearchTree::addNode(Node* node, Bid bid) {
	Insert(bid);
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
* Display the bid information to the console (std::out)
*
* @param bid struct containing the bid info
*/
void displayBid(Bid bid) {
	cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
		<< bid.fund << endl;
	return;
}

/**
* Load a CSV file containing bids into a container
*
* @param csvPath the path to the CSV file to load
* @return a container holding all the bids read
*/
void loadBids(string csvPath, BinarySearchTree* bst) {
	cout << "Loading CSV file " << csvPath << endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	vector<string> header = file.getHeader();
	for (auto const& c : header) {
		cout << c << " | ";
	}
	cout << "" << endl;

	try {
		// loop to read rows of a CSV file
		for (unsigned int i = 0; i < file.rowCount(); i++) {

			// Create a data structure and add to the collection of bids
			Bid bid;
			bid.bidId = file[i][1];
			bid.title = file[i][0];
			bid.fund = file[i][8];
			bid.amount = strToDouble(file[i][4], '$');

			//cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

			// push this bid to the end
			bst->Insert(bid);
		}
	}
	catch (csv::Error& e) {
		std::cerr << e.what() << std::endl;
	}
}

/**
* Simple C function to convert a string to a double
* after stripping out unwanted char
*
* credit: http://stackoverflow.com/a/24875936
*
* @param ch The character to strip out
*/
double strToDouble(string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}

/**
* The one and only main() method
*/
int main(int argc, char* argv[]) {

	// process command line arguments
	string csvPath, bidKey;
	switch (argc) {
	case 2:
		csvPath = argv[1];
		bidKey = "98109";
		break;
	case 3:
		csvPath = argv[1];
		bidKey = argv[2];
		break;
	default:
		csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
		bidKey = "98109";
	}

	// Define a timer variable
	clock_t ticks;

	// Define a binary search tree to hold all bids
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Bid bid;

	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << "  1. Load Bids" << endl;
		cout << "  2. Display All Bids" << endl;
		cout << "  3. Find Bid" << endl;
		cout << "  4. Remove Bid" << endl;
		cout << "  5. Efficency Check" << endl;
		cout << "  6. BFS Efficency" << endl;
		cout << "  7. InOrderDFS Efficency" << endl;
		cout << "  9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			bst = new BinarySearchTree();

			// Initialize a timer variable before loading bids
			ticks = clock();

			// Complete the method call to load the bids
			loadBids(csvPath, bst);

			//cout << bst->Size() << " bids read" << endl;

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 2:
			bst->InOrder();
			break;

		case 3:
			ticks = clock();

			bid = bst->Search(bidKey);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			if (!bid.bidId.empty()) {
				displayBid(bid);
			}
			else {
				cout << "Bid Id " << bidKey << " not found." << endl;
			}

			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

			break;

		case 4:
			bst->Remove(bidKey);
			break;

		case 5:
			bst = new BinarySearchTree();

			// Initialize a timer variable before loading bids
			ticks = clock();

			// Complete the method call to load the bids
			loadBids(csvPath, bst);
		    //does a automatic insert, remove and search to test efficency and speed
			bst->Insert(bid);
			bst->Remove(bidKey);
			bst->Search(bidKey);

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks " << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			// Perform operations that you want to measure (e.g., insertions, deletions, searches)
			

			// Print the elapsed time
			cout << "Insertion count: " << bst->getInsertCounter() << endl;
			cout << "Deletion count: " << bst->getDeleteCounter() << endl;
			cout << "Search count: " << bst->getSearchCounter() << endl;

			break;

		case 6:
			
			ticks = clock();
			loadBids(csvPath, bst);
			bst->BFS();
			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			// Print the elapsed time
			cout << "time: " << ticks << " clock ticks " << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			// Perform operations that you want to measure (e.g., insertions, deletions, searches)
			cout << "Insertion count: " << bst->getInsertCounter() << endl;
			cout << "Deletion count: " << bst->getDeleteCounter() << endl;
			cout << "Search count: " << bst->getSearchCounter() << endl;

			break;

		case 7:

			ticks = clock();
			loadBids(csvPath, bst);
			bst->InOrderDFS();
			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			// Print the elapsed time
			cout << "time: " << ticks << " clock ticks " << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			// Perform operations that you want to measure (e.g., insertions, deletions, searches)
			cout << "Insertion count: " << bst->getInsertCounter() << endl;
			cout << "Deletion count: " << bst->getDeleteCounter() << endl;
			cout << "Search count: " << bst->getSearchCounter() << endl;

			break;
		}
	}

	cout << "Good bye." << endl;

	return 0;
}