#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ibitmapheaderfactory.h"
#include "ibitmapcoreheaderfactory.h"
#include "icolortableheaderfactory.h"
#include "files/bitmap.h"
#include "headers/colortableheader.h"
#include "headers/bitmapcoreheader.h"
#include "headers/bitmapheader.h"

using namespace std;

class BitmapFactory {
    private:
        shared_ptr<IBitmapHeaderFactory> _bitmapHeaderFactory;
        shared_ptr<IBitmapCoreHeaderFactory> _bitmapCoreHeaderFactory;
        shared_ptr<IColorTableHeaderFactory> _colorTableHeaderFactory;

        string FillToSquare(string pixels, unsigned short bitsPerPixel);

        vector<shared_ptr<ColorTableHeader>> CreateColorTableHeaders(unsigned short bitsPerPixel);
        shared_ptr<BitmapHeader> CreateBitmapHeader(
            string pixels,
            shared_ptr<BitmapCoreHeader> bitmapCoreHeader,
            vector<shared_ptr<ColorTableHeader>> colorTableHeaders);

    public:
        BitmapFactory(
            shared_ptr<IBitmapHeaderFactory> bitmapHeaderFactory,
            shared_ptr<IBitmapCoreHeaderFactory> bitmapCoreHeaderFactory,
            shared_ptr<IColorTableHeaderFactory> colorTableHeaderFactory):
                _bitmapHeaderFactory(bitmapHeaderFactory),
                _bitmapCoreHeaderFactory(bitmapCoreHeaderFactory),
                _colorTableHeaderFactory(colorTableHeaderFactory) {};

        shared_ptr<Bitmap> Create(string pixels, unsigned short bitsPerPixel);
};
