#pragma once
#include <Image2D.h>

class Game;
class RenderContext;

class GameController
{
public:

	void attach(Game* ptr) { m_game = ptr; }
	void attach(RenderContext* ptr) { m_context = ptr; }

	void addLife(int screenX, int screenY);
	void toggleLife(int screenX, int screenY);

	void step();

	Point screenToGame(int screenX, int screenY) const;

private:
	Game* m_game;
	RenderContext* m_context;
};