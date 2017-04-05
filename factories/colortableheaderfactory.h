#pragma once

#include <memory>

#include "icolortableheaderfactory.h"
#include "headers/colortableheader.h"

using namespace std;

class ColorTableHeaderFactory : public IColorTableHeaderFactory {
    public:
        shared_ptr<ColorTableHeader> Create(unsigned char blue = 0x08, unsigned char green = 0x08, unsigned char red = 0x08);
};
