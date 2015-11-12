#pragma once

#include "ofMain.h"

class Game;
class GameRenderer;
class GameController;
class RenderContext;

class ofApp : public ofBaseApp{

public:

	~ofApp();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void mouseScrolled(int x, int y, float scrollX, float scrollY) override;

	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
		
private:
	Game* m_game;
	GameRenderer* m_renderer;
	GameController* m_controller;
	RenderContext* m_context;
};

template <typename T>
void SAFE_DELETE(T*& p) { delete p; p = 0; }