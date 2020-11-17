#pragma once

#if defined(MOCK_PINS_COUNT)

#include <RTClib.h>
#include <ctime>

class RTC_PCF8523_CI : public RTC_PCF8523_Base {
private:
  static bool isInitialized;
  static uint32_t offset;

public:
  boolean begin() { return true; }
  void adjust(const DateTime &dt) {
    isInitialized = true;
    offset = dt.unixtime() - std::time(0);
  }
  boolean initialized() { return isInitialized; }
  static DateTime now() { return DateTime(std::time(0) + offset); }
  virtual String className() const { return "RTC_PCF8523_CI"; }
};

#endif
