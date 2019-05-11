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
        Player player;
        std::string happens;
        
    
    public: 
        PlateAppearance(Player p) : player(p) {
            //depeding on player, create string that represents what happened
            
            double r = rand() / (RAND_MAX + 1.0);
            std::cout << "random number from plateAppearance: " << r << std::endl; 
            //if r < walkRate 
            //if not r - walkRate
            //if else r == strikeoutRate chance
            //if else r == home run
            //else
            /*
            if(r<player.getTrueTalentLevel().getWalkRate()){
                std::cout << "player walked\n";
            } else if (r -player.getTrueTalentLevel().getWalkRate() && r<player.getTrueTalentLevel().getStrikeOutRate()) {
                std::cout << "player struck out\n";                
            } else  {
                std::cout << "player made contact\n";
            } 
            */

            if(r<player.getTrueTalentLevel().getWalkRate()) {
                std::cout << "player walked\n";
            } else if ( r< (player.getTrueTalentLevel().getStrikeOutRate() + player.getTrueTalentLevel().getWalkRate())) {
                std::cout << "player struck out\n";
            } else {
                std::cout << "player made contact\n";
            }

            int thing =0;
            if(thing+=1){
                std::cout << thing << std::endl;
            }

        }




    
};

#endif