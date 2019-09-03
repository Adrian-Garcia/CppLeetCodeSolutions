/*
Not my Dijkstra's Algorithm... Yet... 

Got from 
	https://www.youtube.com/watch?v=wQIb1NonMIM
*/
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int findMinVertex(vector<int> distance, vector<bool> visited, int n) {

	int minVertex = -1;

	for (int i=0; i<n; i++) {

		if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
			minVertex = i;
		}
	}

	return minVertex;
}

void dijkstra(vector<vector<int> > edges, int n) {

	vector<int> distance(n, INT_MAX);
	vector<bool> visited(n, false);

	distance[0] = 0;

	for (int i=0; i<n-1; i++) {

		int minVertex = findMinVertex(distance, visited, n);

		visited[minVertex] = true;

		for (int j=0; j<n; j++) {
			
			if (edges[minVertex][j] != 0 && !visited[j]) {
				
				int dist = distance[minVertex] + edges[minVertex][j];

				if (dist < distance[j]) {
					distance[j] = dist;
				} 
			}
		} 
	}

	for (int i=0; i<n; i++) 
		cout << i << " " << distance[i] << endl;
}

int main() {

	int n;
	int e;

	cin >> n >> e;

	// vector<int> aux(n, 0);
	vector<vector<int> > edges(n, vector<int> (n));

	for (int i=0; i<n; i++) {

		for (int j=0; j<n; j++) 
			edges[i][j] = 0;
	}

	for (int i=0; i<e; i++) {
		int f, s, weight;

		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	cout << endl;
	dijkstra(edges, n);

	return 0;
}