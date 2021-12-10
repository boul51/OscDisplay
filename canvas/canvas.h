#ifndef NBOUL_OSCDISPLAY_CANVAS_H
#define NBOUL_OSCDISPLAY_CANVAS_H

#include "drawable/drawable.h"
#include "geometry/point.h"
#include "geometry/coordinate.h"
#include "oscdisplaydriver.h"

#include <vector>
#include <utility>
#include <algorithm>

namespace nboul {
namespace oscdisplay {

class Canvas
{
public:
	Canvas(OscDisplayDriver& driver)
		: m_driver(driver)
	{
	}

	void addDrawable(drawable::Drawable* drawable, const geometry::Point& position, geometry::ZCoordinate z)
	{
		m_drawables.push_back({drawable, position, z});
		sortDrawables();
	}

	void draw()
	{
		for (const auto& drawable : m_drawables)
			m_driver.drawDrawable(*drawable.drawable, drawable.position);
	}

private:
	struct PositionedDrawable
	{
		drawable::Drawable* drawable;
		geometry::Point position;
		geometry::ZCoordinate z;
	};

	void sortDrawables()
	{
		std::sort(m_drawables.begin(), m_drawables.end(), [](const PositionedDrawable& d1, const PositionedDrawable& d2) {
			return d1.z < d2.z;
		});
	}

	std::vector<PositionedDrawable> m_drawables;
	OscDisplayDriver& m_driver;
};

}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_CANVAS_H
