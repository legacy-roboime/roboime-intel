#ifndef _POTENTIAL_FIELDS_H_
#define _POTENTIAL_FIELDS_H_

#include "vector"
#include "../commons/commons.h"

using namespace std;
using namespace common;

class PotentialField{
private:
	float alpha, beta, INF, radiusRobot, areaRobot;

	int id;
	bool is_last;
	vector<Pose> robots; 
	Pose result, goal;

	int sign(float signal);
	void attractiveForce();
	void repulsiveForceOurRobots();
	void repulsiveForceAdvRobots();

public:
	PotentialField();
	PotentialField(PotentialField*);

	void setRobots(vector<Pose>);

	Pose calcResult(int, Pose, bool);
};

#endif // _POTENTIAL_FIELDS_H_