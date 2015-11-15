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

	ofClear(ofColor::white);

	const auto& panel = m_game->getPanel();
	const auto& oldPanel = m_game->getOldPanel();

	const int pw = m_context->panelW();
	const int ph = m_context->panelH();

// 	for (auto it = panel.begin(); it != panel.end(); ++it)
// 	{
// 		int left = pw * it.x - m_context->getPaddingL();
// 		int top = ph * it.y - m_context->getPaddingT();
// 
// 		ofNoFill();
// 		ofSetColor(ofColor::gray);
// 		ofDrawRectangle(left, top, pw, ph);
// 	}

	static int c = 0;
	++c;
	c = c % 256;

	for (auto it = panel.begin(); it != panel.end(); ++it)
	{
		int left = (pw * it.x - m_context->getPaddingL());
		int top = (ph * it.y - m_context->getPaddingT());

		switch (*it)
		{
		case Empty:
			switch (oldPanel(it.getPoint()))
			{
			case Alive:
				ofFill();
				ofSetColor(ofColor(255, 0, 0, 32));
				ofDrawRectangle(left, top, pw, ph);
				break;
			case Empty:
				break;
			default:
				break;
			}
			break;
		case Alive:
		{
			ofFill();
			//ofSetColor(ofColor::deepPink);
			ofSetColor(ofColor::fromHsb(c, 255, 255));
			ofDrawRectangle(left, top, pw, ph);
		}
			break;
		default:
			break;
		}
	}

	ofNoFill();
	ofSetColor(ofColor::gray);
	for (int x = 0; x <= panel.getWidth(); ++x)
	{
		int scX = (pw * x) - m_context->getPaddingL();
		int scY = ph * panel.getHeight() - m_context->getPaddingT();
		ofDrawLine(scX, 0, scX, scY);
	}

	for (int y = 0; y <= panel.getHeight(); ++y)
	{
		int scX = pw * panel.getWidth() - m_context->getPaddingL();
		int scY = (ph * y) - m_context->getPaddingT();
		ofDrawLine(0, scY, scX, scY);
	}

}
