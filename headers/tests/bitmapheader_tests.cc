#include <string>

#include "gtest/gtest.h"
#include "bitmapheader.h"

using namespace std;

class BitmapHeaderTests: public ::testing::Test {
    protected:
        BitmapHeader _subject;

    public:
        BitmapHeaderTests() {
            _subject = BitmapHeader("BM", 2048, 0x01020304, 0x400);
        }
};

TEST_F(BitmapHeaderTests, GetDiskSizeReturns14) {
    auto result = _subject.GetDiskSize();

    ASSERT_EQ(result, 14);
}

TEST_F(BitmapHeaderTests, SerializeStringLengthIs14) {
    auto result = _subject.Serialize();

    ASSERT_EQ(result.size(), 14);
}

TEST_F(BitmapHeaderTests, SerializeStoresIntegersAsLittleEndian) {
    auto expected = string("\x04\x03\x02\x01");

    auto result = _subject.Serialize();

    auto actual = result.substr(6, 4);
    ASSERT_EQ(actual, expected);
}
