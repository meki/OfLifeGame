#include "ofApp.h"
#include "Game.h"
#include "GameRenderer.h"
#include "GameController.h"
#include "RenderContext.h"

#include <iostream>
using namespace std;

const int FRAME_RATE = 30;

class Scenario
{
	enum State
	{
		Initial,
		Stage1,
		Stage2,
		Stage3,
		Stage4,
		Stage5,
		Stage6,
		Stage7,
		Stage8,
		Stage9
	};
public:
	Scenario(GameController* controller, GameRenderer* renderer, RenderContext* context)
	{
		m_controller = controller;
		m_renderer = renderer;
		m_context = context;
		m_state = Initial;
		time = 0;
	}

	void update()
	{
		const double ev1 = 2;
		const double ev2 = 0.8;
		const double ev3 = 0.4;
		const double ev4 = 0.2;
		const double ev5 = 0.1;

// 		const double ev1 = 0.5;
// 		const double ev2 = 0.2;
// 		const double ev3 = 0.1;
// 		const double ev4 = 0.05;
// 		const double ev5 = 0.025;

		const double t1 = ev1 * 30;
		const double t2 = t1 + ev2 * 100;
		const double t3 = t2 + ev3 * 200;
		const double t4 = 60;
		const double t5 = 60;
		const double t6 = 60;


		switch (m_state)
		{
		case Scenario::Initial:
		{
			m_context->setZoomRate(25.0);
			m_context->setPaddingL(7200);
			m_context->setPaddingT(4100);
		}
			break;
		case Scenario::Stage1:
		{
			if (IsEverySeconds(ev1))
			{
				m_controller->step();
			}
		}
			break;
		case Scenario::Stage2:
		{
			static int start = getElapsedSec();
			if (getElapsedSec() - start < 3)
			{
				if (IsEverySeconds(ev1))
				{
					m_controller->step();
				}
			}
			else
			{
				if (IsEverySeconds(ev2))
				{
					m_controller->step();
				}
			}
		}
			break;
		case Scenario::Stage3:
		{
			static int start = getElapsedSec();
			if (getElapsedSec() - start < 3)
			{
				if (IsEverySeconds(ev2))
				{
					m_controller->step();
				}
			}
			else
			{
				if (IsEverySeconds(ev3))
				{
					m_controller->step();
				}
			}
		}
			break;
		case Scenario::Stage4:
		{
			static int start = getElapsedSec();
			if (getElapsedSec() - start < 3)
			{
				if (IsEverySeconds(ev3))
				{
					m_controller->step();
				}
			}
			else
			{
				if (IsEverySeconds(ev4))
				{
					m_controller->step();
				}
			}
		}
			break;
		case Scenario::Stage5:
			break;
		case Scenario::Stage6:
			break;
		case Scenario::Stage7:
			break;
		case Scenario::Stage8:
			break;
		case Scenario::Stage9:
			break;
		default:
			break;
		}

		++time;

		// switch stage
		switch (m_state)
		{
		case Scenario::Initial:
			m_state = Stage1;
			break;
		case Scenario::Stage1:
		{
			if (getElapsedSec() > t1)
			{
				m_state = Stage2;
				m_context->setZoomRate(15.0);
				m_context->setPaddingL(4000);
				m_context->setPaddingT(2300);
			}
		}
			break;
		case Scenario::Stage2:
		{
			if (getElapsedSec() > t2)
			{
				m_state = Stage3;
				m_context->setZoomRate(7.5);
				m_context->setPaddingL(1600);
				m_context->setPaddingT(950);
			}
		}
			break;
		case Scenario::Stage3:
		{
			if (getElapsedSec() > t3)
			{
				m_state = Stage4;
				m_context->setZoomRate(5.0);
				m_context->setPaddingL(780);
				m_context->setPaddingT(490);
			}
		}
			break;
		case Scenario::Stage4:
			break;
		case Scenario::Stage5:
			break;
		case Scenario::Stage6:
			break;
		case Scenario::Stage7:
			break;
		case Scenario::Stage8:
			break;
		case Scenario::Stage9:
			break;
		default:
			break;
		}
	}

	bool IsEverySeconds(double sec) const
	{
		int secInFrame = FRAME_RATE * sec;
		return (time % secInFrame) == 0;
	}

	int getElapsedSec() {
		return time / FRAME_RATE;
	}

private:
	GameController* m_controller;
	GameRenderer* m_renderer;
	RenderContext* m_context;
	State m_state;
	size_t time;
};

bool isStart = false;

ofApp::~ofApp()
{
	SAFE_DELETE(m_game);
	SAFE_DELETE(m_renderer);
	SAFE_DELETE(m_controller);
	SAFE_DELETE(m_context);
	SAFE_DELETE(m_scenario);
}

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(FRAME_RATE);

	const int panelW = 2;
	const int panelH = 2;
	const int gridW = panelW * 160;
	const int gridH = panelH * 90;

	m_game = new Game(gridW, gridH);
	m_game->addAcorn((gridW / 2) - 3, (gridH / 2) - 3);

	m_context = new RenderContext(panelW, panelH, gridW, gridH, 1600, 900);

	m_renderer = new GameRenderer();
	m_renderer->Attach(m_game);
	m_renderer->Attach(m_context);

	m_controller = new GameController();
	m_controller->attach(m_game);
	m_controller->attach(m_context);

	m_scenario = new Scenario(m_controller, m_renderer, m_context);
}

using MouseButton = int;
const MouseButton MouseL = 0;
const MouseButton MouseM = 1;
const MouseButton MouseR = 2;

//--------------------------------------------------------------
void ofApp::update(){
	if (isStart)
	{
		m_scenario->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (isStart)
	{
		m_renderer->Render();
	}
	else
	{
		ofClear(ofColor::white);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// m_game->step();
	isStart = true;
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
