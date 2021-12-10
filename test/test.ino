#include <Arduino.h>

#include <MemoryFree.h>

#include "oscdisplay.h"
#include "oscdisplaycolor.h"
#include "drawable/grid.h"
#include "drawable/buffer.h"
#include "drawable/rectangle.h"
#include "canvas/canvas.h"
#include "drawableprimitive/point.h"
#include "robotlcdoscdisplaydriver.h"
#include "oscdisplaydrivercreator.h"
#include "sample.h"

#if HAS_LOGGER != 1
#define logdebug(...)
#define loginfo(...)
#define logwarning(...)
#define logerror(...)
#endif

#include "platform_logger.h"

#include <vector>
#include <chrono>
#include <limits>

/**** DEFINES ****/

#ifndef SERIAL_IFACE
#error "Please define SERIAL_IFACE to Serial (programming port) or SerialUSB (native port)"
#endif

using namespace nboul::oscdisplay;
using namespace nboul::sample;

namespace {
const test::OscDisplayDriverCreator::DriverType DriverType = test::OscDisplayDriverCreator::DriverType::RobotLcd;
}  // namespace

OscDisplay* g_display;

void testBgColor(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    const std::vector<OscDisplayColor> colors = {
        colors::Red,
        colors::Green,
        colors::Blue,
    };

    for (const auto& color: colors) {
        g_display->setBackgroundColor(color);
        delay(duration.count() / colors.size());
    }

    loginfo("%s--\n", __FUNCTION__);
}

void testPoint(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    geometry::Coordinate offset = 10;
    geometry::Coordinate x0 = offset;
    geometry::Coordinate x1 = g_display->driverConst()->width() - offset;
    geometry::Coordinate y0 = offset;
    geometry::Coordinate y1 = g_display->driverConst()->height() - offset;

    drawableprimitive::ColorStrike c1{colors::Green};
    drawableprimitive::Point p1{x0, y0};
    drawableprimitive::ColorStrike c2{colors::Red};
    drawableprimitive::Point p2{x1, y1};

    g_display->setBackgroundColor(colors::White);
    const int loops = 100;
    for (int i = 0; i < loops; i++) {
        g_display->driver()->drawPrimitive(c1);
        g_display->driver()->drawPrimitive(p1, geometry::Point{i, i});
        g_display->driver()->drawPrimitive(c2);
        g_display->driver()->drawPrimitive(p2, geometry::Point{-i, -i});
        delay(duration.count() / loops);
    }

    loginfo("%s--\n", __FUNCTION__);
}

void testLine(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    geometry::Coordinate offset = 20;
    geometry::Coordinate x0 = offset;
    geometry::Coordinate x1 = g_display->driverConst()->width() - offset;
    geometry::Coordinate y0 = offset;
    geometry::Coordinate y1 = g_display->driverConst()->height() - offset;

    g_display->setBackgroundColor(colors::Black);
    g_display->driver()->drawPrimitive(drawableprimitive::ColorStrike{colors::Cyan});
    g_display->driver()->drawPrimitive(drawableprimitive::Line{{x0, y0}, {x1, y1}});
    g_display->driver()->drawPrimitive(drawableprimitive::Line{{x0, y0}, {x1, y1}}, geometry::Point{0, 10});

    delay(duration.count());

    loginfo("%s--\n", __FUNCTION__);
}

void testBufferAllSamples(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    Sample minSampleValue = 0;
    Sample maxSampleValue = std::numeric_limits<Sample>::max();
    geometry::Coordinate minY = 0;
    geometry::Coordinate maxY = g_display->driver()->height() - 1;
    int samplesCount = g_display->driver()->width();
    drawable::Buffer buffer{minSampleValue, maxSampleValue, minY, maxY, colors::Magenta};
    buffer.setDrawRange(0, samplesCount - 1);

    g_display->driver()->setBackgroundColor(colors::White);

    int maxLoops = 0;  // 0 => draw until duration is elapsed, >0 => draw maxLoops loops
    int loops = 0;
    float pi = acos(-1.0);
    const int periodsPerScreen = 2;
    float phasePerLoop = - pi / 15;
    const float saturation = 1.3;

    int tStart = millis();

    while (millis() - tStart < duration.count() && (loops < maxLoops || maxLoops == 0)) {
        float phase = loops * phasePerLoop;
        buffer.clearSamples();
        for (int i = 0; i < samplesCount; i++) {
            float teta = 2 * pi * periodsPerScreen / samplesCount * i;
            DoubleSample dSample = (buffer.maxSampleValue * (0.5 + sin(teta + phase) * 0.5 * saturation));
            buffer.setSampleAt(i, clipped(dSample));
        }
        buffer.updatePrimitives();
        g_display->driver()->drawDrawable(buffer);
        loops++;
    }

    int elapsed = millis() - tStart;

    loginfo("%s--, drawn %d loops in %d ms (%d ms/loop)\n", __FUNCTION__, loops, elapsed, elapsed / loops);
}

void testBufferSingleSample(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    Sample minSampleValue = 0;
    Sample maxSampleValue = std::numeric_limits<Sample>::max();
    geometry::Coordinate minY = 0;
    geometry::Coordinate maxY = g_display->driver()->height() - 1;
    int samplesCount = g_display->driver()->width();
    drawable::Buffer buffer{minSampleValue, maxSampleValue, minY, maxY, colors::Magenta};

    g_display->driver()->setBackgroundColor(colors::White);

    int maxLoops = 0;  // 0 => draw until duration is elapsed, >0 => draw maxLoops loops
    float pi = acos(-1.0);
    const int periodsPerScreen = 2;
    const float saturation = 0.95;

    Sample* data = new Sample[samplesCount];
    for (int i = 0; i < samplesCount; i++) {
        float teta = 2 * pi * periodsPerScreen / samplesCount * i;
        DoubleSample dSample = (buffer.maxSampleValue * (0.5 + sin(teta) * 0.5 * saturation));
        data[i] = clipped(dSample);
    }

    int tStart = millis();
    int loops = 0;

    drawable::Grid grid{g_display->driver()->width() - 1, g_display->driver()->height() - 1, {2, 4}, {2, 4}, colors::Blue, colors::Blue.lighter(1.3)};

    while (millis() - tStart < duration.count() && (loops < maxLoops || maxLoops == 0)) {
        g_display->driver()->drawDrawable(grid);
        buffer.setSampleAt(0, data[0]);
        for (geometry::Coordinate x = 1; x < samplesCount; x++) {
            buffer.setSampleAt(x, data[x]);
            buffer.setDrawRange(x - 1, x);
            buffer.updatePrimitives();
            g_display->driver()->drawDrawable(buffer);
            delay(10);
        }
        delay(300);
        buffer.setDrawRange(0, samplesCount - 1);
        buffer.updatePrimitives();
        g_display->driver()->eraseDrawable(buffer);

        loops++;
    }

    delete data;

    int elapsed = millis() - tStart;

    loginfo("%s--, drawn %d loops in %d ms (%d ms/loop)\n", __FUNCTION__, loops, elapsed, elapsed / loops);
}

void testGrid(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    g_display->setBackgroundColor(colors::Black);

    int gridWidth = g_display->driver()->width() * 4 / 5;
    int gridHeight = g_display->driver()->height() * 4 / 5;
    geometry::Point gridPosition{(g_display->driver()->width() - gridWidth) / 2,
                                 (g_display->driver()->height() - gridHeight) / 2};

    drawable::Grid grid {
        gridWidth,
        gridHeight,
        drawable::Grid::Division{3, 6},
        drawable::Grid::Division{2, 4},
        colors::White,
        colors::White.darker(1.3),
    };

    g_display->setGrid(grid, gridPosition);
    g_display->drawGrid();
    delay(duration.count());

    loginfo("%s--\n", __FUNCTION__);
}

void testRectangle(const std::chrono::milliseconds& duration)
{
    loginfo("%s++\n", __FUNCTION__);

    g_display->setBackgroundColor(colors::Magenta);

    drawable::Rectangle rectangle{100, 50, 0, colors::None, colors::Blue};
    g_display->driver()->drawDrawable(rectangle, {10, 10});

    delay(duration.count());

    loginfo("%s--\n", __FUNCTION__);
}

void testCanvas(const std::chrono::milliseconds&)
{
    loginfo("%s++\n", __FUNCTION__);

    Canvas canvas(*g_display->driver());

    drawable::Grid grid{g_display->driver()->width() - 1, g_display->driver()->height() - 1, {3, 6}, {3, 6}, colors::Black, colors::Cyan};
    drawable::Rectangle r1{100, 50, 0, colors::None, colors::Blue};
    drawable::Rectangle r2{100, 50, 0, colors::Red, colors::Green};

    canvas.addDrawable(&r1, {10, 10}, 1);
    canvas.addDrawable(&r2, {20, 20}, 2);
    canvas.addDrawable(&grid, {0, 0}, 0);

    canvas.draw();

    loginfo("%s--\n", __FUNCTION__);
}

void setup()
{
    PlatformLogger::inst().echo(true);
    PlatformLogger::inst().auto_flush(false);
    loglevel(log_level_e::info);

    SERIAL_IFACE.begin(115200);
    while (!SERIAL_IFACE) {}
    printf_init(SERIAL_IFACE);

    loginfo("Entering setup, available memory %d\n", freeMemory());

    auto displayDriver = test::OscDisplayDriverCreator::create(DriverType);
    g_display = new OscDisplay(displayDriver);

    analogWriteResolution(12);

    std::chrono::milliseconds duration = std::chrono::seconds{2};

    testBgColor(duration);
    testPoint(duration);
    testLine(duration);
    testGrid(duration);
    testBufferAllSamples(duration);
    testBufferSingleSample(duration);
    testRectangle(duration);
    testCanvas(duration);

    loginfo("All tests run\n");
}

void loop()
{
}
