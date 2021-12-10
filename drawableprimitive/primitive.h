#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_PRIMITIVE_H
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_PRIMITIVE_H

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class Primitive
{
public:
	enum class Type {
		Point,
		Line,
		Text,
		Rectangle,
		ColorStrike,
		ColorFill,
	};

	Type type;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_PRIMITIVE_H
