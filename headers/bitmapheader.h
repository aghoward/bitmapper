#pragma once

#include <string>

#include "header.h"

using namespace std;

class BitmapHeader : public Header {
    public:
        string Identity = "BM";
        unsigned int FileSize;
        unsigned int Reserved;
        unsigned int PixelOffset;

        BitmapHeader() {};

        BitmapHeader(string identity, unsigned int fileSize, unsigned int reserved, unsigned int pixelOffset) :
            Identity(identity), FileSize(fileSize), Reserved(reserved), PixelOffset(pixelOffset) {};

        unsigned int GetDiskSize();
        string Serialize();
};
