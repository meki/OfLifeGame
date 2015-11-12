#include "Game.h"
#include <cassert>

// debug
#include <iostream>
using namespace std;

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
	int liveCount = 0;

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

				if (x < 0 || x >= (int)m_panel.width || y < 0 || y >= (int)m_panel.height)
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
		}

		if (*it == Alive) { ++liveCount; }
	}

	++m_generation;

	cout << "generation: " << m_generation << ", lives: " << liveCount << endl;
}

void Game::createLive(int x, int y)
{
	m_panel(x, y) = Alive;
}

void Game::kill(int x, int y)
{
	m_panel(x, y) = Empty;
}
