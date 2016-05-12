#include "robot.h"

Robot::Robot(){
	id = 0;
	is_our_team = true;
	actPose = setPose = finalPose = Pose(0, 0, 0);
	command = Command(0, 0, 0);
}

Robot::Robot(Robot *r){
	id = r->id;
	is_our_team = r->is_our_team;
	actPose = r->actPose;
	setPose = r->setPose;
	finalPose = r->finalPose;
	command = r->command;
	offpath = r->offpath;
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
	//	Path = PathPlanning(); 
	//	Pose = PotentialField(Path.poses.at(int i = 0 -> Path.poses.size()-1));
	// 	Command = PID(Pose);
	// 	Done !
}