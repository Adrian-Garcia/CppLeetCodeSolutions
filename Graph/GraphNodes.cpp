#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Node
struct GraphNode {

	int val;		// Name of the GraphNode
	bool check;		// If it is checked

	//Vector that have the edge values and its distance
	vector<pair<GraphNode*, int> > adj;

	GraphNode(int x) : val(x), check(false) {}
};

GraphNode* linearSearch(vector<GraphNode*> &nodes, int val, int &i) {

	i=0;

	while (i<nodes.size()) {

		if (nodes[i]->val == val)
			return nodes[i];
		
		i++;
	}

	return NULL;
}

GraphNode* binarySearch(vector<GraphNode*> &nodes, int val, int &mid) {

	int low = 0;
	int big = nodes.size()-1;

	while (low <= big) {

		mid = (low+big)/2;

		if (nodes[mid]->val == val)
			return nodes[mid];

		else if (nodes[mid]->val > val)
			big = mid-1;

		else 
			low = mid+1;		
	}

	return NULL;
}

int insert(GraphNode *&node, pair<GraphNode*, int> newNode) {

	int low = 0;
	int mid;
	int big = node->adj.size()-1;

	while (low <= big) {
		
		mid = (low+big)/2;

		if (node->adj[mid].first->val == newNode.first->val)
			return mid+1;

		else if (node->adj[mid].first->val > newNode.first->val)
			big = mid-1;

		else 
			low = mid+1;
	}

	cout << mid << endl;
	node->adj.insert(node->adj.begin()+mid+1, newNode);
	return mid+1;
}

int insertLinear(GraphNode *&node, pair<GraphNode*, int> newNode) {

	int i=0; 

	while (i<node->adj.size()) {

		if (node->adj[i].first->val > newNode.first->val)
			break;

		i++;
	}

	node->adj.insert(node->adj.begin()+i, newNode);
	return i;
}

void add(vector<GraphNode*> &nodes, int val, int newVal, int dist) {

	int posCurr = 0;
	int posNext = 0;

	GraphNode *curr = linearSearch(nodes, val, posCurr); 
	GraphNode *next = linearSearch(nodes, newVal, posNext);

	// Both nodes does not exist
	if (curr == NULL && next == NULL) {
		
		// Create both nodes
		curr = new GraphNode(val);
		pair<GraphNode*, int> p(new GraphNode(newVal), dist);
		curr->adj.push_back(p);
		
		next = curr->adj[0].first;
		pair<GraphNode*, int> q(curr, dist);
		next->adj.push_back(q);
		
		nodes.push_back(curr);
		nodes.push_back(next);
		
		return;
	}

	// Second node does not exist
	else if (next == NULL) {
		
		int pos;

		pair<GraphNode*, int> p(new GraphNode(newVal), dist);
		
		pos = insertLinear(curr, p);
		
		next = curr->adj[pos].first;
		
		pair<GraphNode*, int> q(curr, dist);
		
		next->adj.push_back(q);
		nodes.insert(nodes.begin()+posCurr+1, next);
	} 

	// Both node exist
	else {

		pair<GraphNode*, int> p(next, dist);
		curr->adj.insert(curr->adj.begin()+posCurr+1, p);
		
		pair<GraphNode*, int> q(next, dist);
		next->adj.insert(next->adj.begin()+posNext+1, q);		
	}
}

void print(vector<GraphNode*> nodes) {

	for (int i=0; i<nodes.size(); i++) {

		cout << nodes[i]->val << endl;
		for (int j=0; j<nodes[i]->adj.size(); j++) {
			cout << nodes[i]->adj[j].first->val;
			cout << " " << nodes[i]->adj[j].second << endl;
		} cout << endl;
	}
}

void printNode(GraphNode* node) {

	for (int i=0; i<node->adj.size(); i++) {
		cout << node->val << " -> ";
		cout << node->adj[i].first->val << " - ";
		cout << node->adj[i].second << endl;
	} 
}

void printAllNodes(vector<GraphNode*> nodes) {

	for(int i=0; i<nodes.size(); i++)
		cout << nodes[i]->val << " ";

	cout << endl;
}

void DFS(vector<GraphNode*> nodes) {


}

int main() {

	vector<GraphNode*> nodes;

	add(nodes, 1, 2, 2);
	add(nodes, 1, 4, 10);
	add(nodes, 1, 3, 5);
	add(nodes, 1, 7, 6);
	add(nodes, 1, 10, 12);
	add(nodes, 1, 6, 1);
	add(nodes, 1, 8, 20);
	printAllNodes(nodes);
	
	// printNode(nodes[1]);
	// printNode(nodes[2]);

	return 0;
}