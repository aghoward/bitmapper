#include <ctime>
#include <random>
#include <string>

#include "gtest/gtest.h"
#include "bitmapheaderfactory.h"

using namespace std;

class BitmapHeaderFactoryTests : public ::testing::Test {
    protected:
        BitmapHeaderFactory _subject;

    public:
        BitmapHeaderFactoryTests() {
            _subject = BitmapHeaderFactory();
            srand(time(0));
        }
};

TEST_F(BitmapHeaderFactoryTests, Create_SetsIdentityToBM) {
    auto result = _subject.Create(1024, 200);

    ASSERT_EQ(result->Identity, string("BM"));
}

TEST_F(BitmapHeaderFactoryTests, Create_SetsReservedToZero) {
    auto result = _subject.Create(1024, 200);

    ASSERT_EQ(result->Reserved, 0x00);
}

TEST_F(BitmapHeaderFactoryTests, Create_SetsFilesizeToParameter) {
    auto expected = (unsigned int) rand();
    
    auto result = _subject.Create(expected, 200);

    ASSERT_EQ(result->FileSize, expected);
}

TEST_F(BitmapHeaderFactoryTests, Create_SetsPixelOffsetToParameter) {
    auto expected = (unsigned int) rand();
    
    auto result = _subject.Create(1024, expected);

    ASSERT_EQ(result->PixelOffset, expected);
}
