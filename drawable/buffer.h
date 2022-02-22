#ifndef NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_BUFFER_H_
#define NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_BUFFER_H_

#include "drawable/drawable.h"
#include "geometry/coordinate.h"
#include "sample.h"
#include "oscdisplaycolor.h"
#include "drawableprimitive/point.h"
#include "drawableprimitive/line.h"
#include "drawableprimitive/colorstrike.h"

#include <vector>

namespace nboul {
namespace oscdisplay {
namespace drawable {

class Buffer : public Drawable {

public:
	Buffer(sample::Sample minSampleValue, sample::Sample maxSampleValue, geometry::Coordinate minY, geometry::Coordinate maxY, const OscDisplayColor& color)
		: minSampleValue{minSampleValue}
		, maxSampleValue{maxSampleValue}
		, minY{minY}
		, maxY{maxY}
		, color{color}
	{
	}

	void clearSamples()
	{
		m_samples.clear();
		deletePrimitives();
	}

	void setSampleAt(geometry::Coordinate x, sample::Sample sample)
	{
		if (static_cast<sample::Sample>(m_samples.size()) > x) {
			// Sample index already exists, overwrite it
			m_samples[x] = sample;
		} else {
			// Fill with empty samples until requested position
			while (static_cast<sample::Sample>(m_samples.size()) < x)
				m_samples.push_back(minSampleValue);
			m_samples.push_back(sample);
		}
	}

	void setDrawRange(geometry::Coordinate xStart, geometry::Coordinate xEnd)
	{
		m_drawXStart = xStart;
		m_drawXEnd = xEnd;
	}

	void updatePrimitives() override
	{
		const bool doAlloc = (m_allPrimitives.size() != m_samples.size() + 1);
		int iPrimitive = 0;

		if (doAlloc)
			deletePrimitives();

		const drawableprimitive::ColorStrike& colorStrike{color};
		if (doAlloc)
			primitives.push_back(new drawableprimitive::ColorStrike{colorStrike});
		else
			*reinterpret_cast<drawableprimitive::ColorStrike*>(primitives[iPrimitive++]) = colorStrike;

		geometry::Coordinate y = map(m_samples[m_drawXStart]);
		geometry::Coordinate prevY = y;

		for (geometry::Coordinate x = m_drawXStart + 1; x <= m_drawXEnd; x++) {
			y = map(m_samples[x]);
			const drawableprimitive::Line& line{{x - 1, prevY}, {x, y}};

			if (doAlloc)
				primitives.push_back(new drawableprimitive::Line{line});
			else
				*reinterpret_cast<drawableprimitive::Line*>(primitives[iPrimitive++]) = line;

			prevY = y;
		}
	}

	sample::Sample minSampleValue;
	sample::Sample maxSampleValue;
	geometry::Coordinate minY;
	geometry::Coordinate maxY;
	OscDisplayColor color;

private:
	geometry::Coordinate map(sample::Sample sample) const
	{
		if (sample >= maxSampleValue)
			return maxY;
		if (sample <= minSampleValue)
			return minY;
		return (maxY - minY) * (sample - minSampleValue) / (maxSampleValue - minSampleValue) + minY;
	}

	int m_drawXStart = 0;
	int m_drawXEnd = 0;
	std::vector<sample::Sample> m_samples;
	std::vector<drawableprimitive::Primitive*> m_allPrimitives;
	bool m_primitivesUpToDate = false;
};

}  // namespace drawableprimitive
}  // namespace oscdisplay
}  // nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLEPRIMITIVE_BUFFER_H_
