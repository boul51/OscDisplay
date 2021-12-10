#include "robotlcdoscdisplaydriver.h"
#include "platform_logger.h"
#include "geometry/coordinate.h"

#include <Arduino.h>

namespace nboul {
namespace oscdisplay {

RobotLcdDisplayDriver::RobotLcdDisplayDriver(int width, int height, uint8_t blPin, uint8_t resetPin, uint8_t dcPin, uint8_t csPin)
	: OscDisplayDriver{width, height}
	, m_tft{new TFT{csPin, dcPin, resetPin}}
	, m_blPin{blPin}
{
	loginfo("RobotLcdDisplayDriver display size: %dx%d\n", width, height);

	m_tft->begin();
	m_tft->setRotation(3);
	analogWrite(blPin, 128);
}

void RobotLcdDisplayDriver::drawBackground()
{
	m_tft->background(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b);
}

void RobotLcdDisplayDriver::drawPoint(const drawableprimitive::Point& point, const geometry::Point& position)
{
	m_tft->point(static_cast<int16_t>(point.point.x + position.x),
				 static_cast<int16_t>(point.point.y + position.y));
}

void RobotLcdDisplayDriver::drawLine(const drawableprimitive::Line& line, const geometry::Point& position)
{
	m_tft->line(static_cast<int16_t>(line.line.p0.x + position.x),
				static_cast<int16_t>(line.line.p0.y + position.y),
				static_cast<int16_t>(line.line.p1.x + position.x),
				static_cast<int16_t>(line.line.p1.y + position.y));
}

void RobotLcdDisplayDriver::drawColorStrike(const drawableprimitive::ColorStrike& colorStrike)
{
	m_colorStrikeOpt = m_eraseMode ? m_backgroundColor : colorStrike.colorOpt;
	if (m_colorStrikeOpt)
		m_tft->stroke(m_colorStrikeOpt->r, m_colorStrikeOpt->g, m_colorStrikeOpt->b);
}

void RobotLcdDisplayDriver::drawColorFill(const drawableprimitive::ColorFill& colorFill)
{
	m_colorFillOpt = m_eraseMode ? m_backgroundColor : colorFill.colorOpt;
	if (m_colorFillOpt)
		m_tft->fill(m_colorFillOpt->r, m_colorFillOpt->g, m_colorFillOpt->b);
}

void RobotLcdDisplayDriver::drawRectangle(const drawableprimitive::Rectangle& rectangle, const geometry::Point& position)
{
	if (m_colorStrikeOpt)
		m_tft->rect(position.x, position.y, rectangle.width, rectangle.height, rectangle.radius);
	else if (m_colorFillOpt)
		m_tft->fillRect(position.x, position.y, rectangle.width, rectangle.height, m_tft->Color565(m_colorFillOpt->r, m_colorFillOpt->g, m_colorFillOpt->b));

}

}  // namespace oscdisplay
}  // namespace nboul
