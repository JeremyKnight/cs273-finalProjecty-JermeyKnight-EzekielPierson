#ifndef _PLATEAPPEARANCE_H_
#define _PLATEAPPEARANCE_H_

#include <iostream>
#include <Player.h>
#include <string>
#include <ctime>

enum class Outcome : int {
    single, Double, triple, homeRun, strikeOut, walk, out
};

class PlateAppearance {
    private:
        Player* player;
        std::string happens;
        enum Outcome outcome;
        
    public: 
        PlateAppearance(Player *p) : player(p) {
            //depeding on player, create string that represents what happened
            player->incrementPlateAppearance();
            double r = rand() / (RAND_MAX + 1.0);
            if(r<player->getTrueTalentLevel().getWalkRate()) {
                player->incrementWalks();
                outcome = Outcome::walk;
                happens = "player walked\n";
            } else if ( r< (player->getTrueTalentLevel().getStrikeOutRate() + player->getTrueTalentLevel().getWalkRate())) {
                player->incrementStrikeouts();
                outcome = Outcome::strikeOut;
                happens = "player struck out\n";
            } else {
                double i = rand() / (RAND_MAX + 1.0);
                
                if(i<player->getTrueTalentLevel().getBABIP()){
          
                    double s = rand() / (RAND_MAX + 1.0);
                    if(s>player->getTrueTalentLevel().getPowerLevel()*80) {
                        int t = rand()%1000;
                        if(t<100) {
                            player->incrementTriples();
                            outcome = Outcome::triple;
                            happens = "triple\n";
                        } else {
                            player->incrementDoubles();
                            outcome = Outcome::Double;
                            happens = "double\n";
                        }
                    } else {
                        player->incrementSingles();
                        outcome = Outcome::single;
                        happens = "single\n";
                    }
                } else if(i<player->getTrueTalentLevel().getBABIP()+player->getTrueTalentLevel().getPowerLevel()) {
                    player->incrementHomeRuns();
                    outcome = Outcome::homeRun;

                    happens = "home run\n"; 
                } else {
                    outcome = Outcome::out;
                    happens = "out\n"; 
                }
            }
        }

        std::string getHappens() {
            return happens;
        }

        enum Outcome getOutcome() {
            return outcome;
        }

    
};

#endif