#include "ofApp.h"
#include "Game.h"
#include "GameRenderer.h"

ofApp::~ofApp()
{
	SAFE_DELETE(m_game);
	SAFE_DELETE(m_renderer);
}

//--------------------------------------------------------------
void ofApp::setup(){
	m_game = new Game(160, 90);
	m_renderer = new GameRenderer();
	m_renderer->AttachGame(m_game);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	m_renderer->Render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	m_game->step();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
