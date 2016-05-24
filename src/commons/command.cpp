#include "command.h"

Command::Command(){
    velTangent_ = 0.0f;
    velNormal_ = 0.0f;
    velAngular_ = 0.0f;
}

Command::Command(float velTangent, float velNormal, float velAngular){
	this->velTangent_ = velTangent;
	this->velNormal_ = velNormal;
	this->velAngular_ = velAngular;
}

Command::Command(Command *cmd){
	velTangent_ = cmd->velTangent_;
	velNormal_ = cmd->velNormal_;
	velAngular_ = cmd->velAngular_;
}

void Command::setVelTan(float velTangent){
	this->velTangent_ = velTangent;
}

void Command::setVelNorm(float velNormal){
	this->velNormal_ = velNormal;
}

void Command::setVelAng(float velAngular){
	this->velAngular_ = velAngular;
}

float Command::getVelTan(){
	return velTangent_;
}

float Command::getVelNorm(){
	return velNormal_;
}

float Command::getVelAng(){
	return velAngular_;
}

void Command::show(){
	cerr << "Command(" << velTangent_ << ", " << velNormal_ << ", " << velAngular_ << ")" << endl;
}