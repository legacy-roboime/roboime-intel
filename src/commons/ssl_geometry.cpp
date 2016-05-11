#include "ssl_geometry.h" 

SSL_Geometry::SSL_Geometry(){
	field_length = 0;
    field_width = 0;
    goal_width = 0;
    center_circle_radius = 0;
    defense_radius = 0;
    defense_stretch = 0;
    free_kick_from_defense_distance = 0;
    penalty_spot_from_field_line_dist = 0;
    penalty_line_from_spot_dist = 0;
}

SSL_Geometry::SSL_Geometry(SSL_Geometry *ssl){
	field_length = ssl->field_length;
    field_width = ssl->field_width;
    goal_width = ssl->goal_width;
    center_circle_radius = ssl->center_circle_radius;
    defense_radius = ssl->defense_radius;
    defense_stretch = ssl->defense_stretch;
    free_kick_from_defense_distance = ssl->free_kick_from_defense_distance;
    penalty_spot_from_field_line_dist = ssl->penalty_spot_from_field_line_dist;
    penalty_line_from_spot_dist = ssl->penalty_line_from_spot_dist;
}