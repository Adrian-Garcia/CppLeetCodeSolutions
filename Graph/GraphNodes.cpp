#include <iostream>

using namespace std;

struct GraphNode {

	GraphNode {
		index = 0;
		check = false;
	}

	int val 		// Name of the GraphNode
	int index;		// Index of value]
	bool check;		// If it is checked

	//Vector that have the next nodes values
	vector<vector<GraphNode*> > adj(2);

	//Initiator
	GraphNode(int x) : val(x), adj(0, NULL) {}
};

int main() {

	return 0;
}