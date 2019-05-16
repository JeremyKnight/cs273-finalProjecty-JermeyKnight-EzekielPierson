////////////////////
//TrueTalent.h 
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

#ifndef _TrueTalent_H_
#define _TrueTalent_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

//represents a Talent level for the player class
class TrueTalent {
    private:
        //The single value that represents the actual talent of the player
        int trueTalentLvl;
        // The player's power level derived from his true talent
        double powerLvl;
        // The player's derived strikeout rate from true talent.
        double strikeOutRate;
        // The player's true walk rate as derived from true talent
        double walkRate;
        // The player's true Batting Average on Balls In Play (BABIP) as derived from true talent
        double BABIP;
        // The player's contact rate
        // This is the rate of plate appearences that don't end in a walk or a strikeout.
        double contactRate;
    
    public:
        // Constructs a true talent object.
        //  int talentLevel -- a number between 0 and 100 that represents the actual talent level (independent of luck) of the player.
        TrueTalent(int talentLevel) {
            trueTalentLvl = talentLevel;
            // Most of these constants are loosely based off of MLB numbers. Some are just magic numbers derived from feel. 
            powerLvl = talentLevel/1000.0;
            strikeOutRate = fabs((talentLevel-99)/213.0);
            if (strikeOutRate < .1) {
                strikeOutRate = .1;
            } else if (strikeOutRate > .4) {
                strikeOutRate = .35;
            }

            walkRate = talentLevel/555.0;
            if(walkRate<.04) {
                walkRate = .04;
            }
            
            BABIP = (talentLevel * 4)/1000.0;
            if(BABIP < 0.2) {
                BABIP = 0.2;
            }

            contactRate = 1 -(strikeOutRate + walkRate);
        }

        double getStrikeOutRate() {
            return strikeOutRate;
        }

        double getWalkRate() {
            return walkRate;
        }

        double getBABIP() {
            return BABIP;
        }

        double getPowerLevel() {
            return powerLvl;
        }

        double getContactRate() {
            return contactRate;
        }
        // Returns a string based representation of the true talent for an associated player.
        // Includes all associated properties of the true talent class.
        std::string toString() {
            std::stringstream stringStream;
            stringStream << "True talent: " << trueTalentLvl;
            stringStream << " Walk rate: " << walkRate << " Strikeout rate: " << strikeOutRate << " BABIP: " << BABIP;
            stringStream << " Power Level: " << powerLvl << " contact rate: " << contactRate;
            return stringStream.str();
        }
};

#endif
