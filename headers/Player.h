#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>

class Player {
    private:
        int id;
        int ttLvl; //true talent level
        int BA; //batting average
        int OBP; //on base percentage
        //add more as needed
    
    public:

        Player(int i, int t) : id(i), ttLvl(t) {}
        Player(int i, int t, int ba, int obp) : id(i), ttLvl(t), BA(ba), OBP(obp) {}

        int getTrueTalentLevel() {return ttLvl;}
        int getBattingAverage() {return BA;}
        int getOnBasePercentage() {return OBP;}
        int getId() {return id;}

        void setTrueTalentLevel(int t) {ttLvl = t;}
        void setBattingAverage(int ba) {BA=ba;}
        void setOnBasePercentage(int obp) {OBP=obp;}
        void setId(int i) {id=i;}
        
};

#endif