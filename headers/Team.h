#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <vector>
#include "Player.h"
#include <string>

class Team {

    private:
        int id;
        std::vector<Player*> players;
        int stopIndex =0;
        std::string name;

    public:
        Team(std::vector<Player*> p,int i, std::string n): players(p),  id(i), name(n){}
        Team() {
            id =0;
        }

        int getId() {return id;}
        void setId(int i) {id =i;}
        std::vector<Player*>& getPlayers() {return players;}
        std::string getName() {return name;}
        void setName(std::string n) {name = n;}

        void setStopIndex(int s) {
            stopIndex = s;
        }

        int getStopIndex() {
            return stopIndex;
        }


        void addPlayer(Player *p) {
            players.push_back(p);
        }

};

#endif