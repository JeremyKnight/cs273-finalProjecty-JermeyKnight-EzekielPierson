#include <iostream>
#include "Team.h"
#include "Game.h"
#include "HalfInning.h"
#include "PlateAppearance.h"
#include "Player.h"
#include <ctime>
#include <vector>
#include <queue>
using namespace std;

vector<Team> createTeams() {
    vector<Team> teams;
    srand(time(NULL));  
    for(int x = 0; x < 4; x++) {
        Team team = Team();
        for(int y = 0; y<9; y++) {
            int r = rand()%100;
            Player p = Player(x*10 +y, r);
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
    return teams;
}

int main() {
    //vector<Team> teams = createTeams();  

    /*srand(time(NULL));
    for(int i =0 ; i< 1000; i++) {
        int r = rand()%100;
        Player p = Player(1, r);
        PlateAppearance pa = PlateAppearance(p);
    }
    */

    Team team = Team();
    for(int y = 0; y<9; y++) {
        int r = rand()%100;
        Player p = Player(y, r);
        team.addPlayer(p);
    }
    team.setId(1);

    HalfInning half = HalfInning(team);
    

    return 0;
}

