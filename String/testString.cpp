#include <iostream>
#include <string>

using namespace std;

int main() {

	string s = "Fernanda";

	cout << s.length() << endl;

	cout << "\nlenght(): ";
	for (int i=0; i<s.length(); i++)
		cout << s[i];

	cout << "\n\nlenght()-1: ";
	for (int i=0; i<s.length()-1; i++)
		cout << s[i];

	cout << endl << endl;
	return 0;
}