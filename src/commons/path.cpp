#include "path.h"

Path::Path(){

}

Path::Path(vector<Pose> poses){
	this->poses = poses;
}

Path::Path(Path *p){
	poses = p->poses;
}	

void Path::setPath(vector<Pose> poses){
	this->poses = poses;
}

vector<Pose> Path::getPath(){
	return poses;
}

void Path::show(){
	cerr << "Path" << endl;
	for(int i = 0 ; i < poses.size() ; i++){
		poses.at(i).show();
	}
}