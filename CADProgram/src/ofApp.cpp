#include "ofApp.h"
#include "common.h"

const ofIndexType Faces[] = {
	0,1,4,
	1,4,5,
	1,2,3,
	1,3,0,
	1,2,5,
	2,5,6,
	3,2,7,
	2,7,6,
	5,4,7,
	5,7,6,
	0,3,4,
	3,4,7
};
const float Verts[] = {
	0, 0, 0,
	1, 0, 0,
	1, 0, 1,
	0, 0, 1,
	0, 1, 0,
	1, 1, 0,
	1, 1, 1,
	0, 1, 1
};
const float Normals[] = {
	0,0,1,
	0,0,1,
	0,-1,0,
	0,-1,0,
	1,0,0,
	1,0,0,
	0,0,-1,
	0,0,-1,
	0,1,0,
	0,1,0,
	-1,0,0,
	-1,0,0
};

ofVec3f v[12];
ofVec3f n[12];
ofFloatColor c[12];
ofVbo vbo;

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofEnableDepthTest();
	ofSetVerticalSync(true);

	camera.setPosition(ofVec3f(0, 0, cameraDistance));
	camera.lookAt(ofVec3f(0, 0, 0));

	diffuse.setShininess(20);
	diffuse.setAmbientColor(ofColor(200, 200, 200));
	diffuse.setDiffuseColor(ofColor(200, 200, 200));
	diffuse.setSpecularColor(ofColor(230, 230, 230));

	mainLight.setPointLight();
	mainLight.setGlobalPosition(ofVec3f(0, 0, mainLightDistance));
	mainLight.orbit(mainLightOrbitOffset[0], mainLightOrbitOffset[1], mainLightDistance, ofVec3f(0, 0, 0));
	mainLight.setAmbientColor(ofColor(150, 150, 150));
	mainLight.setDiffuseColor(ofColor(255, 255, 255));
	mainLight.setSpecularColor(ofColor(255, 255, 255));

	int i, j = 0;
	for (i = 0; i < 12; i++)
	{

		c[i].r = ofRandom(1.0) * 0 + 0.8;
		c[i].g = ofRandom(1.0) * 0 + 0.8;
		c[i].b = ofRandom(1.0) * 0 + 0.8;

		v[i][0] = Verts[j] * 100.f - 50;
		n[i][0] = Normals[j];
		j++;
		v[i][1] = Verts[j] * 100.f - 50;
		n[i][1] = Normals[j];
		j++;
		v[i][2] = Verts[j] * 100.f - 50;
		n[i][2] = Normals[j];
		j++;

		//n[i] = ((b - a).cross(c - a)).normalize();
	}

	vbo.setVertexData(&v[0], 8, GL_STATIC_DRAW);
	vbo.setNormalData(&n[0], 12, GL_STATIC_DRAW);
	vbo.setColorData(&c[0], 12, GL_STATIC_DRAW);
	vbo.setIndexData(&Faces[0], 60, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	camera.begin();
	mainLight.enable();
	diffuse.begin();

	//ofTranslate(-20, 0, 200);
	//ofRotate(ofGetElapsedTimef() * 20.0, 1, 1, 0);
	ofScale(0.5, 0.5, 0.5);
	glPointSize(10.0f);
	vbo.drawElements(GL_TRIANGLES, 60);

	diffuse.end();
	mainLight.disable();
	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	
	lastMousePosition.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
	const float xPrime = lastOrbitPosition.x + x - lastMousePosition.x;
	const float yPrime = lastOrbitPosition.y + y - lastMousePosition.y;

	camera.orbit(xPrime, yPrime, cameraDistance, ofVec3f(0, 0, 0));
	mainLight.orbit(xPrime + mainLightOrbitOffset[0], yPrime + mainLightOrbitOffset[1], mainLightDistance, ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
	lastOrbitPosition.set(lastOrbitPosition.x + x - lastMousePosition.x, lastOrbitPosition.y + y - lastMousePosition.y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}
