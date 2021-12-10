#ifndef NBOUL_OSCDISPLAY_DRAWABLE_RECTANGLE_H
#define NBOUL_OSCDISPLAY_DRAWABLE_RECTANGLE_H

#include "drawable/drawable.h"
#include "drawableprimitive/rectangle.h"
#include "drawableprimitive/colorstrike.h"
#include "drawableprimitive/colorfill.h"
#include "geometry/coordinate.h"
#include "oscdisplaycolor.h"

#include "optional.h"

namespace nboul {
namespace oscdisplay {
namespace drawable {

struct Rectangle : public Drawable {

public:

	Rectangle(geometry::Coordinate width, geometry::Coordinate height, geometry::Coordinate radius, const OscDisplayColorOpt& strikeColorOpt, const OscDisplayColorOpt& fillColorOpt)
		: width{width}
		, height{height}
		, radius{radius}
		, strikeColorOpt{strikeColorOpt}
		, fillColorOpt{fillColorOpt}
	{
		updatePrimitives();
	}

	geometry::Coordinate width;
	geometry::Coordinate height;
	geometry::Coordinate radius;

	OscDisplayColorOpt strikeColorOpt;
	OscDisplayColorOpt fillColorOpt;

	void updatePrimitives()
	{
		primitives.push_back(new drawableprimitive::ColorStrike{strikeColorOpt});
		primitives.push_back(new drawableprimitive::ColorFill{fillColorOpt});
		primitives.push_back(new drawableprimitive::Rectangle{width, height, radius});
	}
};

}  // namespace drawable
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_RECTANGLE_H
