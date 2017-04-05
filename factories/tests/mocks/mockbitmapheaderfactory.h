#pragma once

#include <memory>

#include "gmock/gmock.h"

#include "ibitmapheaderfactory.h"
#include "headers/bitmapheader.h"

class MockBitmapHeaderFactory : public IBitmapHeaderFactory {
    public:
        MOCK_METHOD2(Create, shared_ptr<BitmapHeader>(unsigned int, unsigned int));
};
