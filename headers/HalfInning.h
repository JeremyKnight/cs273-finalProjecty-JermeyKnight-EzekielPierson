////////////////////
//HalfInning.h 
//Jeremy Knight and Ezekiel Pierson all rights reserved
///////////////

#ifndef _HALFINNING_H_
#define _HALFINNING_H_

#include <iostream>
#include <queue>
#include "Team.h"
#include "PlateAppearance.h"

//represents a half inning in baseball
class HalfInning {
    private:
       std::queue<PlateAppearance> events;
       int runsScored;
       Team *team;
       std::vector<std::string> scoringEvents;
    
    public:
        // Construct a half inning object
        // Team * t -- the team that is batting this inning.
        HalfInning(Team* t) {
            team = t;
            int outs=0;
            int i = team->getStopIndex();
            //Populate a queue of PAs until three outs are reached.
            while(outs <3) {
                PlateAppearance pa = PlateAppearance(team->getPlayers()[i]);
                if(pa.getOutcome() == Outcome::out || pa.getOutcome() == Outcome::strikeOut) {
                    outs++;
                }
                events.push(pa);
                if(i>=8) {
                    i=0;
                }else {
                    i++;
                }
            }
            team->setStopIndex(i);
            runsScored = calculateRunsScored(events, scoringEvents);
        }
        // Calculate the number of runs scored in the inning
        // queue -- the first in first out ordered sequence of plate appearances.
        // vector<string> scoringEvents -- keeps track of scoring plays in the inning.
        // Returns the number of runs scored in the inning.
        static int calculateRunsScored(std::queue<PlateAppearance> queue, std::vector<std::string>& scoringEvents) {
            std::vector<int> runners;
            int runsScored = 0;
            while (!queue.empty()) {
                PlateAppearance pa = queue.front();
                switch (pa.getOutcome()) {
                    case Outcome::single:
                        runsScored = updateInningState(1, runners, runsScored, "single", scoringEvents);
                        break;
                    case Outcome::Double:
                        runsScored = updateInningState(2, runners, runsScored, "double", scoringEvents);
                        break;
                    case Outcome::triple:
                        runsScored = updateInningState(3, runners, runsScored, "triple", scoringEvents);
                        break;
                    case Outcome::walk:
                        runsScored = updateInningState(1, runners, runsScored, "walk", scoringEvents);
                        break;
                    case Outcome::homeRun:
                        runsScored = updateInningState(4, runners, runsScored, "Home Run", scoringEvents);
                        break;
                    default:
                        break;
                }
                queue.pop();
            }

            return runsScored;
        }
        // Determine the total number of runs scored in the inning based off of a given base (single, double, etc)
        // int incrementRunnerBy -- the number of bases to move the runner up by.
        // vector<int> runners -- the number of runners on base.
        // int rs the total number of runs scored in the inning up to this point
        // eventDescription -- the hit or walk that potentially scored the runner
        // vectpr<string> & scoringEvents -- an array of scoring plays in the inning
        static int updateInningState(int incrementRunnerBy, std::vector<int>& runners, int rs, std::string eventDescription, std::vector<std::string>& scoringEvents) {
            runners.insert(runners.begin(), 1);
            for (int i = 0; i < runners.size(); i++) {
                runners[i] = runners[i] += incrementRunnerBy;
                if (runners[i] > 4) {
                    runners[i] = -1000;
                    scoringEvents.push_back("runner scored on a " + eventDescription + "\n");
                    rs++;
                }
            }
            return rs;
        }

        //getters
        std::queue<PlateAppearance> getEvents() {return events;}
        int getRunScored() {return runsScored;}
        Team* getTeam() {return team;}
        std::vector<std::string> getScoringEvents() { return scoringEvents; }
};

#endif
