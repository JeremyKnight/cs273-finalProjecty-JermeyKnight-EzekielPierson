#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <vector>
#include "Player.h"

class Team {

    private:
        int id;
        std::vector<Player> players;
        int stopIndex;

    public:
        Team(std::vector<Player> p,int i): players(p),  id(i){}
        Team() {
            id= 0;
        }
        int getId() {return id;}
        void setId(int i) {id =i;}
        std::vector<Player> getPlayers() {return players;}

        void setStopIndex(int s) {
            stopIndex = s;
        }

        int getStopIndex() {
            return stopIndex;
        }


        void addPlayer(Player p) {
            players.push_back(p);
        }

};

#endif