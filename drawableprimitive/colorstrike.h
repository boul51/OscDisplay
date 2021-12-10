#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORSTRIKE_H_
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORSTRIKE_H_

#include "drawableprimitive/primitive.h"
#include "oscdisplaycolor.h"

#include "optional.h"

namespace nboul {
namespace oscdisplay {
namespace drawableprimitive {

class ColorStrike : public Primitive {
public:
	ColorStrike(const OscDisplayColorOpt& colorOpt)
		: Primitive{Primitive::Type::ColorStrike}
		, colorOpt{colorOpt}
	{
	}

	OscDisplayColorOpt colorOpt;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_COLORSTRIKE_H_
