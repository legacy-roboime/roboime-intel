#include "path_planning.h"

vector<Pose> robotsStatic;
PathPlanning::PathPlanning(){
    lowBound = 0;
    highBound = 1000;   
}

Path PathPlanning::solvePath(int id_robot, Pose goal_pose){
    this->id_robot = id_robot;
    this->goal_pose = goal_pose;

    ob::StateSpacePtr space(new ob::SE2StateSpace());

    ob::RealVectorBounds bounds(2);
    bounds.setLow(lowBound);
    bounds.setHigh(highBound);

    space->as<ob::SE2StateSpace>()->setBounds(bounds);

    ob::SpaceInformationPtr si(new ob::SpaceInformation(space));

    si->setStateValidityChecker(boost::bind(&isStateValid, _1));

    ob::ScopedState<ob::SE2StateSpace> start(space);
    ob::ScopedState<ob::SE2StateSpace> goal(space);

    start->setX(robots.at(id_robot).getX());
    start->setY(robots.at(id_robot).getY());
    start->setYaw(robots.at(id_robot).getYaw());

    goal->setX(goal_pose.getX());
    goal->setY(goal_pose.getY());
    goal->setYaw(robots.at(id_robot).getYaw());


    ob::ProblemDefinitionPtr pdef(new ob::ProblemDefinition(si));
    pdef->setStartAndGoalStates(start, goal);
    ob::PlannerPtr planner(new og::RRTConnect(si));
    planner->setProblemDefinition(pdef);
    
    //planner->setup();
    //si->printSettings(std::cout);
    //pdef->print(std::cout);

    ob::PlannerStatus solved = planner->solve(timeToResolve);

    if(solved){
        ob::PathPtr path_ptr;
        path_ptr = pdef->getSolutionPath();
        path = common::PathPtr2Path(path_ptr);
    }else{
        std::cout << "No solution found" << std::endl;
    }
   

    return path;
}

bool PathPlanning::isStateValid(const ob::State *state){
    bool ok = true;
    const ob::SE2StateSpace::StateType* state2D = state->as<ob::SE2StateSpace::StateType>();
    double x = state2D->getX();
    double y = state2D->getY();

    for(int i = 0 ; i < robotsStatic.size() ; i++){
        robotsStatic.at(i).show();
        double dis = sqrt((x-robotsStatic.at(i).getX())*(x-robotsStatic.at(i).getX()) + (y-robotsStatic.at(i).getY())*(y-robotsStatic.at(i).getY())) - 1;/*robotsStatic.at(i).radius*/;
        if(dis < 0.0){
            ok = false;
        }
    }
    
    return ok;
}

void PathPlanning::setBounds(float lowBound, float highBound){
    this->lowBound = lowBound;
    this->highBound = highBound;
}

void PathPlanning::setPlanner(typePlanner planner){
    this->planner = planner;
}

void PathPlanning::setTimeToResolve(float timeToResolve){
    this->timeToResolve = timeToResolve;
}

void PathPlanning::setRobots(vector<Pose> robots){
    this->robots = robots;
    robotsStatic = this->robots;
}