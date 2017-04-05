#pragma once

#include <memory>

#include "headers/bitmapcoreheader.h"

using namespace std;

class IBitmapCoreHeaderFactory {
    public:
        virtual ~IBitmapCoreHeaderFactory() {}
        virtual shared_ptr<BitmapCoreHeader> Create(string pixels, unsigned short bitsPerPixel = 24) = 0;
};
