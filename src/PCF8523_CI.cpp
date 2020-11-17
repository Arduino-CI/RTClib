#include <PCF8523_CI.h>

#if defined(MOCK_PINS_COUNT)

bool RTC_PCF8523_CI::isInitialized = false;
uint32_t RTC_PCF8523_CI::offset = 0;

#endif
