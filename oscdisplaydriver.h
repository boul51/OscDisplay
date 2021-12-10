#ifndef NBOUL_OSCDISPLAY_OSCDISPLAYDRIVER_H
#define NBOUL_OSCDISPLAY_OSCDISPLAYDRIVER_H

#include "oscdisplaycolor.h"
#include "drawable/drawable.h"
#include "drawableprimitive/primitive.h"
#include "drawableprimitive/point.h"
#include "drawableprimitive/line.h"
#include "drawableprimitive/rectangle.h"
#include "drawableprimitive/colorstrike.h"
#include "drawableprimitive/colorfill.h"
#include "geometry/coordinate.h"

namespace nboul {
namespace oscdisplay {

class OscDisplayDriver {
public:
	OscDisplayDriver(int width, int height);
	void setBackgroundColor(const OscDisplayColor& color);
	void drawPrimitive(const drawableprimitive::Primitive& primitive, const geometry::Point& position = geometry::Point{});
	void drawDrawable(const drawable::Drawable& drawable, const geometry::Point& position = geometry::Point{});
	void eraseDrawable(const drawable::Drawable& drawable, const geometry::Point& position = geometry::Point{});

	int width() const { return m_width; }
	int height() const { return m_height; }

protected:
	virtual void drawBackground() = 0;
	virtual void drawPoint(const drawableprimitive::Point& point, const geometry::Point& position = geometry::Point{}) = 0;
	virtual void drawLine(const drawableprimitive::Line& line, const geometry::Point& position = geometry::Point{}) = 0;
	virtual void drawRectangle(const drawableprimitive::Rectangle& rectangle, const geometry::Point& position = geometry::Point{}) = 0;
	virtual void drawColorStrike(const drawableprimitive::ColorStrike& colorStrike) = 0;
	virtual void drawColorFill(const drawableprimitive::ColorFill& colorFill) = 0;

	int m_width = 0;
	int m_height = 0;
	OscDisplayColor m_backgroundColor;
	bool m_eraseMode = false;
};

}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_OSCDISPLAYDRIVER_H
