#ifndef OSCDISPLAY_TEST_OSCDISPLAYDRIVERCREATOR_H
#define OSCDISPLAY_TEST_OSCDISPLAYDRIVERCREATOR_H

#include "oscdisplaydriver.h"

namespace nboul {
namespace oscdisplay {
namespace test {

class OscDisplayDriverCreator {
public:
    enum class DriverType {
        RobotLcd = 0,
    };

    static OscDisplayDriver* create(DriverType type);
};

}  // namespace test
}  // namespace oscdisplay
}  // namespace nboul

#endif
