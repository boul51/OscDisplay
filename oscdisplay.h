#include "oscdisplaydriver.h"

namespace nboul {

namespace oscdisplaydriver {
class OscDisplayDriver;
}  // namespace oscdisplaydriver

namespace oscdisplay {

class OscDisplay
{
public:
	OscDisplay(int width, int height, oscdisplaydriver::OscDisplayDriver* driver);

private:
	int m_width = 0;
	int m_height = 0;
	oscdisplaydriver::OscDisplayDriver* m_driver = nullptr;
};

}  // namespace oscdisplay
}  // namespace nboul
