#pragma once

class Game;
class RenderContext;

class GameController
{
public:

	void Attach(Game* ptr) { m_game = ptr; }
	void Attach(RenderContext* ptr) { m_context = ptr; }

private:
	Game* m_game;
	RenderContext* m_context;
};