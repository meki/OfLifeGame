#include "RenderContext.h"
#include "debugLog.h"

void RenderContext::zoomIncrement(double screenX, double screenY, double deltaZoom)
{
	double newZoom = zoomRate + deltaZoom;
	if (newZoom < MIN_ZOOM_RATE)
	{
		newZoom = MIN_ZOOM_RATE;
	}

	double relativeZoom = newZoom / zoomRate;

	double physX = screenToPhysX(screenX);
	double physY = screenToPhysY(screenY);

	double newX = physX * newZoom;
	double newY = physY * newZoom;

	double newPaddingLeft = -(screenX * relativeZoom) + newX;
	double newPaddingTop = -(screenY * relativeZoom) + newY;


// 	double newPaddingLeft = -screenX + (paddingLeft * relativeZoom) +(screenX * relativeZoom);
// 	double newPaddingTop = -screenY + (paddingTop * relativeZoom) +(screenY * relativeZoom);

	log_v("zoom rate changed from %f to %f, padding(%f, %f) -> (%f, %f)\n", zoomRate, newZoom, paddingLeft, paddingTop, newPaddingLeft, newPaddingTop);

	zoomRate = newZoom;
	paddingLeft = newPaddingLeft;
	paddingTop = newPaddingTop;
}
