#ifndef _TrueTalent_H_
#define _TrueTalent_H_

#include <iostream>

class TrueTalent {
    private:
        int ttyl;
        double powerLvl;
        double strikeOutRate; //strikeRate lower == better
        double walkRate;
        double BABIP;
    
    public: 
        TrueTalent(int t) {
            ttyl = t;
           
            powerLvl = t/1500;
            
            strikeOutRate = abs((t-99)/213);


            walkRate = t/555;
            if(walkRate<.04) {
                walkRate = .04;
            }
            
            BABIP = t/1000 *4;
            if(BABIP < 0.2) {
                BABIP = 0.2;
            }
        }
};

#endif