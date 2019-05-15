#ifndef _HALFINNING_H_
#define _HALFINNING_H_

#include <iostream>
#include <queue>
#include "Team.h"
#include "PlateAppearance.h"

class HalfInning {
    private:
       std::queue<PlateAppearance> events;
       int runsScored;
       Team team; 
    
    public:
        HalfInning(std::queue<PlateAppearance> e, Team & t) : events(e), team(t) {}
        //initializes an empty queue for
        HalfInning(Team & t) {
            team = t;
            int outs=0;
            int i =0;
            while(outs <3) {
                PlateAppearance pa = PlateAppearance(team.getPlayers()[i]);
                if(pa.getOutcome() == Outcome::out || pa.getOutcome() == Outcome::strikeOut) {
                    //std::cout << "out from halfinning!\n";
                    outs++;
                }
                events.push(pa);
                if(i>=9) {
                    i=0;
                }else {
                    i++;
                }
            }
            team.setStopIndex(i);
            runsScored = calculateRunsScored(events);
            
        }

        std::queue<PlateAppearance> getEvents() {return events;}
        int getRunScored() {return runsScored;}
        Team& getTeam() {return team;}

        static int calculateRunsScored(std::queue<PlateAppearance> queue) {
            std::vector<int> runners;
            int runsScored = 0;
            while (!queue.empty()) {
                PlateAppearance pa = queue.front();
                switch (pa.getOutcome()) {
                    case Outcome::single:
                        runsScored = updateInningState(1, runners, runsScored, "single");
                        break;
                    case Outcome::Double:
                        runsScored = updateInningState(2, runners, runsScored, "double");
                        break;
                    case Outcome::triple:
                        runsScored = updateInningState(3, runners, runsScored, "triple");
                        break;
                    case Outcome::walk:
                        runsScored = updateInningState(1, runners, runsScored, "walk");
                        break;
                    case Outcome::homeRun:
                        runsScored = updateInningState(4, runners, runsScored, "Home Run");
                        break;
                    default:
                        break;
                }
                queue.pop();
            }

            return runsScored;
        }
    static int updateInningState(int incrementRunnerBy, std::vector<int>& runners, int rs, std::string eventDescription) {
        runners.insert(runners.begin(), 1);
        for (int i = 0; i < runners.size(); i++) {
            runners[i] = runners[i] += incrementRunnerBy;
            if (runners[i] > 4) {
                //std::cout << "runner scored on a " << eventDescription << std::endl;
                runners[i] = -1000;
                rs++;
            }
        }
        return rs;
    }
};

#endif
