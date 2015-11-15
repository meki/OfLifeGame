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

	double newPaddingLeft = (paddingLeft * relativeZoom) + (screenX * relativeZoom) - screenX;
	double newPaddingTop = (paddingTop * relativeZoom) + (screenY * relativeZoom) - screenY;

	log_v("zoom rate changed from %f to %f, padding(%f, %f) -> (%f, %f)\n", zoomRate, newZoom, paddingLeft, paddingTop, newPaddingLeft, newPaddingTop);

	zoomRate = newZoom;
	paddingLeft = newPaddingLeft;
	paddingTop = newPaddingTop;
}
