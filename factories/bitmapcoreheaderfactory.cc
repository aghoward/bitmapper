#include <cmath>
#include <memory>
#include <string>

#include "bitmapcoreheaderfactory.h"
#include "headers/bitmapcoreheader.h"

using namespace std;

shared_ptr<BitmapCoreHeader> BitmapCoreHeaderFactory::Create(string pixels, unsigned short bitsPerPixel) {
    auto pixelCount = (pixels.size() * 8) / bitsPerPixel;
    auto sideLen = (unsigned short)sqrt(pixelCount);

    return shared_ptr<BitmapCoreHeader>(new BitmapCoreHeader(sideLen, sideLen, bitsPerPixel));
}
