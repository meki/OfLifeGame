#pragma once
#include "Image2D.h"

class Game;
class RenderContext;

class GameRenderer
{
	struct Panel
	{
		Panel()
		{
			isAccessed = false;
			count = 0;
		}

		bool isAccessed;
		int count;
	};

public:
	GameRenderer();
	~GameRenderer();

	void Attach(Game* ptr);

	void Attach(RenderContext* ptr) { m_context = ptr; }

	void Render();

private:
	const Game* m_game;
	RenderContext* m_context;

	Image2D<Panel> m_panel;
};

