#pragma once

#include <string>

#include "header.h"

using namespace std;

class BitmapCoreHeader : public Header {
    public:
        unsigned int Size = 12;
        unsigned short Width;
        unsigned short Height;
        unsigned short ColorPlanes = 1;
        unsigned short BitsPerPixel;

        BitmapCoreHeader() :
            BitmapCoreHeader(0, 0, 0) {};

        BitmapCoreHeader(unsigned short width, unsigned short height, unsigned short bitsPerPixel) :
            Width(width), Height(height), BitsPerPixel(bitsPerPixel) {};

        unsigned int GetDiskSize();
        string Serialize();
};
