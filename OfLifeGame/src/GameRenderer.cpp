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

void GameRenderer::Attach(Game* ptr)
{
	m_game = ptr;
	auto p = m_game->getPanel();
	m_panel = Image2D<Panel>(p.getWidth(), p.getHeight());
}

void GameRenderer::Render()
{
	if (!m_game || !m_context) { return; }

	ofClear(ofColor::white);

	const auto& panel = m_game->getPanel();
	const auto& oldPanel = m_game->getOldPanel();

	for (auto it = panel.begin(); it != panel.end(); ++it)
	{
		auto pt = it.getPoint();
		if(*it == Alive)
		{
			m_panel(pt).isAccessed = true;
			m_panel(pt).count += 1;
		}
		else
		{
			if (oldPanel(pt) == Alive)
			{
				m_panel(pt).count = 0;
			}
		}
	}

	const int pw = m_context->panelW();
	const int ph = m_context->panelH();

	// draw panels
	ofFill();
	for (auto it = panel.begin(); it != panel.end(); ++it)
	{
		int left = (pw * it.x - m_context->getPaddingL());
		int top = (ph * it.y - m_context->getPaddingT());

		auto pt = it.getPoint();

		switch (*it)
		{
		case Empty:
			switch (oldPanel(pt))
			{
			case Alive:
				ofSetColor(ofColor(255, 0, 0, 64));
				ofDrawRectangle(left, top, pw, ph);
				break;
			case Empty:
				break;
			default:
				break;
			}

			if (m_panel(pt).isAccessed)
			{
				ofSetColor(ofColor(0, 255, 0, 16));
				ofDrawRectangle(left, top, pw, ph);
			}

			break;
		case Alive:
		{
			//ofSetColor(ofColor(255, 0, 100));
			//ofSetColor(ofColor::deepPink);

			// hue   0 = red
			//      64 = light green
			//     128 = light blue
			//     196 = violet
			//     255 = red
			const int countMax = 60 * 3;
			const int countMin = 60 * 5;
			int effectiveCount = m_panel(pt).count - countMin;
			if (effectiveCount < 0)
			{
				effectiveCount = 0;
			}

			if (effectiveCount > countMax)
			{
				effectiveCount = countMax;
			}

			int hueFrm = 255;
			int hueTo = 64;
			int hue = ofMap(effectiveCount, 0, 200, hueFrm, hueTo);

			int satFrm = 255;
			int satTo = 128;
			int sat = ofMap(effectiveCount, 0, 200, satFrm, satTo);

			int briFrm = 255;
			int briTo = 128;
			int bri = ofMap(effectiveCount, 0, 200, briFrm, briTo);

			ofSetColor(ofColor::fromHsb(hue, sat, bri));
			ofDrawRectangle(left, top, pw, ph);
		}
			break;
		default:
			break;
		}
	}

	ofNoFill();
	ofSetColor(ofColor::ghostWhite);
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
