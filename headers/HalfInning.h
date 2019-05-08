#ifndef _HALFINNING_H_
#define _HALFINNING_H_

#include <iostream>
#include <queue>
#include "Team.h"
#include "PlateAppearance.h"

class HalfInning {
    private:
       std::queue<PlateAppearance> events;
       int runScored;
       Team team; 
    
    public:
        HalfInning(std::queue<PlateAppearance> e, Team t) : events(e), team(t) {}
        //initializes an empty queue for
        HalfInning() {
            std::cout << "initializing HalfInning with an empty queue of PlateAppearance\n";
        }

        std::queue<PlateAppearance> getEvents() {return events;}
        int getRunScored() {return runScored;}
        Team getTeam() {return team;}

        //adds an event to events
        //this can either take a plateAppearance or it can create a new PlateAppearance
        void addEvent() {
            std::cout << "added an event\n";
        }

};

#endif
