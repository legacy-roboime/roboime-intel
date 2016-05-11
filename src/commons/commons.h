#ifndef _COMMONS_H_
#define _COMMONS_H_

#define IVERSION	0.0.0

#include "math.h"

#include "pose.h"
#include "path.h"
#include "command.h"


namespace common{
	float radians(Pose a, Pose b);
	float degrees(Pose a, Pose b);
	float distance(Pose a, Pose b);
}

#endif // _COMMONS_H_