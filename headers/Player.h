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
        int BA; //batting average
        int OBP; //on base percentage
        //add more as needed
    
    public:

        Player(int i, TrueTalent t) : id(i), trueTalent(t) {}
        Player(int i, TrueTalent t, int ba, int obp) : id(i), trueTalent(t), BA(ba), OBP(obp) {}

        TrueTalent getTrueTalentLevel() {return trueTalent;}
        int getBattingAverage() {return BA;}
        int getOnBasePercentage() {return OBP;}
        int getId() {return id;}

        void setTrueTalentLevel(TrueTalent t) {trueTalent = t;}
        void setBattingAverage(int ba) {BA=ba;}
        void setOnBasePercentage(int obp) {OBP=obp;}
        void setId(int i) {id=i;}
        
        std::string toString() {
            std::stringstream sstream;
            sstream << "ID " << id << " " << trueTalent.toString();
            // FIXME: Add batting average and on base percantge.
            return sstream.str();
        }
};

#endif