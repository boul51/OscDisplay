#include "oscdisplay.h"

namespace nboul {
namespace oscdisplay {

OscDisplay::OscDisplay(OscDisplayDriver* driver)
	: m_driver{driver}
{
}

void OscDisplay::setBackgroundColor(const OscDisplayColor& color)
{
	m_driver->setBackgroundColor(color);
}

void OscDisplay::setGrid(const drawable::Grid& grid, const geometry::Point& position)
{
	m_grid = new drawable::Grid(grid.width, grid.height, grid.hDivision, grid.vDivision, grid.mainColor, grid.subColor);
	m_gridPosition = position;
}

void OscDisplay::drawGrid()
{
	m_driver->drawDrawable(*m_grid, m_gridPosition);
}

}  // namespace oscdisplay
}  // namespace nboul
