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

#if defined(TIME)
    static int timeX1, timeY1;
    static uint8_t textSize1;
    //#include "screen_time.h"
    uint16_t* screenContent;
#endif

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

    #if defined(TIME)
        // ========SAVE SCREEN

        textSize1 = tft.width() / 7 / 6; //размер высота
        timeX1 = (tft.width() - (textSize1 * 5 * 6)) / 3;
        timeY1 = tft.height() - (textSize1 * 8) - 10;

        //screenContent = NULL;
        //screenContent = (uint16_t*) malloc ((h * w)*2);
        //screenContent = (uint16_t*) malloc( textSize1*6*5 * textSize1*8 * 2 );
        //tft.readRect(timeX1-1, timeY1-1, textSize1*6*5, textSize1*8, screenContent);  
        //tft.fillRect(timeX-1, timeY-1, textSize*6*5, textSize*8,TFT_BLACK);
    #endif
}