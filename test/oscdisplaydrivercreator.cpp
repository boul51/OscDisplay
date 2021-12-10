#include "oscdisplaydrivercreator.h"
#include "robotlcdoscdisplaydriver.h"

namespace RobotLcd {
const int Width = 160;
const int Height = 128;

const uint8_t BlPin = 9;
const uint8_t ResetPin = 10;
const uint8_t DcPin = 11;
const uint8_t CsPin = 13;
}  // namespace

namespace nboul {
namespace oscdisplay {
namespace test {

OscDisplayDriver* OscDisplayDriverCreator::create(DriverType type)
{
    switch (type) {
    case DriverType::RobotLcd:
        return new RobotLcdDisplayDriver(RobotLcd::Width, RobotLcd::Height, RobotLcd::BlPin, RobotLcd::ResetPin, RobotLcd::DcPin, RobotLcd::CsPin);
    default:
        return nullptr;
    }
}

}  // namespace test
}  // namespace oscdisplay
}  // namespace nboul
