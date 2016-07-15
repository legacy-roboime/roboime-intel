#include "potential_field.h"

PotentialField::PotentialField(){
	alpha = 2.0;
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

	theta = degrees(robots.at(id), goal);
	distances = distance(robots.at(id), goal);

	if(is_last){
		if(distances < radiusRobot){
			x += 0;
			y += 0;
		}
		else if(distances <= (radiusRobot + areaRobot)){
			x += -alpha*(distances - radiusRobot)*cos(theta); 
			y += -alpha*(distances - radiusRobot)*sin(theta);
		}else{
			x += -alpha*areaRobot*cos(theta); 
			y += -alpha*areaRobot*sin(theta);
		}
	}else{
		x += -alpha*areaRobot*cos(theta); 
		y += -alpha*areaRobot*sin(theta);
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

