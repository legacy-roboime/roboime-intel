#ifndef _PATH_H_
#define _PATH_H_

#include "vector"
#include "pose.h"

using namespace std;

class Path{
private:
	vector<Pose> poses;

public:
	Path();
	Path(vector<Pose>);
	Path(Path*);

	void setPath(vector<Pose>);
	vector<Pose> getPath();

	void show();	// from Debug
};

#endif // _PATH_H_