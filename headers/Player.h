#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include "TrueTalent.h"
#include <string>
#include <sstream>

class Player {
    private:
        int id;
        TrueTalent trueTalent; //true talent level
        int singles = 0;
        int doubles = 0;
        int triples = 0;
        int homeRuns = 0;
        int PlateAppearance = 0;
        int walks = 0;
        int strikeouts = 0;
        //add more as needed
    
    public:

        Player(int i, TrueTalent t) : id(i), trueTalent(t) {}

        TrueTalent getTrueTalentLevel() {return trueTalent;}
        double getBattingAverage() {
            return getHits()/(double)(PlateAppearance-walks);
        }

        double getOnBasePercentage() {
            return (getHits() + walks) / (double)PlateAppearance;
        } 

        double getSlugging() {
            return (singles+doubles*2+triples*3+homeRuns*4)/(double)(PlateAppearance - walks);
        }

        int getId() {return id;}

        void setTrueTalentLevel(TrueTalent t) {trueTalent = t;}

        void setId(int i) {id=i;}

        int getHits() {
            return triples + homeRuns + singles + doubles;
        }

        void incrementSingles() { singles++;}
        void incrementDoubles() { doubles++;}
        void incrementTriples() { triples++;}
        void incrementHomeRuns() { homeRuns++;}
        void incrementPlateAppearance() { PlateAppearance++;}
        void incrementWalks() { walks++;}
        void incrementStrikeouts() { strikeouts++;}

        std::string toString() {
            std::stringstream sstream;
            sstream << "Player: " << id << " has a triple slash of " << getBattingAverage() << "/" << getOnBasePercentage() << "/" << getSlugging() << std::endl; 
            sstream << "hits: " << getHits() << " singles: " << singles << " doubles: "<< doubles << " triples: " << triples << " home runs: " << homeRuns << std::endl;
            // FIXME: Add batting average and on base percantge.
            return sstream.str();
        }
};

#endif