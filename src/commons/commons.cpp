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

	Path PathPtr2Path(ob::PathPtr path_ptr){
		Path path;
		vector<Pose> poses;

		vector<ob::State*> states = boost::static_pointer_cast<og::PathGeometric>(path_ptr)->getStates();

		for(int i = 0 ; i < states.size() ; i++){
			ob::SE2StateSpace::StateType* state = states.at(i)->as<ob::SE2StateSpace::StateType>();
			Pose p(state->getX(), state->getY(), state->getYaw());
			poses.push_back(p);
		}

		path.setPath(poses);
		return path;
	}

	Pose grSim2OMPL(Pose poseGR){
		Pose poseOMPL;

		poseOMPL.setX(poseGR.getX() + 4.0f);
    	poseOMPL.setY(poseGR.getY() + 3.0f);
    	poseOMPL.setYaw(poseGR.getYaw());

		return poseOMPL;
	}

	Pose OMPL2grSim(Pose poseOMPL){
		Pose poseGR;

		poseGR.setX(poseOMPL.getX() - 4.0f);
		poseGR.setY(poseOMPL.getY() - 3.0f);
		poseGR.setYaw(poseOMPL.getYaw());

		return poseGR;
	}
}