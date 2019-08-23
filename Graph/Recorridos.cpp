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

}

// BFS List
void listBFS(vector<vector<int> > &listAdj, int v) {

}

// DFS Matrix
void matrixDFS(int v, bool matrix[N][N]) {

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

		for (int i=v; i>=0; i--) 
			if (matrix[data][i])
				s.push(i);
	}
}

// BFS Matrix 
void matrixBFS(int v, bool matrix[N][N]) {

	queue<int> q;
	vector<bool> status(v);

	q.push(0);

	status[0] = true;

	while (!q.empty()) {

		cout << q.front()+1 << " ";

		for (int i=0; i<v; i++) {

			if (!status[i] && matrix[q.front()][i]) {
				status[i] = true;
				q.push(i);
			}
		}

		q.pop();
	}
}

int main() {

	cout << "Grafo" << endl;

	bool matrix[N][N];
	int v, e;

	cin >> v >> e;

	readMatrix(e, v, matrix);
	cout << endl << endl;
	printMatrix(e, v, matrix);
	cout << endl << endl << "DFS: ";
	matrixDFS(v, matrix);
	cout << endl << "BFS: ";
	matrixBFS(v, matrix);

	return 0;
}