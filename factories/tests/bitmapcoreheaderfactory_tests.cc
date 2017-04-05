#include "gtest/gtest.h"

#include "bitmapcoreheaderfactory.h"

class BitmapCoreHeaderFactoryTests : public ::testing::Test {
    protected:
        BitmapCoreHeaderFactory _subject;
    public:
        BitmapCoreHeaderFactoryTests() {
            _subject = BitmapCoreHeaderFactory();
        }
};

TEST_F(BitmapCoreHeaderFactoryTests, CreateMakesSquareHeader) {
    auto expectedLen = 4;
    auto pixelData = string(3 * (4 * 4), 0x0);

    auto result = _subject.Create(pixelData, 24);

    ASSERT_EQ(result->Width, expectedLen);
    ASSERT_EQ(result->Height, expectedLen);
}
