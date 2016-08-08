#include "ssl_geometry.h" 
#include <iostream>

SSL_Geometry::SSL_Geometry(){
	field_length_ = 0;
    field_width_ = 0;
    goal_width_ = 0;
    center_circle_radius_ = 0;
    defense_radius_ = 0;
    defense_stretch_ = 0;
}

SSL_Geometry::SSL_Geometry(SSL_Geometry *ssl){
	field_length_ = ssl->field_length_;
    field_width_ = ssl->field_width_;
    goal_width_ = ssl->goal_width_;
    center_circle_radius_ = ssl->center_circle_radius_;
    defense_radius_ = ssl->defense_radius_;
    defense_stretch_ = ssl->defense_stretch_;
}


void SSL_Geometry::setGeometry
(       float field_length,
        float field_width,
        float goal_width,
        float center_circle_radius,
        float defense_radius,
        float defense_stretch)
{

    setFieldLength ( field_length );
    setFieldWidth ( field_width );
    setGoalWidth ( goal_width );
    setCenterCircleRadius ( center_circle_radius );
    setDefenseRadius ( defense_radius );
    setDefenseStretch ( defense_stretch );
}


/*SSL_Geometry::SSL_Geometry
(       float field_length,
        float field_width,
        float goal_width,
        float center_circle_radius,
        float defense_radius,
        float defense_stretch)
{   
    field_length_ = field_length;
    field_width_ = field_width;
    goal_width_ = goal_width;
    center_circle_radius_ = center_circle_radius;
    defense_radius_ = defense_radius;
    defense_stretch_ = defense_stretch;
}*/
/* Method for debugging 
void SSL_Geometry::printGeometry(){
    std::cout 
    << getFieldLength() << " "
    << getFieldWidth() << " "
    << getGoalWidth() << " "
    << getCenterCircleRadius() << " "
    << getDefenseRadius() << " "
    << getDefenseStretch();
}*/
