#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "commons/pose.h"
#include "commons/path.h"
#include "commons/command.h"
#include "control/pid.h"
#include "control/potential_field.h"

class Robot{
private:
	int id;						
	bool is_our_team;				
	Pose actPose, setPose, finalPose;
	Pose actVel;
	Command command;	
	Path offpath;

	PID pid;
	PotentialField potentialField;

	vector<Robot> *robots;
	Pose *ball, *vball;
	
public:
	Robot();
	Robot(Robot*);

	void linkRobots(vector<Robot>*);
	void linkBall(Pose*, Pose*);

	void setId(int);
	void setIsOurTeam(bool);
	void setActPose(Pose);
	void setSetPose(Pose);
	void setFinalPose(Pose);
	void setActVel(Pose);
	void setCommand(Command);
	void setPath(Path);

	int getId();
	bool getIsOurTeam();
	Pose getActPose();
	Pose getSetPose();
	Pose getFinalPose();
	Pose getActVel();
	Command getCommand();
	Path getPath();

	void calcAction();
};

#endif // _ROBOT_H_