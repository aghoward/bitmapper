#include "gtest/gtest.h"
#include "colortableheaderfactory.h"

class ColorTableHeaderFactoryTests : public ::testing::Test {
    protected:
        ColorTableHeaderFactory _subject;

    public:
        ColorTableHeaderFactoryTests() {
            _subject = ColorTableHeaderFactory();
        }
};

TEST_F(ColorTableHeaderFactoryTests, CreatePassesRGBValuesToHeader) {
    unsigned char blue = 0x45;
    unsigned char green = 0x89;
    unsigned char red = 0xff;

    auto result = _subject.Create(blue, green, red);

    ASSERT_EQ(result->Blue, blue);
    ASSERT_EQ(result->Green, green);
    ASSERT_EQ(result->Red, red);
}
