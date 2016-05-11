#include "intel.h"

Intel::Intel(){
	ball = vball = Pose(0, 0, 0);
}

void Intel::init(){
	if(checkVersionIO()){
		cerr << "compatible" << endl;

		cin >> geometry.field_length
	        >> geometry.field_width
	        >> geometry.goal_width
	        >> geometry.center_circle_radius
	        >> geometry.defense_radius
	        >> geometry.defense_stretch
	        >> geometry.free_kick_from_defense_distance
	        >> geometry.penalty_spot_from_field_line_dist
	        >> geometry.penalty_line_from_spot_dist;

	    float ball_x, ball_y, ball_vx, ball_vy;

        cin >> ball_x >> ball_y >> ball_vx >> ball_vy;

        ball.setX(ball_x);
        ball.setY(ball_y);
        vball.setX(ball_vx);
        vball.setY(ball_vy);
	}else{
		cerr << "not compatible" << endl;
	}
}

void Intel::loop(){
	while(true){
		cin >> counter
            >> timestamp
            >> referee_state >> referee_time_left
            >> score_player >> score_opponent
            >> goalie_id_player >> goalie_id_opponent
            >> robot_count_player >> robot_count_opponent;

        for (int i = 0; i < robot_count_player; ++i) {
        	Robot robot;
            int robot_id;
            float robot_x, robot_y, robot_w, robot_vx, robot_vy, robot_vw;

            cin >> robot_id >> robot_x >> robot_y >> robot_w >> robot_vx >> robot_vy >> robot_vw;
            
            robot.setId(robot_id);
            robot.setIsOurTeam(true);
            robot.setActPose(Pose(robot_x, robot_y, robot_w));
            robot.setActVel(Pose(robot_vx, robot_vy, robot_vw));

           	//robots.push_back();
        }
	}
}

bool Intel::checkVersionIO(){
    // Version check I/O
    const int compat_version = 1;
    string magic_string;
    int version;
    cin >> magic_string >> version;
    if (magic_string == "ROBOIME_AI_PROTOCOL" && version == compat_version) {
        cout << "COMPATIBLE " << compat_version << endl;
        return true;
    } else {
        cout << "NOT_COMPATIBLE " << compat_version << endl;
        return false;
    }
}