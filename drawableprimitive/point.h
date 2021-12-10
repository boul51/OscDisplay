#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_POINT_H_
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_POINT_H_

#include "drawableprimitive/primitive.h"
#include "geometry/point.h"

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class Point : public Primitive {
public:
	Point(geometry::Coordinate x, geometry::Coordinate y)
		: Primitive{Primitive::Type::Point}
		, point{x, y}
	{
	}

	geometry::Point point;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_POINT_H_
