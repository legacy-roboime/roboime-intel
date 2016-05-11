#ifndef _POSE_H_
#define _POSE_H_

#include "vector"

#include "debug.h"
#include "pose.h"

using namespace std;

class Path : public Debug{
private:
	vector<Pose> path;

public:
	Path();
	Path(vector<Pose>);
	Path(Path);

	void setPath(vector<Pose>);
	vector<Pose> getPath();

	void show();	// from Debug
};

#endif // _POSE_H_