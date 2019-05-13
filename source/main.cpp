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
    for(int x = 0; x < 2; x++) {
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
    vector<Team> teams = createTeams();  

    /*srand(time(NULL));
    for(int i =0 ; i< 1000; i++) {
        int r = rand()%100;
        Player p = Player(1, r);
        PlateAppearance pa = PlateAppearance(p);
    }
    */
    /*
    Team team = Team();
    for(int y = 0; y<9; y++) {
        int r = rand()%100;
        Player p = Player(y, r);
        team.addPlayer(p);
    }
    team.setId(1);
    */
    std::vector<Game> games;
    Team t1 = teams[0];
    Team t2 = teams[1];
    int teamOneWins = 0;
    int teamTwoWins = 0;
    while(teamOneWins < 4 && teamTwoWins < 4)  {
        Game game = Game(t1,  t2);
        if(game.getWinner().getId() == t1.getId()) {
            teamOneWins++;
        } else {
            teamTwoWins++;
        }
        games.push_back(game);
    }
    std::cout << "Team " << t1.getId() << "won " << teamOneWins << "games." << std::endl;
    std::cout << "Team " << t2.getId() << "won " << teamTwoWins << "games." << std::endl;
    std::cout << "Games played: " << games.size() << std::endl;
    //HalfInning half = HalfInning(team);
    

    return 0;
}

