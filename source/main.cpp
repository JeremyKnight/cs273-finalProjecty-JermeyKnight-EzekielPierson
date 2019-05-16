////////////////////
//main.cpp
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

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
// Create teams for the tournament
// Asks the user for an even number of teams
// Then asks for the team names.
// Returns a vector of teams.
vector<Team*> createTeams() {
    vector<Team*> teams;
    int size = 1;
    while(size%2!=0 || size==0) {
        cout << "how many teams do you want? (has to be even) ";
        cin >> size;
    }
    
    for(int x = 0; x < size; x++) {
        Team* team = new Team();
        for(int y = 0; y<9; y++) {
            int r = rand()%100;
            Player* p = new Player(x*10 +y, r);
            team->addPlayer(p);
        }
        team->setId(x+1);
        cout << "name for team " << x+1 << " \n";
        std::string name;
        cin >> name;
        team->setName(name);
        teams.push_back(team);
    }
    return teams;
}

// Play a seven game series between two teams.
// std::vector<Game> & g the vector of games to add the new games to.
// Team * team1 -- the home team
// Team * team2 -- the away team
// Returns losing team
Team* playSeries(std::vector<Game> &g, Team* team1, Team* team2) {
    std::cout << team1->getName() << " vs " << team2->getName() << std::endl;
    std::vector<Game> games = g;
    Team* t1 = team1;
    Team* t2 = team2;
    int teamOneWins = 0;
    int teamTwoWins = 0;
    
    while(teamOneWins < 4 && teamTwoWins < 4)  {
        Game game = Game(t1,  t2);
        if(game.getWinner()->getId() == t1->getId()) {
            teamOneWins++;
        } else {
            teamTwoWins++;
        }
        //At the end of the game, return the next batter to the top of the order.
        t1->setStopIndex(0);
        t2->setStopIndex(0);
        std::cout << game.getGameBoard() << std::endl;
        games.push_back(game);
    }

    if(teamOneWins==4) {
        cout << t1->getName() << " won the series " << "defeating the " << t2->getName() << " " << teamOneWins << " to " << teamTwoWins << endl;
        return t2;
    } else {
        cout << t2->getName() << " won the series " << "defeating the " << t1->getName() << " " << teamTwoWins << " to " << teamOneWins << endl;
        return t1;
    }
}


int main() {
    //Seed randomization for the entire program.
    srand(time(NULL));  
    vector<Team*> teams = createTeams();
    vector<Team*> winningTeams = teams;
    std::vector<Game> games;

    while(winningTeams.size()>1) {
        //if(winningTeams.size()%2>1) P}
// std::vector<Game> & g the vector of games to add the new games to.
// Team * team1 -- the home team
// Team * team2 -- the away team
        for(int i =1; i<winningTeams.size(); i++) {
            Team* losingTeam = playSeries(games, winningTeams[i-1], winningTeams[i]);
            if(winningTeams[i]->getId() == losingTeam->getId()) {
                winningTeams.erase(winningTeams.begin()+i);
            } else {
                winningTeams.erase(winningTeams.begin()+i-1);
            }
        }
        /*
        std::string response;
        if(teams.size() > 2) {
            cout << "print out player stats? (y/n) "
            cin >> response;
        } else {
            cout << "print out player stats? (y/n) "
        }
        */
    }
    
    //create game/series
    
    /*
    for (int i = 0; i < t1->getPlayers().size(); i++) {
        cout << t1->getPlayers()[i]->toString() << endl;
    }
    */
    return 0;
}

