#include <Arduino.h>
#include <ArduinoUnitTests.h>
#include <RTClib.h>

// 2020-11-15T18:30:00
#define DATE_TIME 1605465000

unittest(constructors) {
  bool flag;
  DateTime dt1(DATE_TIME);
  DateTime dt2(2020, 11, 15, 18, 30, 0);
  DateTime dt3(__DATE__, __TIME__);
  DateTime dt4(F(__DATE__), F(__TIME__));
  DateTime dt5("2020-11-15T18:30:00");

  flag = dt1 == dt2;
  assertTrue(flag);
  flag = dt1 == dt5;
  assertTrue(flag);
  flag = dt3 == dt4;
  assertTrue(flag);
}

unittest(isValid) {
  DateTime dt1(DATE_TIME);
  assertTrue(dt1.isValid());
  DateTime dt2(2020, 02, 30, 18, 30, 0);
  assertFalse(dt2.isValid());
}

unittest(toString) {
  DateTime dt(DATE_TIME);
  char buffer1[] = "DDD, DD MMM YYYY hh:mm:ss";
  char* buffer2;
  buffer2 = dt.toString(buffer1);
  assertEqual(buffer1, buffer2);
  String s1 = String(buffer2);
  String s2 = String("Sun, 15 Nov 2020 18:30:00");
  assertEqual(s1, s2);
}

unittest(year) {
  DateTime dt(DATE_TIME);
  assertEqual(2020, dt.year());
}

unittest(month) {
  DateTime dt(DATE_TIME);
  assertEqual(11, dt.month());
}

unittest(day) {
  DateTime dt(DATE_TIME);
  assertEqual(15, dt.day());
}

unittest(hour) {
  DateTime dt(DATE_TIME);
  assertEqual(18, dt.hour());
}

unittest(twelveHour) {
  DateTime dt(DATE_TIME);
  assertEqual(6, dt.twelveHour());
}

unittest(isPM) {
  DateTime dt(DATE_TIME);
  assertEqual(true, dt.isPM());
}

unittest(minute) {
  DateTime dt(DATE_TIME);
  assertEqual(30, dt.minute());
}

unittest(second) {
  DateTime dt(DATE_TIME);
  assertEqual(0, dt.second());
}

unittest(dayOfTheWeek) {
  DateTime dt(DATE_TIME);
  assertEqual(0, dt.dayOfTheWeek());
}

unittest(secondstime) {
  DateTime dt(DATE_TIME);
  assertEqual(DATE_TIME - SECONDS_FROM_1970_TO_2000, dt.secondstime());
}

unittest(unixtime) {
  DateTime dt(DATE_TIME);
  assertEqual(DATE_TIME, dt.unixtime());
}

unittest(timestamp) {
  DateTime dt(DATE_TIME);
  String s1 = dt.timestamp();
  String s2 = String("2020-11-15T18:30:00");
  assertEqual(s1, s2);
  s1 = dt.timestamp(DateTime::TIMESTAMP_DATE);
  s2 = String("2020-11-15");
  assertEqual(s1, s2);
  s1 = dt.timestamp(DateTime::TIMESTAMP_TIME);
  s2 = String("18:30:00");
  assertEqual(s1, s2);
}

// DateTime DateTime::operator+	(	const TimeSpan & 	span	)	

// DateTime DateTime::operator-	(	const TimeSpan & 	span	)	

// TimeSpan DateTime::operator-	(	const DateTime & 	right	)	

// bool DateTime::operator<	(	const DateTime & 	right	)	const

// bool DateTime::operator>	(	const DateTime & 	right	)	const

// bool DateTime::operator<=	(	const DateTime & 	right	)	const

// bool DateTime::operator>=	(	const DateTime & 	right	)	const

// bool DateTime::operator==	(	const DateTime & 	right	)	const

// bool DateTime::operator!=	(	const DateTime & 	right	)	const

unittest_main()
