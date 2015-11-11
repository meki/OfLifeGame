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

	const Panel& getPanel() const { return m_panel; }

private:

	Image2D<State> m_panel;
	int m_generation;
};

