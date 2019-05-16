////////////////////
//PlateAppearance.h 
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

#ifndef _PLATEAPPEARANCE_H_
#define _PLATEAPPEARANCE_H_

#include <iostream>
#include <Player.h>
#include <string>
#include <ctime>
// The possible outcomes in a baseball plate appearance.
enum class Outcome : int {
    single, Double, triple, homeRun, strikeOut, walk, out
};
// Represents the event that occurs once a plate appearance has finished.
class PlateAppearance {
    private:
        // The player this plateAppearance belongs to.
        Player* player;
        // String based representation of what happened.
        std::string happens;
        // Enum based representation of what happened 
        enum Outcome outcome;
        
    public:
        // Construct a PlateAppearance based off a random instance of the player's true talent level.
        PlateAppearance(Player *p) : player(p) {
            //Generate a random number between 0 and 1.
            player->incrementPlateAppearance();
            double r = rand() / (RAND_MAX + 1.0);
            // check where this number falls and determine the appropriate event based off of the player's talent level.
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
        //Getters
        std::string getHappens() {
            return happens;
        }

        enum Outcome getOutcome() {
            return outcome;
        }
};

#endif
