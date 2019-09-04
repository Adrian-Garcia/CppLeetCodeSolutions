/*
Not my Dijkstra's Algorithm... Yet... 

Got from 
	https://www.youtube.com/watch?v=wQIb1NonMIM
*/
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int findMinVertex(vector<int> distance, vector<bool> status, int n) {

	int minVertex = -1;

	for (int i=0; i<n; i++) 
		if (!status[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
			minVertex = i;

	return minVertex;
}

void dijkstra(vector<vector<int> > graph, int n) {

	vector<int> distance(n, INT_MAX);
	vector<bool> status(n, false);

	int minVertex;
	int dist;

	distance[0] = 0;

	for (int i=0; i<n-1; i++) {

		minVertex = findMinVertex(distance, status, n);
		status[minVertex] = true;

		for (int j=0; j<n; j++) {
			
			if (graph[minVertex][j] != 0 && !status[j]) {
				
				dist = distance[minVertex] + graph[minVertex][j];
				
				if (dist < distance[j]) 
					distance[j] = dist;
			}
		} 
	}


	cout << endl;
	for (int i=0; i<n; i++) 
		cout << i << " " << distance[i] << endl;
}

int main() {

	int n;			
	int e;

	int f;
	int s;
	int weight;

	cin >> n >> e;

	vector<vector<int> > graph(n, vector<int> (n));

	for (int i=0; i<e; i++) {

		cin >> f >> s >> weight;
		graph[f][s] = weight;
		graph[s][f] = weight;
	}

	cout << endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) 
			cout << graph[i][j] << "\t";
		cout << endl;
	}

	dijkstra(graph, n);

	return 0;
}