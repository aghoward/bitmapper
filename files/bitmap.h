#pragma once

#include <memory>
#include <string>
#include <vector>

#include "headers/bitmapheader.h"
#include "headers/bitmapcoreheader.h"
#include "headers/colortableheader.h"
#include "serialization/iserializeable.h"

using namespace std;

class Bitmap : public ISerializeable {
    public:
        shared_ptr<BitmapHeader> FileHeader;
        shared_ptr<BitmapCoreHeader> DibHeader;
        vector<shared_ptr<ColorTableHeader>> ColorTableHeaders;
        string Pixels;

        Bitmap(
            shared_ptr<BitmapHeader> fileHeader,
            shared_ptr<BitmapCoreHeader> dibHeader,
            vector<shared_ptr<ColorTableHeader>> colorTableHeaders,
            string pixels) :
                FileHeader(fileHeader),
                DibHeader(dibHeader),
                ColorTableHeaders(colorTableHeaders),
                Pixels(pixels) {};
        string Serialize();
};
