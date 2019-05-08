#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <vector>
#include "Player.h"

class Team {

    private:
        long id;
        std::vector<Player> players;

    public:
        Team(std::vector<Player> p,long i): players(p),  id(i){}
        Team() {
            id= 00000000;
        }
        long getId() {return id;}
        void setId(long i) {id =i;}
        std::vector<Player> getPlayers() {return players;}

};

#endif