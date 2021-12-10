#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_RECTANGLE_H
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_RECTANGLE_H

#include "drawableprimitive/primitive.h"
#include "geometry/point.h"

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class Rectangle : public Primitive
{
public:
	Rectangle(geometry::Coordinate width, geometry::Coordinate height, geometry::Coordinate radius)
		: Primitive{Primitive::Type::Rectangle}
		, width{width}
		, height{height}
		, radius{radius}
	{
	}

	Rectangle(const Rectangle& other)
		: Primitive{other.type}
		, width{other.width}
		, height{other.height}
		, radius{other.radius}
	{
	}

	geometry::Coordinate width;
	geometry::Coordinate height;
	geometry::Coordinate radius;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_RECTANGLE_H
