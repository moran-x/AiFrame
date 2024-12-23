#pragma once
#include "SPI.h"
#include <TFT_eSPI.h>

#include "gen.h"

// SCL->D5
// SDA->D7
// BLK->3V3
// #define TFT_CS 10
// #define TFT_DC D8
// #define TFT_RST D6

// Adafruit_ST7789 tft2(TFT_CS, TFT_DC, TFT_RST);
TFT_eSPI tft = TFT_eSPI();

void tft_render(int x, int y, int w, int h, uint8_t *buf)
{
    //tft.drawBitmap(x, y, (uint8_t *)buf, w, h, TFT_WHITE);
    tft.pushRect(x, y, w, h,(uint16_t*)buf, true);
}

void tft_init()
{
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN);

    gen.onRender(tft_render);
}