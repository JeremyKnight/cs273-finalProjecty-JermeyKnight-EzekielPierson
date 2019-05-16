////////////////////
//Game.h 
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <sstream>
#include "Team.h"
#include "HalfInning.h"

//represents a specific game in baseball
class Game {
    private:
        int winningScore;
        int losingScore;
        Team* winner;
        Team* loser;

        std::string gameString;
        std::string gameBoard;

        std::vector<HalfInning> winnersInnings;
        std::vector<HalfInning> losersInnings;
  
    public:
        // Constructs a game object
        // Team * home -- the home team for this particular game
        // Team * away -- the away team for this particular game 
        Game(Team* home, Team* away) {
            //Properties we need to initilize the object
            int teamOneScore = 0;
            int teamTwoScore = 0;
            std::vector<HalfInning> team1Innings;
            std::vector<HalfInning> team2Innings;
            // String manipulation variables to construct the box score.
            //------------------  
            // inning: 1 2 3 4 r
            //------------------  
            //   home: 2 1
            //   away: 1 2 3
            // -------------
            std::stringstream happens;
            std::stringstream homeStr;
            std::stringstream awayStr;
            std::stringstream inningStr;
            std::stringstream stuff;
            std::string homeTeamName = home->getName() + ": ";
            std::string awayTeamName = away->getName() + ": ";
            std::string inningString = "inning: ";
            normalizeString(homeTeamName, awayTeamName);
            normalizeString(homeTeamName, inningString);
            normalizeString(awayTeamName, inningString);
            inningStr << inningString;
            homeStr <<   homeTeamName;
            awayStr <<   awayTeamName;
            stuff <<     "--------";
            // Iterate through nine innings randomly generating events for those innings
            // If after nine innings the game is tied, then continue.
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
            // Determine who won and set the appropriate instance variables.
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
            // Finish constructing string based representations of the game.
            gameString = happens.str();
            gameBoard = stuff.str() + "\n" + inningStr.str() + "\n" + stuff.str() + "\n" + homeStr.str() + "\n" + awayStr.str() + "\n" + stuff.str();            
        }
        // Helper function that aligns strings by inserting spaces into the shorter of the two strings.
        // Does nothing if strings are equal.
        // string& s1 -- a string to align with s2
        // string& s2 -- a string to align with s1
        // Does not return anything changes the passed variables by reference.
        static void normalizeString(std::string & s1, std::string & s2) {
            std::string s;
            if (s1.size() > s2.size()) {
                int a = (s1.size() - s2.size());
                for (int i = 0; i < a; i++) {
                    s += " ";
                }
                s += s2;
                s2 = s;
            } else {
                int a = (s2.size() - s1.size());
                for (int i = 0; i < a; i++) {
                    s += " ";
                }
                s += s1;
                s1 = s;
            }
        }
        // getters/settters
        int getWinningScore() {return winningScore;}
        int getLosingScore() {return losingScore;}
        Team* getWinner() {return winner;}
        Team* getLoser() {return loser;}
        std::vector<HalfInning> getWinnersInnings() {return winnersInnings;}
        std::vector<HalfInning> getLosersInnings() {return losersInnings;}

        std::string getPlayByPLay() {
            return gameString;
        }
        // Returns a classic box score looking string.
        std::string getGameBoard() {
            return gameBoard;
        }
};

#endif
