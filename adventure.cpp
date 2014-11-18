#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

string compass [5] = {"north", "west", "south", "east", "stay"};

struct position {
	int x;
	int y;
};

class Player {
	public:
		string name;
		string response;
		int hoursPlayed;
		
		int HP;
		int strength;
		int defense;
		int speed;
		int luck;

		position pos;

		Player() {
			name = "";
			response = "";
			hoursPlayed = 0;
			HP = 100;
			strength = defense = speed = luck = 5;

			pos.x = 1;
			pos.y = 1;
		}

		int attack() {
			return 0;
		}
};


class WorldMap {
	private:
		char * worldmap;

		int width;
		int height;

	public:
		WorldMap() {
			width = 10;
			height = 10;
			worldmap = new char[width * height];

			worldmap[1 + 1*width] = '1';
		}

		~WorldMap() {
			delete[] worldmap;
		}

		bool checkBounds(int x, int y) {
			return ((x < width && x >= 0) &&
					(y < height && y >= 0));
		}

		void moveAround(Player& p1) {
			bool validInput = false;
			bool worked = false;

			while(!worked) {
				cout << "Where to? (north, west, south, east)" << endl;
				cin >> p1.response;

				while(!validInput) {
					validInput = (find(compass, compass+6, p1.response)) != compass+6;
					if(!validInput) {
						cout << "Wait, where? (north, west, south, east)" << endl;
						cin >> p1.response;
					}
				}
			
				position& pos = p1.pos;
				if(!(p1.response).compare("north")) {
					validInput = checkBounds(pos.x, pos.y + 1);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						++(pos.y);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further north!" << endl;
					}
				} else if(!(p1.response).compare("south")) {
					validInput = checkBounds(pos.x, pos.y - 1);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						--(pos.y);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further south!" << endl;
					}
				} else if(!(p1.response).compare("west")) {
					validInput = checkBounds(pos.x - 1, pos.y);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						--(pos.x);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further west!" << endl;
					}
				} else if(!(p1.response).compare("east")) {
					validInput = checkBounds(pos.x + 1, pos.y);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						++(pos.x);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further east!" << endl;
					}
				} else {
					cout << "Good idea, let's stay here." << endl;
				}
			}

			cout << "(position: " << p1.pos.x << ", " << p1.pos.y << ")" << endl << endl;
		}

};

void Battle() {
}

void randomBattle() {
	int chance = rand() % 100 + 1;
	if(chance > 60) {
		cout << "Crap, it's the thugs from before!" << endl;
		Battle();
	} else {
		cout << "Ok Good, I don't see any of those guys here either." << endl;
	}
}

void help() {
	cout << "Use the Folling commands:" << endl;
	cout << "move - to move around in the world map." << endl;
	cout << "quit - to quit the game. All progress will be lost." << endl;
}

int main() {
	// Init
	WorldMap map = WorldMap();
	Player player1 = Player();
	bool gameOver = false;

	// Game Start
	// cout << "Welcome to Rapture." << endl;
	// cout << "What's you name, bloke? ";
	// cin >> player1.name;

	// cout << player1.name << ", ay?"<< endl;
	// usleep(1000000);
	// cout << "Well " << player1.name << ", this is a story of great adventure and perils." << endl;
	// cout << "Here we go......................" << endl << endl << endl << endl;
	// usleep(4000000);

	// // Intro Scene
	// cout << player1.name << "!" << endl;
	// usleep(3000000);
	// cout << player1.name << "! Wake up, we gotta leave now!" << endl;
	// usleep(1500000);
	// cout << "..." << endl;
	// usleep(1500000);
	// cout << "..." << endl;
	// usleep(1500000);
	// cout << "..." << endl;
	// usleep(1500000);
	// cout << "Holy crap man, can't believe we got away, right?" << endl;
	// cout << player1.name << ": ";
	// cin >> player1.response;
	// usleep(1500000);
	// cout << "Duuuuuude... Somebody was gonna kill you!" << endl;
	// usleep(1500000);
	// cout << "Look, we have to find Matt before it's too late." << endl;
	// usleep(1500000);
	// cout << "He lives at 4 east, and 4 north." << endl;
	cout << "(position: " << player1.pos.x << ", " << player1.pos.y << ")" << endl << endl;
	help();

	while (!gameOver) {
		cout << "You: ";
		cin >> player1.response;
		if(!(player1.response).compare("help")) {
			help();
		} else if(!(player1.response).compare("move")) {
			map.moveAround(player1);
			randomBattle();
		} else if(!(player1.response).compare("quit")) {
			cout << "Are you sure you want to quit? (yes/no)" << endl;
			cin >> player1.response;
			if(!(player1.response).compare("yes")) {
				exit(0);
			}
		}

	}

	// cout << player1.response;
	
}















