#ifndef NOUL_OSCDISPLAY_ROBOTLCDDISPLAYDRIVER_H
#define NOUL_OSCDISPLAY_ROBOTLCDDISPLAYDRIVER_H

#include "oscdisplaydriver.h"
#include "oscdisplaycolor.h"

#include "TFT.h"

#include "optional.h"

namespace nboul {
namespace oscdisplay {

class RobotLcdDisplayDriver : public OscDisplayDriver {
public:
	RobotLcdDisplayDriver(int width, int height, uint8_t blPin, uint8_t resetPin, uint8_t dcPin, uint8_t csPin);
	void drawBackground() override;
	void drawPoint(const drawableprimitive::Point& point, const geometry::Point& position = geometry::Point{}) override;
	void drawLine(const drawableprimitive::Line& line, const geometry::Point& position = geometry::Point{}) override;
	void drawRectangle(const drawableprimitive::Rectangle &rectangle, const geometry::Point &position) override;
	void drawColorStrike(const drawableprimitive::ColorStrike &colorStrike) override;
	void drawColorFill(const drawableprimitive::ColorFill &colorFill) override;

private:
	TFT* m_tft = nullptr;
	uint8_t m_blPin = 0;  // backlight pin
	nonstd::optional<OscDisplayColor> m_colorStrikeOpt;
	nonstd::optional<OscDisplayColor> m_colorFillOpt;
};

}  // namespace oscdisplay
}  // namespace nboul

#endif  // NOUL_OSCDISPLAY_ROBOTLCDDISPLAYDRIVER_H
