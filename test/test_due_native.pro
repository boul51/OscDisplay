# Generated by arduino-genmakefile
#
# Command line:
# arduino-genmakefile.py --sketch test.ino --config conf/conf.yaml --config ~/arduino_configs/board/due_native.yaml --config ~/arduino_configs/arduino/due.yaml --makefile Makefile.due_native --qmake test_due_native.pro

TEMPLATE=app
CONFIG+=console
CONFIG-=app_bundle
CONFIG-=qt

HOME=$$(HOME)

exists(test_due_native.pri) {
    include(test_due_native.pri)
}

TARGET = test_due_native

MAKEFILE = Makefile.due_native

DEFINES += \
	USB_MANUFACTURER=\\\"Arduino LLC\\\" \
	USB_PRODUCT=\\\"Arduino Due\\\" \
	F_CPU=84000000L \
	ARDUINO=10607 \
	ARDUINO_SAM_DUE \
	ARDUINO_ARCH_SAM \
	HAS_LOGGER \
	NO_PRAGMA_MARK \
	SERIAL_IFACE=SerialUSB \
	__SAM3X8E__ \
	USB_VID=0x2341 \
	USB_PID=0x003e \
	USBCON \
	printf=iprintf \

OTHER_FILES += \
	Makefile.due_native \
	conf/conf.yaml \
	../conf/conf.yaml \
	../../MemoryFree/conf/conf.yaml \
	../../Sample/conf/conf.yaml \
	../../TFT/conf/conf.yaml \
	../../arduino-printf/conf/conf.yaml \
	../../arduino-logger/conf/conf.yaml \

HEADERS += \
	oscdisplaydrivercreator.h \
	platform_logger.h \
	../oscdisplay.h \
	../oscdisplaycolor.h \
	../drawableprimitive/colorstrike.h \
	../drawableprimitive/primitive.h \
	../drawableprimitive/line.h \
	../drawableprimitive/point.h \
	../drawableprimitive/rectangle.h \
	../drawableprimitive/colorfill.h \
	../oscdisplaydriver.h \
	../robotlcdoscdisplaydriver.h \
	../geometry/coordinate.h \
	../geometry/line.h \
	../geometry/point.h \
	../drawable/grid.h \
	../drawable/buffer.h \
	../drawable/drawable.h \
	../drawable/rectangle.h \
	../optional.h \
	../canvas/canvas.h \
	../../MemoryFree/pgmStrToRAM.h \
	../../MemoryFree/MemoryFree.h \
	../../Sample/sample.h \
	../../TFT/src/utility/Adafruit_ST7735.h \
	../../TFT/src/utility/PImage.h \
	../../TFT/src/utility/Adafruit_GFX.h \
	../../TFT/src/TFT.h \
	../../arduino-printf/src/LibPrintf.h \
	../../arduino-printf/extras/printf/printf.h \
	../../arduino-printf/extras/test/LibPrintf.h \
	../../arduino-logger/src/TeensySDLogger.h \
	../../arduino-logger/src/ArduinoLogger.h \
	../../arduino-logger/src/TeensyRobustModuleLogger.h \
	../../arduino-logger/src/internal/circular_buffer.hpp \
	../../arduino-logger/src/SDFileLogger.h \
	../../arduino-logger/src/AVRSDRotationalLogger.h \
	../../arduino-logger/src/TeensySDRotationalModuleLogger.h \
	../../arduino-logger/src/TeensySDRotationalLogger.h \
	../../arduino-logger/src/CircularBufferLogger.h \
	../../arduino-logger/src/AVRCircularBufferLogger.h \
	../../arduino-logger/examples/AVRCircularLogBuffer/platform_logger.h \
	../../arduino-logger/examples/CircularLogBuffer_GlobalInst/platform_logger.h \
	../../arduino-logger/examples/CircularLogBuffer_CompileTimeFiltering/platform_logger.h \
	../../arduino-logger/examples/CircularLogBuffer/platform_logger.h \
	../../arduino-logger/test/catch/catch.hpp \
	../../arduino-logger/test/test_helper.hpp \
	../../arduino-logger/test/sketch/Adafruit_SleepyDog.h \
	../../arduino-logger/test/sketch/SdFat.h \

SOURCES += \
	test.ino \
	oscdisplaydrivercreator.cpp \
	../robotlcdoscdisplaydriver.cpp \
	../oscdisplaydriver.cpp \
	../oscdisplay.cpp \
	../../MemoryFree/MemoryFree.cpp \
	../../MemoryFree/pgmStrToRAM.cpp \
	../../TFT/src/utility/Adafruit_GFX.cpp \
	../../TFT/src/utility/Adafruit_ST7735.cpp \
	../../TFT/src/utility/glcdfont.c \
	../../TFT/src/TFT.cpp \
	../../arduino-printf/src/LibPrintf.cpp \
	../../arduino-printf/extras/printf/printf.c \
	../../arduino-printf/extras/sketch_cpp/override_putchar.cpp \
	../../arduino-printf/extras/sketch_cpp/specify_print_class.cpp \
	../../arduino-printf/extras/sketch_cpp/default_to_serial.cpp \
	../../arduino-logger/src/ArduinoLogger.cpp \
	../../arduino-logger/test/test_helper.cpp \
	../../arduino-logger/test/CoreLoggerTests.cpp \
	../../arduino-logger/test/CircularBufferLoggerTests.cpp \
	../../arduino-logger/test/AVRCircularBufferLoggerTests.cpp \
	../../arduino-logger/test/catch_main.cpp \
	../../arduino-logger/test/sketch/CircularLogBuffer_LocalInst.cpp \
	../../arduino-logger/test/sketch/CircularLogBuffer.cpp \
	../../arduino-logger/test/sketch/CircularLogBuffer_CompileTimeFiltering.cpp \
	../../arduino-logger/test/sketch/SDFileLogger_Teensy.cpp \
	../../arduino-logger/test/sketch/CircularLogBuffer_GlobalInst.cpp \
	../../arduino-logger/test/sketch/TeensySDLogger.cpp \
	../../arduino-logger/test/sketch/TeensySDRotationalLogger.cpp \
	../../arduino-logger/test/sketch/AVRSDRotationalLogger.cpp \
	../../arduino-logger/test/sketch/AVRCircularLogBuffer.cpp \
	../../arduino-logger/test/sketch/Adafruit_SleepyDog.cpp \

INCLUDEPATH += \
	. \
	.. \
	../drawableprimitive \
	../geometry \
	../drawable \
	../canvas \
	../../MemoryFree \
	../../Sample \
	../../TFT/src/utility \
	../../TFT/src \
	../../arduino-printf/src \
	../../arduino-printf/extras/printf \
	../../arduino-printf/extras/test \
	../../arduino-logger/src \
	../../arduino-logger/src/internal \
	../../arduino-logger/examples/AVRCircularLogBuffer \
	../../arduino-logger/examples/CircularLogBuffer_GlobalInst \
	../../arduino-logger/examples/CircularLogBuffer_CompileTimeFiltering \
	../../arduino-logger/examples/CircularLogBuffer \
	../../arduino-logger/test/catch \
	../../arduino-logger/test \
	../../arduino-logger/test/sketch \