#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct GraphNode {

	int val;		// Name of the GraphNode
	bool check;		// If it is checked

	//Vectors that have the next nodes values
	vector<GraphNode*> adj;
	vector<int> dist;

	//Initiator
	GraphNode(int x) : val(x),
		check(false), adj(0, NULL) {}
};

void add(vector<GraphNode*> &nodes, int val, int newVal, int dist) {

	GraphNode *curr, *next = NULL;
	// bool found = false;

	for (int i=0; i<nodes.size(); i++) 
		if (nodes[i]->val == val) 
			curr = nodes[i];

	for (int i=0; i<nodes.size(); i++) 
		if(nodes[i]->val == newVal) 
			next = nodes[i];

	if (next == NULL) {
		curr->adj.push_back(new GraphNode(newVal));
		curr->dist.push_back(dist);
		next = curr->adj[curr->adj.size()-1];
		next->adj.push_back(curr);
		next->dist.push_back(dist);
		nodes.push_back(next);
	} 

	else {
		curr->adj.push_back(next);
		curr->dist.push_back(dist);
		next->adj.push_back(curr);
		next->dist.push_back(dist);
	}
}

void print(vector<GraphNode*> nodes) {

	for (int i=0; i<nodes.size(); i++) {

		cout << nodes[i]->val << endl;
		for (int j=0; j<nodes[i]->adj.size(); j++) {
			cout << nodes[i]->adj[j]->val;
			cout << " " << nodes[i]->dist[j] << endl;
		} cout << endl;
	}
}

int main() {

	vector<GraphNode*> nodes;
	GraphNode *curr, *next;

	nodes.push_back(new GraphNode(1));

	add(nodes, 1, 2, 2);
	add(nodes, 1, 4, 10);
	add(nodes, 2, 3, 5);
	add(nodes, 2, 4, 4);

	print(nodes);

	return 0;
}