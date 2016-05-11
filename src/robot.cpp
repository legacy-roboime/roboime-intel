#include "robot.h"

Robot::Robot(){
	id = 0;
	is_yellow = true;
	actPose = setPose = finalPose = Pose(0, 0, 0);
	command = Command(0, 0, 0);
}

Robot::Robot(Robot *r){
	id = r->id;
	is_yellow = r->is_yellow;
	actPose = r->actPose;
	setPose = r->setPose;
	finalPose = r->finalPose;
	command = r->command;
	offpath = r->offpath;
}

void Robot::linkRobots(vector<Robot> *robots){
	this->robots = robots;
}

void Robot::setId(int id){
	this->id = id;
}

void Robot::setIsYellow(bool is_yellow){
	this->is_yellow = is_yellow;
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

void Robot::setCommand(Command command){
	this->command = command;
}

void Robot::setPath(Path offpath){
	this->offpath = offpath;
}

int Robot::getId(){
	return id;
}

bool Robot::getIsYellow(){
	return is_yellow;
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

Command Robot::getCommand(){
	return command;
}

Path Robot::getPath(){
	return offpath;
}