#include "gtest/gtest.h"
#include "colortableheader.h"

class ColorTableHeaderTests : public ::testing::Test {
    protected:
        ColorTableHeader _subject;
    public:
        ColorTableHeaderTests() {
            _subject = ColorTableHeader(0x41, 0x42, 0x43, 0x00);
        }
};

TEST_F(ColorTableHeaderTests, GetDiskSizeReturns4) {
    auto result = _subject.GetDiskSize();

    ASSERT_EQ(result, 4);
}

TEST_F(ColorTableHeaderTests, SerializeStringLengthEqualsDiskSize) {
    auto result = _subject.Serialize();

    ASSERT_EQ(result.size(), 4);
}
