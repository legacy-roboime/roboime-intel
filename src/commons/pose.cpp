#include "pose.h"

Pose::Pose(){
	x = y = yaw = 0.0;
}

Pose::Pose(float x, float y, float yaw){
	this->x = x;
	this->y = y;
	this->yaw = yaw;
}

Pose::Pose(Pose *p){
	x = p->x;
	y = p->y;
	yaw = p->yaw;
}

void Pose::setX(float x){
	this->x = x;
}

void Pose::setY(float y){
	this->y = y;
}

void Pose::setYaw(float yaw){
	this->yaw = yaw;
}

float Pose::getX(){
	return x;
}

float Pose::getY(){
	return y;
}

float Pose::getYaw(){
	return yaw;
}

void Pose::show(){
	cerr << "Pose(" << x << ", " << y << ", " << yaw << ")" << endl;
}