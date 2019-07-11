#include <iostream>
#include <string>

using namespace std;

int binarySearch(string str, char look) {

	int low = 0;
	int big = str.length();
	int mid;
	bool found = false;

	while (low <= big && !found) {

		mid = (big+low)/2;

		if (str[mid] == look)
			return mid;

		else if (str[mid] > look)
			big = mid-1; 

		else
			low = mid+1;
	}

	return -1;
}

int main() {

	string str = "abcdefghijklmnopqrstuvwxyz";

	cout << str << endl;
	cout << binarySearch(str, 'c') << endl;

	return 0;
}
