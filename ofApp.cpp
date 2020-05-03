#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 12;
	for (int y = span * -5; y < ofGetHeight() + span * 5; y += span) {

		vector<glm::vec2> vertices;
		vertices.push_back(glm::vec2(0, ofGetHeight()));
		for (int x = 0; x <= ofGetWidth(); x += 5) {

			auto distance = abs(ofGetWidth() * 0.5 - x);
			auto tmp_y = 0.f;

			if (distance < 250) {

				auto noise_value = ofNoise(y * 0.03, x * 0.01, ofGetFrameNum() * 0.005);
				auto param = ofMap(distance, 0, 250, 1, 0);
				tmp_y = ofMap(noise_value, 0, 1, span * -5 * param, span * 5 * param);
			}
			
			vertices.push_back(glm::vec2(x, y + tmp_y));
		}
		vertices.push_back(glm::vec2(ofGetWidth() , ofGetHeight()));

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}