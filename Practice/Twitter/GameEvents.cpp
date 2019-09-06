#include <iostream>
#include <vector>
#include <string>

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

vector<string> getEventsOrder(string team1, string team2, vector<string> events1, vector<string> events2) {

	// To store game events
	vector<Event> game(events1.size() + events2.size());
	string curr;

	for (int i=0; i<events1.size(); i++) {

		game[i].team = team1;

		for (int j=0; j<events1[i].length(); j++) {
			
			if (events1[i][j] != " ") {
				curr.insert(events1[i][j]);
			}

			else {
				curr.clear();
			}
		}
	}
}

int main() {

	return 0;
}