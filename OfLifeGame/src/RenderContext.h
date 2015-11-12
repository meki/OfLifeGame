#pragma once

class RenderContext
{
public:
	RenderContext(int pw, int ph, int w, int h)
		: panelPhysW(pw),
		panelPhysH(ph),
		globalPhysW(pw * w),
		globalPhysH(ph * h)
	{
		zoomRate = 1.0;
		paddingLeft = 0;
		paddingTop = 0;
	}

	float globalW() const { return globalPhysW * zoomRate; }
	float globalH() const { return globalPhysH * zoomRate; }
	float panelW() const { return panelPhysW * zoomRate; }
	float panelH() const { return panelPhysH * zoomRate; }
	void zoomIncrement(float screenX, float screenY, float deltaZoom)
	{
		float newZoom = zoomRate + deltaZoom;
		float relativeZoom = newZoom / zoomRate;

		float newPaddingLeft = (paddingLeft * relativeZoom) + (screenX * relativeZoom) - screenX;
		float newPaddingTop = (paddingTop * relativeZoom) + (screenY * relativeZoom) - screenY;

		zoomRate = newZoom;
		paddingLeft = newPaddingLeft;
		paddingTop = newPaddingTop;
	}

	float screenToPhysX(float xScreen) const {
		return (paddingLeft + xScreen) / zoomRate;
	}

	float screenToPhysY(float yScreen) const {
		return (paddingTop + yScreen) / zoomRate;
	}

	float getPaddingL() const { return paddingLeft; }
	float getPaddingT() const { return paddingTop; }

private:
	const float panelPhysW;
	const float panelPhysH;
	const float globalPhysW;
	const float globalPhysH;
	float zoomRate;
	float paddingLeft;
	float paddingTop;
};