#pragma once

#include "ofMain.h"

class Tear {
public:
	Tear();
	Tear(ofVec3f location);
	~Tear();

	void update();
	void draw();

private:
	float speed;
	float location_angle_1, location_angle_2, location_radius;
	float body_color_value;

	ofVec3f location;
	vector<ofVec3f> log;
	int log_size;
};