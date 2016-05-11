#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "commons/pose.h"
#include "commons/path.h"
#include "commons/command.h"

class Robot{
private:
	int id;						
	bool is_yellow;				
	Pose actPose, setPose, finalPose;
	Command command;	
	Path offpath;

public:
	Robot();
	Robot(Robot*);

	void setId(int);
	void setIsYellow(bool);
	void setActPose(Pose);
	void setSetPose(Pose);
	void setFinalPose(Pose);
	void setCommand(Command);
	void setPath(Path);

	int getId();
	bool getIsYellow();
	Pose getActPose();
	Pose getSetPose();
	Pose getFinalPose();
	Command getCommand();
	Path getPath();
};

#endif // _ROBOT_H_