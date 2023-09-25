#include "entry.h"
#include <iostream>
using namespace std;
class Scoreboard {
	entry board[5];
	int size;
	
	public:
	bool add(entry e) {
		int last;
		for (last = size - 1; last >= 0; last--) {
			entry* player = &board[last];
			if (player->score < e.score) {
				if (last < 4) {
					// Move down the player
					board[last + 1] = board[last];
				} 
			} else {
				break;
			}
		}
		if (last + 1 < 5) {
			board[last + 1] = e;
		} else {
			return false;
		}
		if (size < 5){
			size++;
		}
		return true;
	}
	
	int banCollege(string college) {
//		if (college.compare("another") == 0)
	}
	
	void print() {
		for (int i = 0; i < 5; i++) {
			if (i < size) {
				entry* player = &board[i];
				cout << i+1 << ". " << player->name << " (" << player->college << ") - " << player->score << endl;
			} else {
				cout << i+1 << ". (none)" << endl;
			}
		}
	}
};
