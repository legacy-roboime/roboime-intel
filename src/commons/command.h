#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "iostream"

using namespace std;

class Command{
private:
	float velTangent_, velNormal_, velAngular_;

public:
	Command();
	Command(float, float, float);
	Command(Command*);

	void setVelTan(float);
	void setVelNorm(float);
	void setVelAng(float);

	float getVelTan();
	float getVelNorm();
	float getVelAng();

	void show();
};

#endif // _COMMAND_H_