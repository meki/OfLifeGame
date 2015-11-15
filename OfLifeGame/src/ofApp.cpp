#include "ofApp.h"
#include "Game.h"
#include "GameRenderer.h"
#include "GameController.h"
#include "RenderContext.h"

#include <iostream>
using namespace std;

ofApp::~ofApp()
{
	SAFE_DELETE(m_game);
	SAFE_DELETE(m_renderer);
	SAFE_DELETE(m_controller);
	SAFE_DELETE(m_context);
}

//--------------------------------------------------------------
void ofApp::setup(){

	const int panelW = 2;
	const int panelH = 2;
	const int gridW = panelW * 160;
	const int gridH = panelH * 90;

	m_game = new Game(gridW, gridH);
	m_game->addAcorn((gridW / 2) - 3, (gridH / 2) - 3);

	m_context = new RenderContext(panelW, panelH, gridW, gridH);

	m_renderer = new GameRenderer();
	m_renderer->Attach(m_game);
	m_renderer->Attach(m_context);

	m_controller = new GameController();
	m_controller->attach(m_game);
	m_controller->attach(m_context);
}

using MouseButton = int;
const MouseButton MouseL = 0;
const MouseButton MouseM = 1;
const MouseButton MouseR = 2;

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

	switch (button)
	{
	case MouseL:
	{
		m_controller->addLife(x, y);
	}
	break;

	case MouseR:
	{
		m_context->setPaddingL(x);
		m_context->setPaddingT(y);
	}
	break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	
	cout << __FUNCTION__ << ", " << x << ", " << y << ": " << button << endl;

	switch (button)
	{
	case MouseL:
	{
		m_controller->toggleLife(x, y);
	}
		break;

	case MouseR:
	{

	}
		break;

	default:
		break;
	}
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

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	cout << __FUNCTION__ << " (" << x << "," << y << "," << scrollX << "," << scrollY << ")" << endl;

	float delta = scrollY * 0.1;

	m_context->zoomIncrement(x, y, delta);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
