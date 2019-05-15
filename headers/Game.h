#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <sstream>
#include "Team.h"
#include "HalfInning.h"

class Game {
    private:
        int winningScore;
        int losingScore;
        Team winner;
        Team loser;

        std::string gameString;
        std::string gameBoard;

        std::vector<HalfInning> winnersInnings;
        std::vector<HalfInning> losersInnings;
  
    public:
        Game(Team &home, Team &away) {
            
            int teamOneScore = 0;
            int teamTwoScore = 0;
            std::vector<HalfInning> team1Innings;
            std::vector<HalfInning> team2Innings;

            std::stringstream happens;
            std::stringstream homeStr;
            std::stringstream awayStr;
            std::stringstream inningStr;
            std::stringstream stuff;

            //------------------  
            // inning: 1 2 3 4 r
            //------------------  
            //   home: 2 1
            //   away: 1 2 3
            // -------------

            inningStr << "inning: ";
            homeStr <<   "  home: ";
            awayStr <<   "  away: ";
            stuff <<     "--------";

            for(int x = 0; x < 9 || teamOneScore == teamTwoScore; x++) {
            
                
                happens << "team one at bat!\n";
                HalfInning half1 = HalfInning(home);
                team1Innings.push_back(half1);
               
                teamOneScore += half1.getRunScored();

                happens << "team two at bat!\n";
                HalfInning half2 = HalfInning(away);
                team2Innings.push_back(half2);
                
                teamTwoScore += half2.getRunScored();
                stuff << "---";
                
                if(x+1<10) {
                    inningStr << x+1 << "  ";
                    homeStr <<  half1.getRunScored() << "  ";
                    awayStr <<  half2.getRunScored() << "  ";
                } else {
                    inningStr << x+1 << " ";
                    homeStr <<  half1.getRunScored() << "  ";
                    awayStr <<  half2.getRunScored() << "  ";
                }
            }
            inningStr << "|R";
            homeStr << "|" << teamOneScore;
            awayStr << "|" << teamTwoScore;
            stuff << "--";

            if (teamOneScore > teamTwoScore) {
                winner = home;
                winningScore = teamOneScore;
                winnersInnings = team1Innings;
                loser = away;
                losingScore = teamTwoScore;
                losersInnings = team2Innings;
            } else {
                winner = away;
                winningScore = teamTwoScore;
                winnersInnings = team2Innings;
                loser = home;
                losingScore = teamOneScore;
                losersInnings = team1Innings;
            }
            happens << "final score:\n team 1: " << teamOneScore << "\n team 2: " << teamTwoScore << std::endl; 
            gameString = happens.str();

            
            gameBoard = stuff.str() + "\n" + inningStr.str() + "\n" + stuff.str() + "\n" + homeStr.str() + "\n" + awayStr.str() + "\n" + stuff.str();
            
            
        }

        int getWinningScore() {return winningScore;}
        int getLosingScore() {return losingScore;}
        Team& getWinner() {return winner;}
        Team& getLoser() {return loser;}
        std::vector<HalfInning> getWinnersInnings() {return winnersInnings;}
        std::vector<HalfInning> getLosersInnings() {return losersInnings;}

        std::string getPlayByPLay() {
            return gameString;
        }
        
        std::string getGameBoard() {
            return gameBoard;
        }
};

#endif
