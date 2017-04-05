#pragma once

#include <memory>

#include "headers/bitmapheader.h"

using namespace std;

class IBitmapHeaderFactory {
    public:
        virtual ~IBitmapHeaderFactory() {}
        virtual shared_ptr<BitmapHeader> Create(unsigned int fileSize, unsigned int pixelOffset) = 0;
};
