#pragma once 

#include <memory>
#include <string>

#include "gmock/gmock.h"

#include "ibitmapcoreheaderfactory.h"
#include "headers/bitmapcoreheader.h"

class MockBitmapCoreHeaderFactory : public IBitmapCoreHeaderFactory {
    public:
        MOCK_METHOD2(Create, shared_ptr<BitmapCoreHeader>(string, unsigned short));
        MOCK_METHOD1(Create, shared_ptr<BitmapCoreHeader>(string));
};
