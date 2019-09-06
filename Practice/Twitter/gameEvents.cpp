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
};

struct Time {
	int time;
	bool extra;
	int extraTime;
};

void toTime(string time, Time &result) {

	string aux;

	int plus = time.find('+');

	if (plus != std::string::npos) {
		aux = time.substr(0, plus);
		time = time.substr(plus+1, time.length()-1);

		result.time = stoi(aux);
		result.extra = true;
		result.extraTime = stoi(time);
	}

	else {
		result.time = stoi(time);
		result.extra = false;
	}
}

bool big(Time T1, Time T2) {

	if (!T1.extra && !T2.extra)
		return (T1.time > T2.time);

	if (T1.extra && T2.extra)
		return (T1.extraTime > T2.extraTime);

	if (T1.extra && !T2.extra) 
		return true;

	return false;
}

bool order (Event E1, Event E2) {

	Time T1; 
	Time T2; 

	toTime(E1.time, T1);
	toTime(E2.time, T2);

	if (E1.time == E2.time) {

		if (E1.actn == E2.actn)
			if (E1.name > E2.name)
				return false;

		else if (E1.actn == "G") 
			return false;

		else if (E1.actn == "Y" && E2.actn != "G")
			return false;

		else if (E1.actn == "R" && E2.actn != "G" && E2.actn != "Y")
			return false;

		else if (E1.actn == "S" && E2.actn != "G" && E2.actn != "Y" && E2.actn != "R")
			return false;
	}

	else if (big(T1, T2))
		return false;

	
	return true;
}

void substitution(string query, Event &event) {

	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != ' ') 
			aux.push_back(query[i]);	

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

			aux.clear();
			place++;
		}
	}
}

void yellow (string query, Event &event) {
	
	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != ' ') 
			aux.push_back(query[i]);	

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

			aux.clear();
			place++;
		}
	}	
}

void restCards(string query, Event &event) {

	string aux;
	int place = 0;

	for (int i=0; i<query.length(); i++) {

		if (query[i] != ' ') 
			aux.push_back(query[i]);	

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
			}

			aux.clear();
			place++;
		}
	}
}

char getEventType(string event) {

	int spaces = 0;
	char last;
	char preLast;

	for (int i=0; i<event.length(); i++) {

		if (event[i] == ' ') {

			spaces++;

			if (spaces == 2) 
				preLast = event[i+1];

			else if (spaces == 3)
				last = event[i+1];
		}
	}

	if (spaces == 2)
		return preLast;

	else if (spaces == 3) {
		
		if (preLast == 'S') 
			return 'S';

		else 
			return last;
	}
}

void storeData(string team1, string team2, string event, Event &game, int i, int stop) {

	game.team = (i < stop) ?
		team1 : team2;

	for (int j=0; j<event.length(); j++) {	

		switch (getEventType(event)) {

			case 'G':
				restCards(event, game);
				game.actn = 'G';
			break;

			case 'Y':
				yellow(event, game);
				game.actn = 'Y';
			break;

			case 'R':
				restCards(event, game);
				game.actn = 'R';
			break;

			case 'S':
				substitution(event, game);
				game.actn = 'S';
			break;
		}
	}
}

vector<string> getEventsOrder(string team1, string team2, vector<string> events1, vector<string> events2) {

	// To store game events
	vector<Event> game(events1.size() + events2.size());
	vector<string> res(events1.size() + events2.size());
	int i;
	int stop = events1.size();

	events1.insert(events1.end(), events2.begin(), events2.end());

	// Events of first team
	for (i=0; i<events1.size(); i++) 
		storeData(team1, team2, events1[i], game[i], i, stop);

	sort(game.begin(), game.end(), order);

	for (int i=0; i<game.size(); i++) {

		if (game[i].actn == "S") {

			res[i].append(game[i].team);
			res[i].append(" ");
			res[i].append(game[i].name);
			res[i].append(" ");
			res[i].append(game[i].time);
			res[i].append(" ");
			res[i].append(game[i].actn);
			res[i].append(" ");
			res[i].append(game[i].next);

		}

		else if (game[i].actn == "Y") {

			res[i].append(game[i].team);
			res[i].append(" ");
			res[i].append(game[i].name);
			res[i].append(" ");
			res[i].append(game[i].lame);
			res[i].append(" ");
			res[i].append(game[i].time);
			res[i].append(" ");
			res[i].append(game[i].actn);			
		} 

		else {

			res[i].append(game[i].team);
			res[i].append(" ");
			res[i].append(game[i].name);
			res[i].append(" ");
			res[i].append(game[i].time);
			res[i].append(" ");
			res[i].append(game[i].actn);
		}
	}

	return res;
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

	getEventsOrder(team1, team2, events1, events2);

	return 0;
}