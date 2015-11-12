#include "GameRenderer.h"
#include "Game.h"
#include "RenderContext.h"
#include "ofApp.h"

GameRenderer::GameRenderer()
	: m_game(NULL)
{
}


GameRenderer::~GameRenderer()
{
}

void GameRenderer::Render()
{
	if (!m_game || !m_context) { return; }

	ofClear(ofColor::antiqueWhite);

	const auto& panel = m_game->getPanel();

	const int pw = m_context->panelW();
	const int ph = m_context->panelH();

	for (auto it = panel.begin(); it != panel.end(); ++it)
	{
		int left = pw * it.x - m_context->getPaddingL();
		int top = ph * it.y - m_context->getPaddingT();

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
