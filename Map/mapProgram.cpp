#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	map<string, int> myMap;
	int age;
	string name;

	name = "Fer";
	age = 19;
	myMap.insert(pair<string, int> (name, age));

	name = "Adrian";
	age = 20;
	myMap.insert(pair<string, int> (name, age));

	name = "Burbuja";
	age = 9;
	myMap.insert(pair<string, int> (name, age));

	name = "Lola";
	age = 10;
	myMap.insert(pair<string, int> (name, age));

	map<string, int>::iterator it = myMap.find("Fer");

	for (it=myMap.begin(); it!=myMap.end(); it++)
		cout << it->first << " " << it->second << endl;

	cout << endl << endl;

	it = myMap.find("Fer");
	myMap.erase(it);
	myMap.insert(pair<string, int> ("Super ninia", 19));

	for (it=myMap.begin(); it!=myMap.end(); it++)
		cout << it->first << " " << it->second << endl;	

	return 0;
}