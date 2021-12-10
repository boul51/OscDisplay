#ifndef NBOUL_OSCDISPLAY_OSCDISPLAY_H
#define NBOUL_OSCDISPLAY_OSCDISPLAY_H

#include "oscdisplaydriver.h"
#include "oscdisplaycolor.h"
#include "drawable/grid.h"
#include "geometry/point.h"

namespace nboul {
namespace oscdisplay {

class OscDisplayDriver;

class OscDisplay
{
public:
	OscDisplay(OscDisplayDriver* driver);
	void setBackgroundColor(const OscDisplayColor& color);
	void setGrid(const drawable::Grid& grid, const geometry::Point& position);
	const OscDisplayDriver* driverConst() const { return m_driver; }
	OscDisplayDriver* driver() { return m_driver; }
	void drawGrid();

private:
	OscDisplayDriver* m_driver = nullptr;
	drawable::Grid* m_grid = nullptr;
	geometry::Point m_gridPosition;
};

}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_OSCDISPLAY_H
