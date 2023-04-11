#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA {

    RGBA(uint8_t R,uint8_t G,uint8_t B,uint8_t A) 
    : r { R }
    , g { G }
    , b { B }
    , a { A } {}
     uint8_t r;
     uint8_t g;
     uint8_t b;
     uint8_t a;
};
struct RGB{
    RGB(uint8_t R,uint8_t G,uint8_t B) 
    : r { R }
    , g { G }
    , b { B } {}
     uint8_t r;
     uint8_t g;
     uint8_t b;

};
struct Luma{
    Luma(uint8_t luma):
    gray { luma } {}
    uint8_t gray;
};
