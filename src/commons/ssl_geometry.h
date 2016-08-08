#ifndef _SSL_GEOMETRY_H_
#define _SSL_GEOMETRY_H_

class SSL_Geometry{
public:
    // Overloaded constructors
    SSL_Geometry();
    SSL_Geometry(SSL_Geometry*);
    // SSL_Geometry(float, float, float, float, float, float, float, float, float); 

    // Set functions for field geometry parameters
	
    void setFieldLength (float field_length) { field_length_ = field_length; }
	void setFieldWidth (float field_width) { field_width_ = field_width; }
	void setGoalWidth (float goal_width) { goal_width_ = goal_width; }
	void setCenterCircleRadius (float center_circle_radius) { center_circle_radius_ = center_circle_radius; }
    void setDefenseRadius (float defense_radius) { defense_radius_ = defense_radius; }
    void setDefenseStretch (float defense_stretch) {defense_stretch_ = defense_stretch; }

    // Get functions for field geometry parameters
    
    float getFieldLength() const { return field_length_; }
    float getFieldWidth() const { return field_width_; }
    float getGoalWidth() const { return goal_width_; }
    float getCenterCircleRadius() const { return center_circle_radius_; }
    float getDefenseRadius() const { return defense_radius_; }
    float getDefenseStretch() const { return defense_stretch_; }
    
    void setGeometry(float, float, float, float, float, float);
    
private:
	float field_length_;
    float field_width_;
    float goal_width_;
    float center_circle_radius_;
    float defense_radius_;
    float defense_stretch_;
};

#endif // _SSL_GEOMETRY_H_
