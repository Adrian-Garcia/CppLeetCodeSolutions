#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> processes, int n, int middle, int &close, bool &flag) {

	if (flag)
		return;

	cout << close << " ";

	if (middle == 0) {
		flag = true;
		return;
	}

	if (middle < close)
		close = middle;

	cout << close << endl;

	if (n == 0 && middle != 0)
		return;

	if (processes[n-1] > middle)
		backtracking(processes, n-1, middle, close, flag);

	backtracking(processes, n-1, middle, close, flag);
	backtracking(processes, n-1, middle-processes[n-1], close, flag);
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

	backtracking(processes, n, middle, close, flag);
	return close;
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