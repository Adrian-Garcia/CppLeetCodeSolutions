#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct GraphNode {

	int val;		// Name of the GraphNode
	bool check;		// If it is checked

	//Vector that have the edge values and its distance
	vector<pair<GraphNode*, int> > adj;

	GraphNode(int x) : val(x),
		check(false) {}

	bool operator < (const GraphNode *&other) const {
		return (this->val < other->val);
	}

	bool operator > (const GraphNode *&other) const {
		return (this->val > other->val);
	}

	bool operator <= (const GraphNode *&other) const {
		return (this->val <= other->val);
	}

	bool operator >= (const GraphNode *&other) const {
		return (this->val >= other->val);
	}

	bool operator == (const GraphNode *&other) const {
		return (this->val == other->val);
	}
};

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

void add(vector<GraphNode*> &nodes, int val, int newVal, int dist) {

	int posCurr;
	int posNext;

	GraphNode *curr = binarySearch(nodes, val, posCurr); 
	GraphNode *next = binarySearch(nodes, newVal, posNext);

	if (curr == NULL) 
		return;

	if (next == NULL) {

		pair<GraphNode*, int> p(new GraphNode(newVal), dist);
		curr->adj.push_back(p);
		next = curr->adj[curr->adj.size()-1].first;
		pair<GraphNode*, int> q(curr, dist);
		next->adj.push_back(q);
		nodes.push_back(next);
	} 

	else {

		pair<GraphNode*, int> p(next, dist);
		curr->adj.push_back(p);
		pair<GraphNode*, int> q(next, dist);
		next->adj.push_back(q);		
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

void merge(vector<GraphNode*> &nodes, int l, int m, int r) { 

	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 

	vector<GraphNode*> L(n1); 
	vector<GraphNode*> R(n2); 

	for (i = 0; i < n1; i++)
		L[i] = nodes[l + i]; 

	for (j = 0; j < n2; j++)
		R[j] = nodes[m + 1+ j]; 

	i = 0;
	j = 0;
	k = l;
    
	while (i < n1 && j < n2) { 
        
		if (L[i] <= R[j]) { 
			nodes[k] = L[i]; 
			i++; 
		} 

		else { 
			nodes[k] = R[j]; 
			j++; 
		} 

		k++; 
	} 

	while (i < n1) { 
		nodes[k] = L[i]; 
		i++; 
		k++; 
	}

	while (j < n2) { 
		nodes[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(vector<GraphNode*> &nodes, int l, int r) { 
    
    if (l < r) { 
    
        int m = l+(r-l)/2;
        mergeSort(nodes, l, m); 
        mergeSort(nodes, m+1, r); 
        merge(nodes, l, m, r); 
    } 
} 

void DFS(vector<GraphNode*> nodes) {


}

int main() {

	vector<GraphNode*> nodes;
	GraphNode *curr, *next;

	nodes.push_back(new GraphNode(1));

	add(nodes, 1, 2, 2);
	add(nodes, 2, 3, 5);
	add(nodes, 1, 4, 10);
	add(nodes, 2, 4, 4);

	// for (int i=0; i<nodes.size(); i++)
	// 	cout << nodes[i]->val << endl;

	print(nodes);

	return 0;
}