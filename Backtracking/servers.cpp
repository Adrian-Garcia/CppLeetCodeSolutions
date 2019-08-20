#include <iostream>
#include <vector>

using namespace std;

bool backtracking(vector<int> processes, int n, int middle, int &close) {

	if (middle < close)
		close = middle;
			
	if (middle == 0) {
		return true;
	}

	if (n == 0 && middle != 0)
		return false;

	if (processes[n-1] > middle)
		return backtracking(processes, n-1, middle, close);

	return 
		backtracking(processes, n-1, middle, close) ||
		backtracking(processes, n-1, middle-processes[n-1], close);
}

int sumValues(vector<int> processes) {

	int addition = 0;

	for (int i=0; i<processes.size(); i++)
		addition+=processes[i];

	return addition;
}

int splitServer(vector<int> processes) {

	int n = processes.size();
	int sum = sumValues(processes);
	int middle = sum/2;	
	int close = sum;
	bool flag = false;

	return backtracking(processes, n, middle, close) ?
		sum-middle*2 : close;	
}

int main() {

	vector<int> processes;

	processes.push_back(1);
	processes.push_back(2);
	processes.push_back(3);
	processes.push_back(4);
	processes.push_back(5);

	for (int i=0; i<processes.size(); i++)
		cout << processes[i] << " ";

	cout << endl << endl << endl << splitServer(processes) << endl;

	return 0;
}
