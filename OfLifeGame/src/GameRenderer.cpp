#include "GameRenderer.h"
#include "Game.h"
#include "ofApp.h"

GameRenderer::GameRenderer()
	: m_pGame(NULL)
{
}


GameRenderer::~GameRenderer()
{
}

void GameRenderer::Render()
{
	if (!m_pGame) { return; }

	ofClear(ofColor::antiqueWhite);

	const auto& panel = m_pGame->getPanel();

	const int pw = 10;
	const int ph = 10;

	for (auto it = panel.begin(); it != panel.end(); ++it)
	{
		int left = pw * it.x;
		int top = pw * it.y;

		switch (*it)
		{
		case Empty:
			ofNoFill();
			ofSetColor(ofColor::gray);
			ofDrawRectangle(left, top, pw, ph);
		case Alive:
			ofFill();
			ofSetColor(ofColor::aliceBlue);
			ofDrawRectangle(left, top, pw, ph);
		default:
			break;
		}
	}

}
