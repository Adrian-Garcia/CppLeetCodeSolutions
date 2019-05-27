#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {

	int res, size;
	int counter = 0;
	int i=0;
	
	bool flag = false;
	bool positive = true;

	while (str[i] == ' ') {
		flag = true;
		counter++;
		i++;
	}

	if (flag) str.erase(0, counter);

	if (isalpha(str[0]) && str[0] != '-')
		return 0;

	i = (str[0] == '-') ? 1 : 0;
	flag = false;
	counter = 0;

	while(isdigit(str[i])) {
		counter++;
		flag = true;
		i++;
	}

	if (flag) str.erase(counter, str.length()-1);

	positive = (str[0] != '-') ? true : false;

	size = (positive) ?
		str.length()-1 : str.length();

	// return res;
	return 1;
}

int main() {

	string str = "   42 asddd";

	int number = myAtoi(str);
	// cout << number-1 << endl;

	return 0;
}
