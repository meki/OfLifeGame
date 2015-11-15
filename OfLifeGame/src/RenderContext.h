#pragma once

class RenderContext
{
public:
	RenderContext(int pw, int ph, int w, int h, int winW, int winH)
		: panelPhysW(pw),
		panelPhysH(ph),
		globalPhysW(pw * w),
		globalPhysH(ph * h),
		windowW(winW),
		windowH(winH),
		MIN_ZOOM_RATE(10.0 / pw)
	{
		zoomRate = 10.0 / pw;
		paddingLeft = 0;
		paddingTop = 0;
	}

	double globalW() const { return globalPhysW * zoomRate; }
	double globalH() const { return globalPhysH * zoomRate; }
	double panelW() const { return panelPhysW * zoomRate; }
	double panelH() const { return panelPhysH * zoomRate; }
	
	void setZoomRate(double rate) { zoomRate = rate; }
	void zoomIncrement(double screenX, double screenY, double deltaZoom);

	double screenToPhysX(double xScreen) const {
		return (paddingLeft + xScreen) / zoomRate;
	}

	double screenToPhysY(double yScreen) const {
		return (paddingTop + yScreen) / zoomRate;
	}

	void setPaddingL(double value) { paddingLeft = value; }
	void setPaddingT(double value) { paddingTop = value; }

	double getPaddingL() const { return paddingLeft; }
	double getPaddingT() const { return paddingTop; }

private:
	const double panelPhysW;
	const double panelPhysH;
	const double globalPhysW;
	const double globalPhysH;
	const double windowW;
	const double windowH;
	const double MIN_ZOOM_RATE;
	double zoomRate;
	double paddingLeft;
	double paddingTop;
};