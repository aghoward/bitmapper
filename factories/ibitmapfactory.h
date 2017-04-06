#pragma once

#include <memory>
#include <string>

#include "files/bitmap.h"

using namespace std;

class IBitmapFactory {
    public:
        virtual shared_ptr<Bitmap> Create(string pixels, unsigned short bitsPerPixel) = 0;
};
