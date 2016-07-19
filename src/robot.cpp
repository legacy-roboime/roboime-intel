#include "robot.h"

Robot::Robot(){
	id = 0;
	is_our_team = true;
	actPose = setPose = finalPose = Pose(0, 0, 0);
	command = Command(0, 0, 0);
	path_is_valid_yet = false;
}

Robot::Robot(Robot *r){
	id = r->id;
	is_our_team = r->is_our_team;
	actPose = r->actPose;
	setPose = r->setPose;
	finalPose = r->finalPose;
	command = r->command;
	offpath = r->offpath;
	path_is_valid_yet = r->path_is_valid_yet;
}

void Robot::linkRobots(vector<Robot> *robots){
	this->robots = robots;
}

void Robot::linkBall(Pose *ball, Pose *vball){
	this->ball = ball;
	this->vball = vball;
}

void Robot::setId(int id){
	this->id = id;
}

void Robot::setIsOurTeam(bool is_our_team){
	this->is_our_team = is_our_team;
}

void Robot::setActPose(Pose actPose){
	this->actPose = actPose;
}

void Robot::setSetPose(Pose setPose){
	this->setPose = setPose;
}

void Robot::setFinalPose(Pose finalPose){
	this->finalPose = finalPose;
}

void Robot::setActVel(Pose actVel){
	this->actVel = actVel;
}

void Robot::setCommand(Command command){
	this->command = command;
}

void Robot::setPath(Path offpath){
	this->offpath = offpath;
}

int Robot::getId(){
	return id;
}

bool Robot::getIsOurTeam(){
	return is_our_team;
}

Pose Robot::getActPose(){
	return actPose;
}

Pose Robot::getSetPose(){
	return setPose;
}

Pose Robot::getFinalPose(){
	return finalPose;
}

Pose Robot::getActVel(){
	return actVel;
}

Command Robot::getCommand(){
	return command;
}

Path Robot::getPath(){
	return offpath;
}

void Robot::calcAction(){
	vector<Pose> poses;
	vector<Pose> grSim2ompl;

	for(int i = 0 ; i < robots->size() ; i++){
		poses.push_back(robots->at(i).getActPose());
		grSim2ompl.push_back(common::grSim2OMPL(robots->at(i).getActPose()));
		grSim2ompl.at(i).show();
	}

	potentialField.setRobots(poses);

	/*pathPlanning.setRobots(grSim2ompl);

	offpath = pathPlanning.solvePath(id, common::grSim2OMPL(*ball));

	for(int i = 0 ; i < offpath.poses.size() ; i++){
		offpath.poses.at(i) = common::OMPL2grSim(offpath.poses.at(i));
	}

	if(id == 0)
		offpath.show();*/

	Pose targetPosition = potentialField.calcResult(id, *ball, true);

	targetPosition.setX(actPose.getX() + targetPosition.getX());
	targetPosition.setY(actPose.getY() + targetPosition.getY());

	command = pid.calcCommand(actPose, targetPosition);

	// if(have to plan a new path)
	//		Plan();
	//
	// if(distance of robot to pose_i < some_value)
	//		i++;
	//
	// Pose potential = potentialField(robot to pose_i);
	//
	// Command cmd = pid.calcCommand(act pose to potential);
}