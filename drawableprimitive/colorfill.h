#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORFILL_H_
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORFILL_H_

#include "drawableprimitive/primitive.h"
#include "oscdisplaycolor.h"

#include "optional.h"

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class ColorFill : public Primitive {
public:
	ColorFill(const OscDisplayColorOpt& colorOpt)
		: Primitive{Primitive::Type::ColorFill}
		, colorOpt{colorOpt}
	{
	}

	OscDisplayColorOpt colorOpt;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORFILL_H_
