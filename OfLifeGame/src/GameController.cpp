#include "GameController.h"
#include "Game.h"
#include "RenderContext.h"
#include <iostream>
using namespace std;

void GameController::addLife(int screenX, int screenY)
{
	Point p = screenToGame(screenX, screenY);

	m_game->addLife(p.x, p.y);
}

void GameController::toggleLife(int screenX, int screenY)
{
	Point p = screenToGame(screenX, screenY);

	m_game->toggleLife(p.x, p.y);
}

Point GameController::screenToGame(int x, int y) const
{
	Point out;

	int px = m_context->screenToPhysX(x);
	int py = m_context->screenToPhysY(y);

	out[0] = px / m_context->panelW();
	out[1] = py / m_context->panelH();

	cout << __FUNCTION__ << ": in(" << x << "," << y << ") ==> out(" << out[0] << "," << out[1] << ")\n";

	return out;
}
