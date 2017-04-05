#include <cmath>
#include <memory>
#include <string>
#include <vector>

#include <iostream>

#include "bitmapfactory.h"
#include "files/bitmap.h"
#include "headers/bitmapheader.h"
#include "headers/colortableheader.h"

using namespace std;

string BitmapFactory::FillToSquare(string pixels, unsigned short bitsPerPixel) {
    auto pixelCount = (pixels.size() * 8) / bitsPerPixel;
    if ((pixels.size() * 8) % bitsPerPixel != 0)
        pixelCount++;

    auto root = sqrt(pixelCount);
    if (floor(root) == root)
        return pixels;

    auto newTotal = pow((unsigned int)(root + 1), 2);
    auto newByteCount = (newTotal * bitsPerPixel) / 8;
    return pixels + string(newByteCount - pixels.size(), 0x0);
}

shared_ptr<Bitmap> BitmapFactory::Create(string pixels, unsigned short bitsPerPixel) {
    auto filledPixels = FillToSquare(pixels, bitsPerPixel);

    auto colorTableHeaders = CreateColorTableHeaders(bitsPerPixel);
    auto bitmapCoreHeader = _bitmapCoreHeaderFactory->Create(filledPixels, bitsPerPixel);
    auto bitmapHeader = CreateBitmapHeader(filledPixels, bitmapCoreHeader, colorTableHeaders);

    return shared_ptr<Bitmap>(new Bitmap(bitmapHeader, bitmapCoreHeader, colorTableHeaders, filledPixels));
}

vector<shared_ptr<ColorTableHeader>> BitmapFactory::CreateColorTableHeaders(unsigned short bitsPerPixel) {
    auto headers = vector<shared_ptr<ColorTableHeader>>();
    auto header = _colorTableHeaderFactory->Create(bitsPerPixel / 3, bitsPerPixel / 3, (bitsPerPixel / 3) + (bitsPerPixel % 3));
    headers.push_back(header);
    return headers;
}

shared_ptr<BitmapHeader> BitmapFactory::CreateBitmapHeader(
    string pixels,
    shared_ptr<BitmapCoreHeader> bitmapCoreHeader,
    vector<shared_ptr<ColorTableHeader>> colorTableHeaders)
{
    auto bitmapHeaderSize = _bitmapHeaderFactory->Create(0, 0)->GetDiskSize();
    auto pixelOffset = bitmapHeaderSize + bitmapCoreHeader->GetDiskSize();
    for (auto header : colorTableHeaders)
        pixelOffset += header->GetDiskSize();

    auto fileSize = pixelOffset + pixels.size();

    return _bitmapHeaderFactory->Create(fileSize, pixelOffset);
}
