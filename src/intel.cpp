#include "intel.h"

Intel::Intel(){
	ball = vball = Pose(0, 0, 0);

    // init vector of robots
    for(int i = 0 ; i < 10 ; i++){
        Robot robot;

        robot.setId(i);

        if(i < 5){
            robot.setIsOurTeam(true);
        }
        else {
            robot.setIsOurTeam(false);
        }

        robot.setActPose(Pose(0, 0, 0));
        robot.setSetPose(Pose(0, 0, 0));
        robot.setFinalPose(Pose(0, 0, 0));
        robot.setActVel(Pose(0, 0, 0));
        robot.setCommand(Command(0, 0, 0));
        robots.push_back(robot);
    }
}

void Intel::init(){
	if(checkVersionIO()){
    	cerr << "compatible" << endl;

        float field_length;
        float field_width;
        float goal_width;
        float center_circle_radius;
        float defense_radius;
        float defense_stretch;
        float free_kick_from_defense_distance;
        float penalty_spot_from_field_line_dist;
        float penalty_line_from_spot_dist;


    	cin >> field_length
            >> field_width
            >> goal_width
            >> center_circle_radius
            >> defense_radius
            >> defense_stretch
            >> free_kick_from_defense_distance
            >> penalty_spot_from_field_line_dist
            >> penalty_line_from_spot_dist;

        geometry.setGeometry(
            field_length,
            field_width,
            goal_width,
            center_circle_radius,
            defense_radius,
            defense_stretch,
            free_kick_from_defense_distance,
            penalty_spot_from_field_line_dist,
            penalty_line_from_spot_dist);

        // set pointers
        for(int i = 0 ; i < robots.size() ; i++){
            robots.at(i).linkRobots(&robots);
            robots.at(i).linkBall(&ball, &vball);
        }
	}
    else{
		cerr << "not compatible" << endl;
	}
}

void Intel::loop(){
	while(true){
        receive_new_state();

        calc_intel();

        send_new_command();
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

void Intel::calc_intel(){
    for(int i = 0 ; i < robot_count_player ; i++){
        if(i == 0){                     // Only robot 0, development yet
            robots.at(i).calcAction();
        }   
    }
}

void Intel::send_new_command(){
    for(int i = 0 ; i < robot_count_player ; i++){
        Command cmd(0.0f, 0.0f, 0.0f);
        const int robot_id = robots.at(i).getId();
        float kick_x = 0.0f;
        float kick_z = 0.0f;
        float spin = false;
        
        cmd = robots.at(i).getCommand();
        kick_x = 4.0f;
        kick_z = 0.0f;
        spin = true;
        
        cout << cmd.getVelTan() << " " << cmd.getVelNorm() << " " << cmd.getVelAng() << " " << kick_x << " " << kick_z << " " << spin << endl;    
    }
}

void Intel::receive_new_state(){
    	cin >> counter
            >> timestamp
            >> referee_state >> referee_time_left
            >> score_player >> score_opponent
            >> goalie_id_player >> goalie_id_opponent
            >> robot_count_player >> robot_count_opponent;

        float ball_x, ball_y, ball_vx, ball_vy;
        cin >> ball_x >> ball_y >> ball_vx >> ball_vy;

        ball.setX(ball_x);
        ball.setY(ball_y);
        vball.setX(ball_vx);
        vball.setY(ball_vy);

        for(int i = 0; i < robot_count_player; i++){
            int robot_id;
            float robot_x, robot_y, robot_w, robot_vx, robot_vy, robot_vw;

            cin >> robot_id >> robot_x >> robot_y >> robot_w >> robot_vx >> robot_vy >> robot_vw;
            
            robots.at(robot_id).setActPose(Pose(robot_x, robot_y, robot_w));
            robots.at(robot_id).setActVel(Pose(robot_vx, robot_vy, robot_vw));
        }


        for(int i = 0; i < robot_count_opponent; i++){
            int robot_id;
            float robot_x, robot_y, robot_w, robot_vx, robot_vy, robot_vw;

            cin >> robot_id >> robot_x >> robot_y >> robot_w >> robot_vx >> robot_vy >> robot_vw;

            //robots.at(robot_id+5).setActPose(Pose(robot_x, robot_y, robot_w));
            //robots.at(robot_id+5).setActVel(Pose(robot_vx, robot_vy, robot_vw));
        }

        cout << counter << endl;
}