#ifndef NBOUL_OSCDISPLAY_OSCDISPLAYCOLOR_H
#define NBOUL_OSCDISPLAY_OSCDISPLAYCOLOR_H

#include "optional.h"

namespace nboul {
namespace oscdisplay {

struct OscDisplayColor {
	int r;
	int g;
	int b;

	OscDisplayColor(int r, int g, int b)
		: r(r)
		, g(g)
		, b(b)
	{
	}

	OscDisplayColor(const OscDisplayColor& other)
		: r(other.r)
		, g(other.g)
		, b(other.b)
	{
	}

	OscDisplayColor operator*(float mult) const
	{
		return OscDisplayColor{static_cast<int>(r * mult), static_cast<int>(g * mult), static_cast<int>(b * mult)};
	}

	OscDisplayColor lighter(float mult) const
	{
		return *this * mult;
	}

	OscDisplayColor darker(float mult) const
	{
		return *this * (1/mult);
	}

};

using OscDisplayColorOpt = nonstd::optional<OscDisplayColor>;

namespace colors {
static const OscDisplayColor Red{255, 0, 0};
static const OscDisplayColor Green{0, 255, 0};
static const OscDisplayColor Blue{0, 0, 255};

static const OscDisplayColor White{255, 255, 255};
static const OscDisplayColor Black{0, 0, 0};

static const OscDisplayColor Yellow{255, 255, 0};
static const OscDisplayColor Cyan{0, 255, 255};
static const OscDisplayColor Magenta{255, 00, 255};

static const OscDisplayColorOpt None;

}  // namespace colors

}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_OSCDISPLAYCOLOR_H
