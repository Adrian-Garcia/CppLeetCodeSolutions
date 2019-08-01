// Curriculum.cpp : Defines the entry point for the console application.
//

// Nombre: Alberto García Viegas
// Matrícula: A00822649

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool DFS(int listAdj[100][100], int v) {
	
	stack<int> pila;
	vector<bool> status(v, false); //(tam, valor inicial);
	vector<int> current;
	pila.push(0);
	status[0] = true;
	int data;
	for (int j = 0; j < v; j++) {
		pila.push(j);
		while (!pila.empty()) {
			data = pila.top();
			pila.pop();
			if (!status[data]) {
				status[data] = true;
				current.push_back(data);
				for (int i = v; i >= 0; i--) {
					if (listAdj[data][i] == 1) {
						if (!status[i]) {
							pila.push(i);
						}
						else {
							for (int m = 0; m < current.size(); m++) {
								if (i == current[m]) {
									return false;
								}
							}
						}
						
					}
				}
			}
		}
		current.clear();
	}	
	return true;
}


int main() {

	int n, m, o, p;
	int matAdj[100][100];
	vector<string> materias;
	string mater, extra;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			matAdj[i][j] = 0;
		}
	}

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> mater;
		materias.push_back(mater);
	}

	for (int i = 0; i < m; i++) {
		o = -1;
		p = -1;
		cin >> mater >> extra;
		int j = 0;
		while (o == -1 || p == -1) {
			if (mater == materias[j]) {
				o = j;
			}
			if (extra == materias[j]) {
				p = j;
			}
			j++;
		}
		matAdj[o][p] = 1;
	}

	/*if (m >= n)
		cout << "INCORRECT\n";
	else*/
		cout << (DFS(matAdj, n) ? "CORRECT" : "INCORRECT") << endl;

    return 0;
}

