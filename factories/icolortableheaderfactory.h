#pragma once

#include <memory>

#include "headers/colortableheader.h"

using namespace std;

class IColorTableHeaderFactory {
    public:
        virtual ~IColorTableHeaderFactory() {}
        virtual shared_ptr<ColorTableHeader> Create(unsigned char blue = 0x08, unsigned char green = 0x08, unsigned char red = 0x08) = 0;
};
