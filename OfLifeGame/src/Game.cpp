#include "Game.h"
#include <cassert>

Game::Game(int w, int h)
	: m_panel(w, h),
	m_generation(1)
{
	for (auto& v : m_panel) { v = Empty; }
}


Game::~Game()
{
}

void Game::step()
{
	auto foreachNeighbor = [&](int cx, int cy, auto action) {
		for (int y = cy - 1; y <= cy + 1; ++y) {
			for (int x = cx - 1; x <= cx + 1; ++x) {
				action();
			}
		}
	};

	for (auto it = m_panel.begin(); it != m_panel.end(); ++it)
	{
		const int cx = it.x;
		const int cy = it.y;

		bool isAlive = (*it == Alive);

		int liveCount = 0;
		int deathCount = 0;
		for (int y = cy - 1; y <= cy + 1; ++y) {
			for (int x = cx - 1; x <= cx + 1; ++x) {
				if (x == cx && y == cy)
				{
					continue;
				}

				switch (m_panel(x, y))
				{
				case Empty:
					++deathCount;
					break;
				case Alive:
					++liveCount;
					break;
				default:
					assert(false);
					break;
				}

				switch (*it)
				{
				case Empty:
				{	// ”­¶
					if (liveCount == 3) { *it = Alive; }
					break;
				}
				case Alive:
				{
					if (liveCount <= 1)
					{	// ‰ß‘a
						*it = Empty;
					}
					else if (liveCount <= 3)
					{	// ‘¶‘±
						*it = Alive;
					}
					else {
						// ‰ß–§
						*it = Empty;
					}
					break;
				}

				default:
					assert(false);
					break;
				}

			}
		}
	}
}
