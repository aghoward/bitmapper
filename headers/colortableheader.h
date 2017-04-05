#pragma once

#include <string>

#include "header.h"

using namespace std;

class ColorTableHeader : public Header {
    public:
        unsigned char Blue;
        unsigned char Green;
        unsigned char Red;
        unsigned char Alpha = 0x00;

        ColorTableHeader() :
            ColorTableHeader(0x00, 0x00, 0x00, 0x00) {};

        ColorTableHeader(unsigned char blue, unsigned char green, unsigned char red, unsigned char alpha = 0x00) :
            Blue(blue), Green(green), Red(red), Alpha(alpha) {};

        unsigned int GetDiskSize();
        string Serialize();
};
