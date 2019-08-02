#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void readListAdj(vector<vector<int> > &listAdj, int e) {

	cout << "Insert Graph Edge and arch" << endl;

	//Variables of origin and destination
	int a, b;

	//Read arches
	for (int i=0; i<e; i++) {
		
		cin >> a >> b; 		// Ask value of a and b
		
		listAdj[a-1].push_back(b-1);
		listAdj[b-1].push_back(a-1);
	}
}

void printListAdj(vector<vector<int> > &listAdj) {

	for(int i=0; i<listAdj.size(); i++) {
		
		cout << i+1 << " -> ";

		for(int j=0; j<listAdj[i].size(); j++) {

			if (j!=0)
				cout << " - ";
			
			cout << listAdj[i][j]+1;

		} cout << endl;
	}
}

void listAdjDFS(vector<vector<int> > &listAdj, int v) {

	stack<int> s;
	vector<bool> status(v, false);
	int data;

	s.push(0);

	while(!s.empty()) {

		data = s.top();
		s.pop();

		if (status[data]) 
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=listAdj[data].size()-1; i>=0; i--) 
			if (!status[listAdj[data][i]])
				s.push(listAdj[data][i]);
	}

	cout << endl;
}

void listAdjBFS(vector<vector<int> > &listAdj, int v) {

	queue<int> q;
	int data;
	vector<bool> status(v, false);

	q.push(0);

	while (!q.empty()) {

		data = q.front();
		q.pop();

		if (status[data])
			continue;

		cout << data+1 << " ";
		status[data] = true;

		for (int i=0; i<listAdj[data].size(); i++)	
			if (!status[listAdj[data][i]])
				q.push(listAdj[data][i]);	 
	}
	cout << endl;
}

int main() {

	int v = 7; 		//edges
	int e = 11; 	//arches

	cout << "Insert Edges and Arches" << endl;
	cin >> v >> e;

	vector<vector<int> > listAdj(v);

	readListAdj(listAdj, e);
	cout << endl;
	printListAdj(listAdj);
	cout << endl;
	listAdjDFS(listAdj, v);
	cout << endl;
	listAdjBFS(listAdj, v);
	cout << endl;

	return 0;
}