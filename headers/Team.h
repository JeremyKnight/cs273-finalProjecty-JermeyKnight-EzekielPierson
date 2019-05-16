////////////////////
//Team.h 
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <vector>
#include "Player.h"
#include <string>

//represents a baseball team
class Team {

    private:
        int id;
        std::vector<Player*> players;
        // The stop index indicates where the team leads off next inning.
        // It is the responsiblity of the user to make sure this value is valid.
        int stopIndex = 0;
        std::string name;

    public:
        // Construct a Team object
        // vector<Player *> p -- the 9 player vector that forms a team
        // int i -- the id of the team
        // string name -- the name of the team
        Team(std::vector<Player*> p, int i, std::string n): players(p),  id(i), name(n) {}
        // Construct a team and set instance variables to empty.
        Team() {
            id =0;
        }
        //getters and setters
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