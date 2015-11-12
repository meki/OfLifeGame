#pragma once
#include "Image2D.h"

using State = int;

const State Empty = 0;
const State Alive = 1;

class Game
{
public:
	using Panel = Image2D<State>;

	Game(int w, int h);
	~Game();

	void step();

	void createLive(int x, int y);

	void kill(int x, int y);

	const Panel& getPanel() const { return m_panel; }

private:

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	Image2D<State> m_panel;
	int m_generation;
};

