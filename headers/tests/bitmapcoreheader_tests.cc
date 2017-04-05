#include <string>

#include "gtest/gtest.h"

#include "bitmapcoreheader.h"

class BitmapCoreHeaderTests : public ::testing::Test {
    protected:
        BitmapCoreHeader _subject;

    public:
        BitmapCoreHeaderTests() {
            _subject = BitmapCoreHeader(1080, 1024, 24);
        }
};

TEST_F(BitmapCoreHeaderTests, GetDiskSizeReturns12) {
    auto result = _subject.GetDiskSize();

    ASSERT_EQ(result, 12);
}

TEST_F(BitmapCoreHeaderTests, SerializeStringSizeIs12) {
    auto result = _subject.Serialize();

    ASSERT_EQ(result.size(), 12);
}
