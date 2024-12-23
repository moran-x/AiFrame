#pragma once
#include "Kandinsky/Kandinsky.h"

#include "config.h"
Kandinsky gen;
bool gen_flag = 0;
long randNumber;
String query;

void generate() {
    gen_flag = 1;
}

void gen_tick() {
    gen.tick();

    if (gen_flag) {
        gen_flag = 0;


        randNumber = random(1, 6);
        //Serial.println(randNumber);
        
        query = String(db[kk::gen_query]);

        switch (randNumber)
        {
        case 1:
            query = String(db[kk::gen_query]);
            break;
        case 2:
            if (!String(db[kk::gen_query2]).length()) break;
            query = String(db[kk::gen_query2]);
            break;
        case 3:
            if (!String(db[kk::gen_query3]).length()) break;
            query = String(db[kk::gen_query3]);
            break;
        case 4:
            if (!String(db[kk::gen_query4]).length()) break;
            query = String(db[kk::gen_query4]);
            break;
        case 5:
            if (!String(db[kk::gen_query5]).length()) break;
            query = String(db[kk::gen_query5]);
            break;
        default:
            query = String(db[kk::gen_query]);
            break;
        }

        //Serial.println(query);

        gen.setScale(DISP_SCALE);
        gen.generate(
            query,
            DISP_WIDTH * DISP_SCALE,
            DISP_HEIGHT * DISP_SCALE,
            Text(gen.styles).getSub(db[kk::gen_style], ';'),
            db[kk::gen_negative]);
    }
}