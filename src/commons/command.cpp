#include "command.h"

Command::Command(){
	velTangent = velNormal = velAngular = 0.0;
}

Command::Command(float velTangent, float velNormal, float velAngular){
	this->velTangent = velTangent;
	this->velNormal = velNormal;
	this->velAngular = velAngular;
}

Command::Command(Command *cmd){
	velTangent = cmd->velTangent;
	velNormal = cmd->velNormal;
	velAngular = cmd->velAngular;
}

void Command::setVelTan(float velTangent){
	this->velTangent = velTangent;
}

void Command::setVelNorm(float velNormal){
	this->velNormal = velNormal;
}

void Command::setVelAng(float velAngular){
	this->velAngular = velAngular;
}

float Command::getVelTan(){
	return velTangent;
}

float Command::getVelNorm(){
	return velNormal;
}

float Command::getVelAng(){
	return velAngular;
}

void Command::show(){
	cerr << "Command(" << velTangent << ", " << velNormal << ", " << velAngular << ")" << endl;
}