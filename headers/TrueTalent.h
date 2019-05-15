#ifndef _TrueTalent_H_
#define _TrueTalent_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class TrueTalent {
    private:
        int ttyl;
        double powerLvl;
        double strikeOutRate; //strikeRate lower == better
        double walkRate;
        double BABIP;
        double contactRate;
    
    public: 
        TrueTalent(int t) {
            ttyl = t;
           
            powerLvl = t/1000.0;
            strikeOutRate = fabs((t-99)/213.0);
            if (strikeOutRate < .1) {
                strikeOutRate = .1;
            } else if (strikeOutRate > .4) {
                strikeOutRate = .35;
            }

            walkRate = t/555.0;
            if(walkRate<.04) {
                walkRate = .04;
            }
            
            BABIP = (t * 4)/1000.0;
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

        std::string toString() {
            std::stringstream stringStream;
            stringStream << "True talent: " << ttyl;
            stringStream << " Walk rate: " << walkRate << " Strikeout rate: " << strikeOutRate << " BABIP: " << BABIP;
            stringStream << " Power Level: " << powerLvl << " contact rate: " << contactRate;
            return stringStream.str();
        }
};

#endif
