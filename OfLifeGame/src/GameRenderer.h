#pragma once

class Game;

class RenderContext
{
public:
	RenderContext()
		: panelPhysW(10),
		panelPhysH(10),
		globalPhysW(1600),
		globalPhysH(1000)
	{
		zoomRate = 1.0;
		left = 0;
		top = 0;
	}

	float globalW() const { return globalPhysW * zoomRate; }
	float globalH() const { return globalPhysH * zoomRate; }
	float panelW() const { return panelPhysW * zoomRate; }
	float panelH() const { return panelPhysH * zoomRate; }
	void zoom(float screenX, float screenY, float newZ)
	{
		float actualX = (left + screenX);
	}

private:
	const float panelPhysW;
	const float panelPhysH;
	const float globalPhysW;
	const float globalPhysH;
	float zoomRate;
	float left;
	float top;
};

class GameRenderer
{
public:
	GameRenderer();
	~GameRenderer();

	void AttachGame(Game* p) { m_pGame = p; }

	void Render();

private:
	Game* m_pGame;
};

