#include "commons.h"

namespace common{
	float degrees(Pose a, Pose b){
		return (atan2(a.getY() - b.getY(), a.getX() - b.getX()) * (180/M_PI));
	}

	float radians(Pose a, Pose b){
		return (atan2(a.getY() - b.getY(), a.getX() - b.getX()));
	}

	float distance(Pose a, Pose b){
		return sqrt(((a.getX() - b.getX())*(a.getX() - b.getX())) + ((a.getY() - b.getY())*(a.getY() - b.getY())));
	}
}