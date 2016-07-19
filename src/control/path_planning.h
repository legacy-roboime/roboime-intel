#ifndef _PATH_PLANNING_H_
#define _PATH_PLANNING_H_

#include "ompl.h"
#include "vector"
#include "../commons/path.h"
#include "../commons/pose.h"
#include "../commons/commons.h"

using namespace std;

class PathPlanning{
protected:
    int id_robot;
    float timeToResolve;                                    // Tempo para resolver o problema     
    float lowBound, highBound;                              // Limites do espaço
    typePlanner planner;                                    // Algoritmo de planejamento de trajetória
    planningObjective objectiveType;

    Path path;
    vector<Pose> robots;
    Pose goal_pose;
    //Workspace *workspace;
    
    static bool isStateValid(const ob::State *state);

public:
    PathPlanning();  
    
    Path solvePath(int id_robot, Pose goal_pose);
    
    void setBounds(float, float);
    void setPlanner(typePlanner);
    void setTimeToResolve(float);

    void setRobots(vector<Pose>);
};

#endif // _PATH_PLANNING_H_