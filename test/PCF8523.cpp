#include <Arduino.h>
#include <ArduinoUnitTests.h>
#include <RTClib_CI.h>

// 2020-11-15T18:30:00
#define DATE_TIME 1605465000

unittest(test) {
  RTC_PCF8523 rtc;
  assertEqual("RTC_PCF8523_CI", rtc.className());
  assertTrue(rtc.begin());
  assertFalse(rtc.initialized());
  DateTime dt1 = DateTime(DATE_TIME);
  rtc.adjust(dt1);
  assertTrue(rtc.initialized());
  DateTime dt2 = rtc.now();
  assertTrue(dt1.unixtime() <= dt2.unixtime());
  assertTrue(dt2.unixtime() <= dt1.unixtime() + 1);

  delay(5000);
  dt2 = rtc.now();
  assertTrue(dt1.unixtime() + 4 <= dt2.unixtime());
  assertTrue(dt2.unixtime() <= dt1.unixtime() + 6);
}

unittest_main()
