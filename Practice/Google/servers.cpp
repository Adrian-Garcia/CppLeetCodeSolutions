/* Servers problem 		(medium)
	
	Your are going to be given a vector with numbers. Each number, represent the time of a process that is
	going to run in a server. For this example, the processes are going to be runing in 2 servers. 

	Your job, is allocate the processes in the two servers and make both processes work ass equal as it is
	possible. 

	Write a function that return the diference between the 2 processes runing

	Example:
		Input: [1,2,3,4]
		Output: 0
		Explanation:
			You can run in server 1: processes 2 & 3, wich will finish in 5 units of time
			And in the other server: processes 1 & 4, wich will finish in 5 units of time

			5 - 5 = 0
*/
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> v, int &rest, int half, int sum, int i) {

	if (rest == 0)
		return;
	
	if (rest != 0)
		rest = half-sum;

	if (rest == 0)
		return;

	if (i<0)
		return;

	backtracking(v, rest, half, sum+v[i], i-1);
	backtracking(v, rest, half, sum, i-1);
}

int servers(vector<int> v) {

	int totalSum=0;
	int half;
	int rest;

	for (int i=0; i<v.size(); i++)
		totalSum+=v[i]; 

	half = totalSum/2;
	rest = half;
	
	cout << totalSum << endl;
	cout << half << endl;
	cout << rest << endl;

	backtracking(v, rest, half, 0, v.size());

	return totalSum-half-(half-rest);
}

int main() {

	vector<int> v;

	v.push_back(100);
	v.push_back(1);
	v.push_back(2);

	cout << endl << servers(v) << endl;

	return 0;
}