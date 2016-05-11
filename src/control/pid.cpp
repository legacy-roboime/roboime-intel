#include "pid.h"

PID::PID(){
	proportionalL = 0.2000; //p1 = 0.0004
	derivativeL = 0.0;
	integrativeL = 0.0;

	proportionalA = 0.8000; //p2 = 0.8000
	derivativeA = 0.0;
	integrativeA = 0.0;

	command = Command(0, 0, 0);
	actPose = setPose = Pose(0, 0, 0);
}

PID::PID(PID *pid){
	proportionalL = pid->proportionalL; 
	derivativeL = pid->derivativeL;
	integrativeL = pid->integrativeL;

	proportionalA = pid->proportionalA; 
	derivativeA = pid->derivativeA;
	integrativeA = pid->integrativeA;

	command = pid->command;
	actPose = pid->actPose;
	setPose = pid->setPose;
}

Command PID::calcCommand(Pose actPose, Pose setPose){
	this->actPose = actPose;
	this->setPose = setPose;

	calcProportional();
	calcDerivative();
	calcIntegrative();

	return command;
}

void PID::calcProportional(){
	float vel_tangent = proportionalL * ((setPose.getX() - actPose.getX()) * cos(actPose.getYaw()) + (setPose.getY() - actPose.getY()) * sin(actPose.getYaw()));
	float vel_normal = proportionalL * ((setPose.getY() - actPose.getY()) * cos(actPose.getYaw()) - (setPose.getX() - actPose.getX()) * sin(actPose.getYaw()));
	float vel_angular = proportionalA * (setPose.getYaw() - actPose.getYaw());
	
	command.setVelTan(vel_tangent + command.getVelTan());
	command.setVelNorm(vel_normal + command.getVelNorm());
	command.setVelAng(vel_angular + command.getVelAng());
}

void PID::calcDerivative(){
	// TODO
}

void PID::calcIntegrative(){
	// TODO
}