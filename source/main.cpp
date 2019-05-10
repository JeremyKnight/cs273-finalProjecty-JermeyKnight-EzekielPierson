#include <iostream>
#include "Team.h"
#include "Game.h"
#include "HalfInning.h"
#include "PlateAppearance.h"
#include "Player.h"
#include <ctime>
#include <vector>
using namespace std;



int main() {
    vector<Team> teams;  
    srand(time(NULL));  
    for(int x = 0; x < 4; x++) {
        Team team = Team();
        for(int y = 0; y<9; y++) {
            int r = rand()%100;
            Player p = Player(x, r);
            team.addPlayer(p);
        }
        team.setId(x);
        teams.push_back(team);
        for (int i = 0; i < teams.size(); i++) {
            for (int j = 0; j < teams[i].getPlayers().size(); j++) {
                cout << teams[i].getPlayers()[j].toString() << endl;
            }
        }
    }


    

    return 0;
}