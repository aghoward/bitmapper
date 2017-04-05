#pragma once

#include <memory>

#include "ibitmapcoreheaderfactory.h"
#include "headers/bitmapcoreheader.h"

using namespace std;

class BitmapCoreHeaderFactory : public IBitmapCoreHeaderFactory {
    public:
        shared_ptr<BitmapCoreHeader> Create(string pixels, unsigned short bitsPerPixel = 24);
};
