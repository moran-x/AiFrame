#include <Arduino.h>
#include "tft.h"
#include "gen.h"


/* time library */
#include <time.h>
static time_t now;     

/* HTTP */
const char *headerkeys[] = {"Location"};

/* variables */
static int w, h, timeX, timeY, len, offset;
static uint8_t textSize;
static unsigned long next_show_millis = 0;

#define NTP_SERVER "pool.ntp.org"
#define TZ "HKT-7" //изменить на свою тайм зону

void ntpGetTime()
{
  // Initialize NTP settings
#if defined(ESP32)
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
#elif defined(ESP8266)
  configTime(TZ, NTP_SERVER);
#endif

 Serial.print(F("Waiting for NTP time sync: "));
  tft.setTextColor(TFT_GREEN);
  tft.print(F("Waiting for NTP time sync: "));
  time_t nowSecs = time(nullptr);
  while (nowSecs < 8 * 3600 * 2)
  {
    delay(500);
    Serial.print('.');
    tft.print('.');
    yield();
    nowSecs = time(nullptr);
  }
  Serial.println(asctime(localtime(&nowSecs)));
  tft.println(asctime(localtime(&nowSecs)));
}

void printTime()
{
  now = time(nullptr);
  const tm *tm = localtime(&now);
  int hour = tm->tm_hour;
  int min = tm->tm_min;

  //set text size with pixel margin
  //tft.setTextSize(TextSize, TextSize, 2);
  if (tft_render)
  {
    // print time with black background
    //tft.pushRect(0, 0, w, h,(uint16_t*)screenContent, true);
    tft.setCursor(timeX, timeY);
    tft.setTextColor(TFT_GREEN);
    tft.printf("%02d:%02d", hour, min);
  }
  else
  {
    // print time with border
    tft.setCursor(timeX - 1, timeY - 1);
    tft.setTextColor(TFT_DARKGREY);
    tft.printf("%02d:%02d", hour, min);
    tft.setCursor(timeX + 2, timeY + 2);
    tft.setTextColor(TFT_BLACK);
    tft.printf("%02d:%02d", hour, min);
    tft.setCursor(timeX, timeY);
    tft.setTextColor(TFT_WHITE);
    tft.printf("%02d:%02d", hour, min);
  }
} 