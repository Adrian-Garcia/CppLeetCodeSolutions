/*
Paths of graphs (Deep First and Breath First)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define N 10

using namespace std;

// Read List
vector<vector<int> > readList(int e, int v) {

	int a, b;

	vector<vector<int> > list(v);

	for (int i=0; i<e; i++) {
		cin >> a >> b;
		list[a-1].push_back(b-1);
		list[b-1].push_back(a-1);
	}

	return list;
}

// Read Matrix
void readMatrix(int e, int v, bool matrix[N][N]) {
	
	int a, b;

	for (int i=0; i<=v; i++) 
		for (int j=0; j<=v; j++) 
			matrix[i][j] = false;

	for (int i=0; i<=v; i++) 
		matrix[i][i] = true;

	for (int i=1; i<=e; i++) {
		cin >> a >> b;
		matrix[a-1][b-1] = matrix[b-1][a-1] = true;
	}
}

void printList(vector<vector<int> > list) {

	for (int i=0; i<list.size(); i++) {

		cout << i+1 << " -> ";

		for (int j=0; j<list[i].size(); j++) 
			cout << list[i][j]+1 << " ";

		cout << endl;
	}
}

void printMatrix(int e, int v, bool matrix[N][N]) {

	cout << "\t";
	for (int i=1; i<=v; i++)
		cout << i << "\t"; 

	cout << endl << endl;
	for (int i=0; i<v; i++) {

		cout << i+1 << "\t";

		for (int j=0; j<v; j++) {
			
			cout << (matrix[i][j] ? "T" : "F") << "\t"; 
		} 

		cout << endl;
	}
}

// DFS List
void listDFS(vector<vector<int> > &listAdj, int v) {

	stack<int> s;
	vector<bool> status(v, false);
	int data;

	s.push(0);

	while (!s.empty()) {

		data = s.top();
		s.pop();

		if (status[data]) 
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=listAdj[data].size()-1; i>=0; i--)
			s.push(listAdj[data][i]);
	}
}

// BFS List
void listBFS(vector<vector<int> > &listAdj, int v) {

	queue<int> q;
	vector<bool> status(v, false);
	int data;

	q.push(0);

	while (!q.empty()) {

		data = q.front();
		q.pop();

		if (status[data])
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=0; i<listAdj[data].size(); i++) 
			q.push(listAdj[data][i]);
	}	
}

// DFS Matrix
void matrixDFS(int v, bool matrix[N][N]) {

	stack<int> s;
	vector<int> status(v, false);
	int data;

	s.push(0);

	while (!s.empty()) {

		data = s.top();
		s.pop();

		if (status[data])
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=v-1; i>=0; i--) 
			if (matrix[data][i])
				s.push(i);
	}

}

// BFS Matrix 
void matrixBFS(int v, bool matrix[N][N]) {

	queue<int> q;
	vector<bool> status(v, false);
	int data;

	q.push(0);

	while (!q.empty()) {

		data = q.front();
		q.pop();

		if (status[data])
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=0; i<v; i++)
			if (matrix[data][i])
				q.push(i);
	}
}

void mat(int e, int v, bool matrix[N][N]) { 

	readMatrix(e, v, matrix);
	cout << endl << endl;
	printMatrix(e, v, matrix);
	cout << endl << endl << "DFS: ";
	matrixDFS(v, matrix);
	cout << endl << "BFS: ";
	matrixBFS(v, matrix);

	return;
}

void lst(int e, int v, vector<vector<int> > &list) {

	list = readList(e, v);
	cout << endl;
	printList(list);
	cout << endl << "DFS: ";
	listDFS(list, v);
	cout << endl << "BFS: ";
	listBFS(list, v);

	return;
}

int main() {

	cout << "Grafo" << endl;

	vector<vector<int> > list;
	bool matrix[N][N];
	int v, e;

	cin >> v >> e;

	// mat(e, v, matrix);
	lst(e, v, list);

	return 0;
}