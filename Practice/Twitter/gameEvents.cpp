#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Event {

	string team;	// Team Name
	string name;	// Player name
	string lame;	// Last name
	string time;	// Time of action
	string actn; 	// Action
	string next; 	// Next player

	Event();
};

void substitution(string query, Event &event) {

	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != " ") 
			aux.insert(query[i]);	

		else {
			
			switch (place) {

				case 0:
					event.name = aux;
				break;

				case 1:
					event.time = aux;
				break;

				case 2:
					event.actn = aux;
				break;

				case 3:
					event.next = aux;
				break;
			}

			aux.clear;
			place++;
		}
	}
}

void yellow (string query, Event &event) {
	
	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != " ") 
			aux.insert(query[i]);	

		else {
			
			switch (place) {

				case 0:
					event.name = aux;
				break;

				case 1:
					event.lame = aux;
				break;

				case 2:
					event.time = aux;
				break;

				case 3:
					event.actn = aux;
				break;
			}

			aux.clear;
			place++;
		}
	}	
}

void restCards(string query, Event &event) {

	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != " ") 
			aux.insert(query[i]);	

		else {
			
			switch (place) {

				case 0:
					event.name = aux;
				break;

				case 2:
					event.time = aux;
				break;

				case 3:
					event.actn = aux;
				break;
			}

			aux.clear;
			place++;
		}
	}
}

char getEventType(string event) {

	int spaces = 0;
	char last;
	char preLast;

	for (int i=event.length(); i>=0; i--) {
		
		if (event[i] == " ") {
			
			spaces++;

			if (spaces == 1)
				last = event[i+1]

			if (spaces == 2)
				preLast = event[i+1];
		} 
	}

	if (spaces == 2)
		return last;

	else 
		return preLast;
}

void storeData(string team, vector <string> events1, vector<Event> &game, int i) {

	game[i] = team;

	for (int j=0; j<events1[i].length(); j++) {
			
		switch (getEventType(events1[i])) {

			case 'G':
				restCards(events1[i], game[i]);
			break;

			case 'Y':
				yellow(events1[i], game[i]);
			break;

			case 'R':
				restCards(events1[i], game[i]);
			break;

			case 'S':
				substitution(events1[i], game[i]);
			break;
		}
	}
}

vector<string> getEventsOrder(string team1, string team2, vector<string> events1, vector<string> events2) {

	// To store game events
	vector<Event> game(events1.size() + events2.size());

	int i;

	// Events of first team
	for (i=0; i<events1.size(); i++) 
		storeData(team1, events1, game);

	for (i; i<events2.size(); i++)
		storeData(team2, events2, game);

	for (i=0; i<game.size(); i++) {

		cout << game.team << endl;
		cout << game.name << endl;
		cout << game.actn << endl;
		cout << game.time << endl;
		cout << endl << endl;
	}

	return vector<string>();
}

int main() {

	string team1 = "ABC";
	string team2 = "CBA";

	vector<string> events1;
	vector<string> events2;

	events1.push_back("Mo Sa 45+2 Y");
	events1.push_back("A 13 G");

	events2.push_back("D 23 S F");
	events2.push_back("Z 46 G");

	getEventsOrder(team1, team2 events1, events2);

	return 0;
}