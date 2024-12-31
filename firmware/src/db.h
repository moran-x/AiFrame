#pragma once
#include <GyverDBFile.h>
#include <LittleFS.h>
GyverDBFile db(&LittleFS, "settings.db");

enum kk : size_t {
    wifi_ssid,
    wifi_pass,
    kand_token,
    kand_secret,
    gen_query,
    gen_negative,
    gen_style,
    auto_gen,
    auto_prd,
    gen_query2,
    gen_query3,
    gen_query4,
    gen_query5,
};

void db_init() {
    LittleFS.begin();
    db.begin();
    db.init(kk::wifi_ssid, "");
    db.init(kk::wifi_pass, "");
    db.init(kk::kand_token, "");
    db.init(kk::kand_secret, "");

    db.init(kk::gen_query, "");
    db.init(kk::gen_query2, "");
    db.init(kk::gen_query3, "");
    db.init(kk::gen_query4, "");
    db.init(kk::gen_query5, "");
    db.init(kk::gen_negative, "");
    db.init(kk::gen_style, 1);

    db.init(kk::auto_gen, 0);
    db.init(kk::auto_prd, 60);
}