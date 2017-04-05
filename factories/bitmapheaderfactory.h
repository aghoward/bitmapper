#pragma once

#include <memory>

#include "ibitmapheaderfactory.h"
#include "headers/bitmapheader.h"

using namespace std;

class BitmapHeaderFactory : public IBitmapHeaderFactory {
    public:
        shared_ptr<BitmapHeader> Create(unsigned int fileSize, unsigned int pixelOffset);
};
