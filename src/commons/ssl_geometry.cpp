#include "ssl_geometry.h" 
#include <iostream>

SSL_Geometry::SSL_Geometry(){
	field_length_ = 0;
    field_width_ = 0;
    goal_width_ = 0;
    center_circle_radius_ = 0;
    defense_radius_ = 0;
    defense_stretch_ = 0;
    free_kick_from_defense_distance_ = 0;
    penalty_spot_from_field_line_dist_ = 0;
    penalty_line_from_spot_dist_ = 0;
}

SSL_Geometry::SSL_Geometry(SSL_Geometry *ssl){
	field_length_ = ssl->field_length_;
    field_width_ = ssl->field_width_;
    goal_width_ = ssl->goal_width_;
    center_circle_radius_ = ssl->center_circle_radius_;
    defense_radius_ = ssl->defense_radius_;
    defense_stretch_ = ssl->defense_stretch_;
    free_kick_from_defense_distance_ = ssl->free_kick_from_defense_distance_;
    penalty_spot_from_field_line_dist_ = ssl->penalty_spot_from_field_line_dist_;
    penalty_line_from_spot_dist_ = ssl->penalty_line_from_spot_dist_;
}


void SSL_Geometry::setGeometry
(       float field_length,
        float field_width,
        float goal_width,
        float center_circle_radius,
        float defense_radius,
        float defense_stretch,
        float free_kick_from_defense_distance,
        float penalty_spot_from_field_line_dist,
        float penalty_line_from_spot_dist)
{

    setFieldLength ( field_length );
    setFieldWidth ( field_width );
    setGoalWidth ( goal_width );
    setCenterCircleRadius ( center_circle_radius );
    setDefenseRadius ( defense_radius );
    setDefenseStretch ( defense_stretch );
    setFreeKickFromDefenseDist ( free_kick_from_defense_distance );
    setPenaltySpotFromFieldLineDist ( penalty_spot_from_field_line_dist );
    setPenaltyLineFromSpotDist ( penalty_line_from_spot_dist );
}


/*SSL_Geometry::SSL_Geometry
(       float field_length,
        float field_width,
        float goal_width,
        float center_circle_radius,
        float defense_radius,
        float defense_stretch,
        float free_kick_from_defense_distance,
        float penalty_spot_from_field_line_dist,
        float penalty_line_from_spot_dist)
{   
    field_length_ = field_length;
    field_width_ = field_width;
    goal_width_ = goal_width;
    center_circle_radius_ = center_circle_radius;
    defense_radius_ = defense_radius;
    defense_stretch_ = defense_stretch;
    free_kick_from_defense_distance_ = free_kick_from_defense_distance;
    penalty_spot_from_field_line_dist_ = penalty_spot_from_field_line_dist;
    penalty_line_from_spot_dist_ = penalty_line_from_spot_dist;
}*/
/* Method for debugging 
void SSL_Geometry::printGeometry(){
    std::cout 
    << getFieldLength() << " "
    << getFieldWidth() << " "
    << getGoalWidth() << " "
    << getCenterCircleRadius() << " "
    << getDefenseRadius() << " "
    << getDefenseStretch() << " "
    << getFreeKickFromDefenseDist() << " "
    << getPenaltySpotFromFieldLineDist() << " "
    << getPenaltyLineFromSpotDist();
}*/