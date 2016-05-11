#include "command.h"

Command::Command(){
	vel_tangent = vel_normal = vel_angular = 0.0;
}

Command::Command(float vel_tangent, float vel_normal, float vel_angular){
	this->vel_tangent = vel_tangent;
	this->vel_normal = vel_normal;
	this->vel_angular = vel_angular;
}

Command::Command(Command *cmd){
	vel_tangent = cmd->vel_tangent;
	vel_normal = cmd->vel_normal;
	vel_angular = cmd->vel_angular;
}

void Command::setVelTan(float vel_tangent){
	this->vel_tangent = vel_tangent;
}

void Command::setVelNorm(float vel_normal){
	this->vel_normal = vel_normal;
}

void Command::setVetAng(float vel_angular){
	this->vel_angular = vel_angular;
}

float Command::getVelTan(){
	return vel_tangent;
}

float Command::getVelNorm(){
	return vel_normal;
}

float Command::getVelAng(){
	return vel_angular;
}

void Command::show(){
	cerr << "Command(" << vel_tangent << ", " << vel_normal << ", " << vel_angular << ")" << endl;
}