#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include "Team.h"
#include "HalfInning.h"

class Game {
    private:
        int teamOneScore;
        int teamTwoScore;
        Team team1;
        Team team2;

        std::vector<HalfInning> innings;
    
    public:
        Game(std::vector<HalfInning> i) : innings(i) {}
        int getTeamOneScore() {return teamOneScore;}
        int getTeamTwoScore() {return teamTwoScore;}
        Team getTeam1() {return team1;}
        Team getTeam2() {return team2;}
        std::vector<HalfInning> getInnings() {return innings;}


};

#endif