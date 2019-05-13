#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include "Team.h"
#include "HalfInning.h"

class Game {
    private:
        int winningScore;
        int losingScore;
        Team winner;
        Team loser;

        std::vector<HalfInning> winnersInnings;
        std::vector<HalfInning> losersInnings;
  
    public:
        Game(Team t1, Team t2) {
            

            int teamOneScore = 0;
            int teamTwoScore = 0;
            std::vector<HalfInning> team1Innings;
            std::vector<HalfInning> team2Innings;
            for(int x = 0; x < 8 || teamOneScore == teamTwoScore; x++) {
                std::cout << "inning: " << x << std::endl;
                std::cout << "team one at bat!\n";
                HalfInning half1 = HalfInning(t1);
                team1Innings.push_back(half1);
                teamOneScore += half1.getRunScored();

                std::cout << "team two at bat!\n";
                HalfInning half2 = HalfInning(t2);
                team2Innings.push_back(half2);
                teamTwoScore += half2.getRunScored();
            }
            if (teamOneScore > teamTwoScore) {
                winner = t1;
                winningScore = teamOneScore;
                winnersInnings = team1Innings;
                loser = t2;
                losingScore = teamTwoScore;
                losersInnings = team2Innings;
            } else {
                winner = t2;
                winningScore = teamTwoScore;
                winnersInnings = team2Innings;
                loser = t1;
                losingScore = teamOneScore;
                losersInnings = team1Innings;
            }
            std::cout << "final score:\n team 1: " << teamOneScore << "\n team 2: " << teamTwoScore << std::endl; 
            
        }
        int getWinningScore() {return winningScore;}
        int getLosingScore() {return losingScore;}
        Team getWinner() {return winner;}
        Team getLoser() {return loser;}
        std::vector<HalfInning> getWinnersInnings() {return winnersInnings;}
        std::vector<HalfInning> getLosersInnings() {return losersInnings;}
};

#endif
