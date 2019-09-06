#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mySort(pair<int, int> a, pair<int, int> b) {

	if (a.first < b.first)
		return true;

	if (a.first > b.first)
		return false;

	if (a.first == b.first)
		if (a.second < b.second)
			return false;
		else 
			return true;
}

int maxEvents(vector<int> arrival, vector<int> duration) {

	if (arrival.size() == 1)
		return 1;

	vector<pair<int, int>> aux;
	vector<int> sum(arrival.size());
	int res = 0;
	int last = -1;

	for (int i=0; i<arrival.size(); i++) 
		aux.push_back(pair<int, int> (arrival[i], duration[i]));

	sort(aux.begin(), aux.end(), mySort);

	for (int i=0; i<aux.size(); i++) {
		sum[i] = aux[i].first+aux[i].second;
		cout << sum[i] << " ";
	} cout << endl;

	for (int i=0; i<sum.size(); i++){
		
		if (last < sum[i]) {
			last = sum[i];
			res++;
		}
	}

	return res;
}

int main() {

	vector<int> arrival;
	vector<int> duration;

	arrival.push_back(1);
	arrival.push_back(1);

	duration.push_back(1);
	duration.push_back(5);

	cout << maxEvents(arrival, duration) << endl;

	return 0;
}