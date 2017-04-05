#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "bitmapfactory.h"
#include "mocks/mockbitmapheaderfactory.h"
#include "mocks/mockbitmapcoreheaderfactory.h"
#include "mocks/mockcolortableheaderfactory.h"
#include "headers/colortableheader.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Exactly;
using ::testing::NiceMock;

#include <iostream>

using namespace std;

class BitmapFactoryTests : public ::testing::Test {
    protected:
        BitmapFactory _subject;
        NiceMock<MockBitmapHeaderFactory> _mockBitmapHeaderFactory;
        NiceMock<MockBitmapCoreHeaderFactory> _mockBitmapCoreHeaderFactory;
        NiceMock<MockColorTableHeaderFactory> _mockColorTableHeaderFactory;

        shared_ptr<BitmapHeader> _bitmapHeader;
        shared_ptr<BitmapCoreHeader> _bitmapCoreHeader;
        shared_ptr<ColorTableHeader> _colorTable;

    public:
        BitmapFactoryTests() :
        _subject(BitmapFactory(
                shared_ptr<IBitmapHeaderFactory>(&_mockBitmapHeaderFactory, [] (auto x) {}),
                shared_ptr<IBitmapCoreHeaderFactory>(&_mockBitmapCoreHeaderFactory, [] (auto x) {}),
                shared_ptr<IColorTableHeaderFactory>(&_mockColorTableHeaderFactory, [] (auto x) {})))
        {
            _bitmapHeader = shared_ptr<BitmapHeader>(new BitmapHeader());
            _bitmapCoreHeader = shared_ptr<BitmapCoreHeader>(new BitmapCoreHeader());
            _colorTable = shared_ptr<ColorTableHeader>(new ColorTableHeader());

            ON_CALL(_mockBitmapHeaderFactory, Create(_, _))
                .WillByDefault(Return(_bitmapHeader));
            ON_CALL(_mockBitmapCoreHeaderFactory, Create(_, _))
                .WillByDefault(Return(_bitmapCoreHeader));
            ON_CALL(_mockColorTableHeaderFactory, Create(_, _, _))
                .WillByDefault(Return(_colorTable));
        }
};

TEST_F(BitmapFactoryTests, Create_CallsColorTableHeaderFactoryWithEvenColors) {
    auto bitsPerPixel = 24;
    auto expectedValue = bitsPerPixel / 3;
    auto pixels = string(expectedValue * 16, 0x0);

    EXPECT_CALL(_mockColorTableHeaderFactory, Create(expectedValue, expectedValue, expectedValue))
        .Times(Exactly(1));

    auto result = _subject.Create(pixels, bitsPerPixel);
}

TEST_F(BitmapFactoryTests, Create_CallsColorTableHeaderFactoryWithUnevenColors) {
    auto bitsPerPixel = 8;
    auto expectedValue = bitsPerPixel / 3;
    auto pixels = string(expectedValue * 16, 0x0);

    EXPECT_CALL(_mockColorTableHeaderFactory, Create(expectedValue, expectedValue, expectedValue + 2))
        .Times(Exactly(1));

    auto result = _subject.Create(pixels, bitsPerPixel);
}


TEST_F(BitmapFactoryTests, Create_CallsBitmapCoreHeaderFactoryWithFilledPixelArray) {
    auto bitsPerPixel = 8;
    auto pixels = string(bitsPerPixel * 12, 0x1);
    auto expected = pixels + string(4, 0x0);

    EXPECT_CALL(_mockBitmapCoreHeaderFactory, Create(expected, bitsPerPixel))
        .Times(Exactly(1));

    auto result = _subject.Create(pixels, bitsPerPixel);
}
