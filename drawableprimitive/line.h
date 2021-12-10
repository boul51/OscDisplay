#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_LINE_H
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_LINE_H

#include "drawableprimitive/primitive.h"
#include "geometry/line.h"

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class Line : public Primitive
{
public:
	Line(const geometry::Point& p0, const geometry::Point& p1)
		: Primitive{Primitive::Type::Line}
		, line{p0, p1}
	{
	}

	Line(const Line& other)
		: Primitive{other.type}
		, line{other.line.p0, other.line.p1}
	{
	}

	geometry::Line line;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_LINE_H
