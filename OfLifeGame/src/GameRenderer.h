#pragma once

class Game;
class RenderContext;

class GameRenderer
{
public:
	GameRenderer();
	~GameRenderer();

	void Attach(Game* ptr) { m_game = ptr; }

	void Attach(RenderContext* ptr) { m_context = ptr; }

	void Render();

private:
	const Game* m_game;
	RenderContext* m_context;
};

