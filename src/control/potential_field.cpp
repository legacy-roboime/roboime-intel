#include "potential_field.h"

PotentialField::PotentialField(){
	alpha = 0.2;
	beta = 0.4; //0.4
	INF = 0.4; //20
	radiusRobot = 0.12;
	areaRobot = 0.50;

	id = 0;
	is_last = true;
	result = goal = Pose(0, 0, 0);
}

PotentialField::PotentialField(PotentialField *pp){
	id = pp->id;;
	is_last = pp->is_last;
	robots = pp->robots; 
	result = pp->result;
	goal = pp->goal;
}

void PotentialField::setRobots(vector<Pose> robots){
	this->robots = robots;
}

Pose PotentialField::calcResult(int id, Pose goal, bool is_last){
	result = Pose(0, 0, 0);
	this->id = id;
	this->is_last = is_last;
	this->goal = goal;

	attractiveForce();
	//repulsiveForceOurRobots();
	//repulsiveForceAdvRobots();

	return result;
}

int PotentialField::sign(float signal){
	if(signal < 0){
		return -1;
	}else if(signal == 0){
		return 0;
	}else{
		return 1;
	}
}

void PotentialField::attractiveForce(){
	double theta, distances;
	float x, y;
	x = y = 0;

	//robots.at(id).show();
	//goal.show();

	theta = radians(robots.at(id), goal);
	distances = distance(robots.at(id), goal);

	if(is_last){
		if(distances < radiusRobot){
			x += 0;
			y += 0;
		}
		else if(distances <= (radiusRobot + areaRobot)){
			x += -alpha*(distances - radiusRobot)*cos(theta/180.0*M_PI); 
			y += -alpha*(distances - radiusRobot)*sin(theta/180.0*M_PI);
		}else{
			x += -alpha*areaRobot*cos(theta/180.0*M_PI); 
			y += -alpha*areaRobot*sin(theta/180.0*M_PI);
		}
	}else{
		x += -alpha*areaRobot*cos(theta/180.0*M_PI); 
		y += -alpha*areaRobot*sin(theta/180.0*M_PI);
	}

	result.setX(result.getX() + x);
	result.setY(result.getY() + y);
}

void PotentialField::repulsiveForceOurRobots(){
	// TODO
}

void PotentialField::repulsiveForceAdvRobots(){
	// TODO
}

