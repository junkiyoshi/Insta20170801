#include "Tear.h"

Tear::Tear() : Tear(ofVec3f(0, 0, 0)) {
}

Tear::Tear(ofVec3f location){
	this->location = location;
	this->log_size = 10;
	this->body_color_value = ofRandom(255);
	this->speed = ofRandom(2, 12);
	this->location_angle_1 = ofRandom(360);
	this->location_angle_2 = ofRandom(180);
	this->location_radius = ofRandom(ofGetWidth() / 2);
}

Tear::~Tear() {

}

void Tear::update() {
	if (this->location_radius > ofGetWidth())
	{
		this->location_radius = 0;
		this->log.clear();
	}

	float x = this->location_radius * cos(this->location_angle_1 * DEG_TO_RAD) * sin(this->location_angle_2 * DEG_TO_RAD);
	float y = this->location_radius * sin(this->location_angle_1 * DEG_TO_RAD) * sin(this->location_angle_2 * DEG_TO_RAD);
	float z = this->location_radius * cos(this->location_angle_2 * DEG_TO_RAD);
	this->location = ofVec3f(x, y, z);
	this->location_radius += this->speed;

	this->log.push_back(this->location);
	if (this->log.size() > this->log_size) {
		this->log.erase(this->log.begin());
	}
}

void Tear::draw() {

	ofColor c;
	c.setHsb(this->body_color_value, 255, 255);
	ofSetColor(c);

	ofVec3f gap = ofVec3f();
	if (this->log.size() > 1) {
		gap = this->log[0] - this->location;
	}

	ofPushMatrix();
	ofTranslate(this->location);
	
	ofMesh mesh;

	mesh.addVertex(ofVec3f(5, 0, 0));
	mesh.addVertex(ofVec3f(-5, 0, 0));

	mesh.addVertex(ofVec3f(0, 0, 5));
	mesh.addVertex(ofVec3f(0, 0, -5));

	mesh.addVertex(gap);


	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(2);

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(3);

	mesh.addIndex(0);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(0);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(1);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(1);
	mesh.addIndex(3);
	mesh.addIndex(4);

	mesh.addIndex(0);
	mesh.addIndex(3);
	mesh.addIndex(4);

	mesh.draw();
	ofSphere(5);
	ofPopMatrix();
}