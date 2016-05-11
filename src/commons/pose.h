#ifndef _POSE_H_
#define _POSE_H_

#include "debug.h"

class Pose : public Debug{
private:
	float x, y, yaw;

public:
	Pose();
	Pose(float, float, float);
	Pose(Pose*);

	void setX(float);
	void setY(float);
	void setYaw(float);

	float getX();
	float getY();
	float getYaw();

	void show();	// from Debug
};

#endif // _POSE_H_