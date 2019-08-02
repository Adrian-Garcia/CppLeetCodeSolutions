#include <iostream>
#include <vector>
#include <algorithm>
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

	//Operators
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

	void operator = (GraphNode *&other) {
		
		this->val = other->val;	
		this->check = other->check;
		this->adj.clear();
		this->dist.clear();

		for (int i=0; i<other->adj.size(); i++){
			this->adj.push_back(other->adj[i]);
			this->dist.push_back(other->dist[i]);
		}
	}
};

void add(vector<GraphNode*> &nodes, int val, int newVal, int dist) {

	GraphNode *curr = NULL; 
	GraphNode *next = NULL;

	for (int i=0; i<nodes.size(); i++) 
		if (nodes[i]->val == val) 
			curr = nodes[i];

	if (curr == NULL) return;

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

void merge(vector<GraphNode*> &nodes, int l, int m, int r) { 
    
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    // int L[n1], R[n2]; 
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
  
    //Copy the remaining elements of R[], if there are any
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
	add(nodes, 1, 4, 10);
	add(nodes, 2, 3, 5);
	add(nodes, 2, 4, 4);

	sort(nodes.begin(), nodes.end());
	mergeSort(nodes, 0, nodes.size()-1);

	for (int i=0; i<nodes.size(); i++)
		cout << nodes[i]->val << endl;

	// print(nodes);

	return 0;
}