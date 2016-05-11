#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "iostream"

using namespace std;

class Command{
private:
	float vel_tangent, vel_normal, vel_angular;

public:
	Command();
	Command(float, float, float);
	Command(Command*);

	void setVelTan(float);
	void setVelNorm(float);
	void setVetAng(float);

	float getVelTan();
	float getVelNorm();
	float getVelAng();

	void show();
};

#endif // _COMMAND_H_