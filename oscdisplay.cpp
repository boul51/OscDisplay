#include "oscdisplay.h"

namespace nboul {
namespace oscdisplay {

OscDisplay::OscDisplay(int width, int height, nboul::oscdisplaydriver::OscDisplayDriver* driver)
	: m_width{width}
	, m_height{height}
	, m_driver{driver}
{
}

}  // namespace oscdisplay
}  // namespace nboul
