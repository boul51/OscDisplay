#ifndef NBOUL_OSCDISPLAY_DRAWABLE_GRID_H_
#define NBOUL_OSCDISPLAY_DRAWABLE_GRID_H_

#include "drawable/drawable.h"
#include "drawableprimitive/line.h"
#include "drawableprimitive/colorstrike.h"
#include "geometry/coordinate.h"
#include "geometry/point.h"
#include "oscdisplaycolor.h"

#include <vector>
#include <algorithm>

namespace nboul {
namespace oscdisplay {
namespace drawable {

class Grid : public Drawable {
public:
	struct Division {
		int main;
		int sub;
	};

	enum LineType {
		Main,
		Sub,
	};

	enum LineOrientation {
		Horizontal,
		Vertical,
	};

	Grid(int width, int height, const Division& hDivision, const Division& vDivision, const OscDisplayColor& mainColor, const OscDisplayColor& subColor)
		: width(width)
		, height(height)
		, hDivision(hDivision)
		, vDivision(vDivision)
		, mainColor(mainColor)
		, subColor(subColor)
	{
		addPrimitives();
	}

	int width;
	int height;
	Division hDivision;
	Division vDivision;
	OscDisplayColor mainColor;
	OscDisplayColor subColor;

private:
	void addPrimitives()
	{
		// Add main lines first, so that when adding sub lines we can check if a main line
		// already exists with the same points.
		// If so, don't add the sub line, since it will be covered by the main line anyway
		addPrimitives(LineType::Main, LineOrientation::Horizontal);
		addPrimitives(LineType::Main, LineOrientation::Vertical);
		primitives.push_back(new drawableprimitive::ColorStrike{subColor});
		addPrimitives(LineType::Sub, LineOrientation::Horizontal);
		addPrimitives(LineType::Sub, LineOrientation::Vertical);
		primitives.push_back(new drawableprimitive::ColorStrike{mainColor});

		// Reverse the vector so that we draw the sub lines first (main lines must be drawn on top of them)
		std::reverse(primitives.begin(), primitives.end());
	}

	// Check if a line with the same points already exists in the primitives
	static bool containsLines(const std::vector<drawableprimitive::Primitive*>& v, const geometry::Line& line)
	{
		return std::find_if(v.cbegin(), v.cend(), [line](const drawableprimitive::Primitive* primitive) {
			const drawableprimitive::Line* oldLine = reinterpret_cast<const drawableprimitive::Line*>(primitive);
			return primitive->type == drawableprimitive::Primitive::Type::Line
					&& oldLine->line.p0 == line.p0
					&& oldLine->line.p1 == line.p1;
		}) != v.cend();
	}

	void addPrimitives(LineType type, LineOrientation orientation)
	{
		const Division& div = (orientation == LineOrientation::Vertical ? hDivision : vDivision);
		const int* const divisions = (type == LineType::Main ? &div.main : &div.sub);
		const int linesCount = *divisions + 1;

		for (int i = 0; i < linesCount; i++) {
			geometry::Coordinate x0, y0, x1, y1;
			if (orientation == LineOrientation::Horizontal) {
				x0 = 0;
				x1 = width;
				y0 = y1 = i * height / *divisions;
			} else {
				y0 = 0;
				y1 = height;
				x0 = x1 = i * width / *divisions;
			}

			primitives.push_back(new drawableprimitive::Line{{x0, y0}, {x1, y1}});
		}
	}
};

}  // namespace drawable
}  // namespace oscdisplay
}  // nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLE_GRID_H_
