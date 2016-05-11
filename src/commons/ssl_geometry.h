#ifndef _SSL_GEOMETRY_H_
#define _SSL_GEOMETRY_H_

class SSL_Geometry{
public:
	float field_length;
    float field_width;
    float goal_width;
    float center_circle_radius;
    float defense_radius;
    float defense_stretch;
    float free_kick_from_defense_distance;
    float penalty_spot_from_field_line_dist;
    float penalty_line_from_spot_dist;

	SSL_Geometry();
	SSL_Geometry(SSL_Geometry*);

	// TODO gets and sets
};

#endif // _SSL_GEOMETRY_H_