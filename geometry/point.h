#ifndef NBOUL_OSCDISPLAY_GEOMETRY_POINT_H
#define NBOUL_OSCDISPLAY_GEOMETRY_POINT_H

#include "geometry/coordinate.h"

namespace nboul {
namespace oscdisplay {
namespace geometry {

class Point
{
public:
	Coordinate x = 0;
	Coordinate y = 0;

	Point()
		: x(0)
		, y(0)
	{
	}

	Point(Coordinate x, Coordinate y)
		: x(x)
		, y(y)
	{
	}

	Point(int x, int y)
		: x{static_cast<Coordinate>(x)}
		, y{static_cast<Coordinate>(y)}
	{
	}

	bool operator == (const Point& other) const {
		return x == other.x && y == other.y;
	}
};

}  // namespace geometry
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_GEOMETRY_POINT_H
