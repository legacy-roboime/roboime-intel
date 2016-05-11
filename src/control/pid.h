#ifndef _PID_H_
#define _PID_H_

#include "../commons/commons.h"

class PID{
private:
	float proportionalL, derivativeL, integrativeL;
	float proportionalA, derivativeA, integrativeA;
	Command command;
	Pose actPose, setPose;

	void calcProportional();
	void calcDerivative();
	void calcIntegrative();
public:
	PID();
	PID(PID*);

	Command calcCommand(Pose actPose, Pose setPose);

	// get's e set's
};

#endif // _PID_H_