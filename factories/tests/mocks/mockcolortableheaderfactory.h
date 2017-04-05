#pragma once

#include <memory>

#include "gmock/gmock.h"

#include "icolortableheaderfactory.h"
#include "headers/colortableheader.h"

class MockColorTableHeaderFactory : public IColorTableHeaderFactory {
    public:
        MOCK_METHOD3(Create, shared_ptr<ColorTableHeader>(unsigned char, unsigned char, unsigned char));
};
