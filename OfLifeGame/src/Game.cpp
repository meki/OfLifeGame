#include "Game.h"
#include <cassert>

// debug
#include "debugLog.h"

Game::Game(int w, int h)
	: m_panel(w, h),
	m_generation(1)
{
	for (auto& v : m_panel) { v = Empty; }

	m_panelPrev = m_panel;
}


void Game::addLife(int x, int y)
{
	m_panel(x, y) = Alive;
}

Game::~Game()
{
}

void Game::step()
{
	int liveCount = 0;

	m_panelPrev = m_panel;

	const Panel& check = m_panelPrev;

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

				if (x < 0 || x >= (int)check.width || y < 0 || y >= (int)check.height)
				{
					continue;
				}

				switch (check(x, y))
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
			}
		}

		switch (*it)
		{
		case Empty:
		{	// î≠ê∂
			if (liveCount == 3) { *it = Alive; }
			break;
		}
		case Alive:
		{
			if (liveCount <= 1)
			{	// âﬂëa
				*it = Empty;
			}
			else if (liveCount <= 3)
			{	// ë∂ë±
				*it = Alive;
			}
			else {
				// âﬂñß
				*it = Empty;
			}
			break;
		}

		default:
			assert(false);
			break;
		}
	}

	++m_generation;

	if (m_generation % 50 == 0)
	{
		log_v("generation: %d, lives: %d\n", m_generation, liveCount);
	}
}

void Game::toggleLife(int x, int y)
{
	m_panel(x, y) = (m_panel(x, y) == Alive) ? Empty : Alive;
}

void Game::kill(int x, int y)
{
	m_panel(x, y) = Empty;
}

void Game::addAcorn(int x, int y)
{
	addLife(x + 2, y + 1);
	addLife(x + 4, y + 2);

	addLife(x + 1, y + 3);
	addLife(x + 2, y + 3);
	addLife(x + 5, y + 3);
	addLife(x + 6, y + 3);
	addLife(x + 7, y + 3);
}

void Game::addRPentomino(int x, int y)
{
	addLife(x + 2, y + 1);
	addLife(x + 3, y + 1);
	addLife(x + 1, y + 2);
	addLife(x + 2, y + 2);
	addLife(x + 2, y + 3);
}
