#include <string>

#include "serializationhelper.h"
#include "gtest/gtest.h"

class SerializationHelperTest : public ::testing::Test {
    public:
        SerializationHelperTest() {
        }

};

TEST_F(SerializationHelperTest, binstrHandlesNullCorrectly) {
    auto expected = string(4, (char)0);
    auto value = (unsigned int)0;

    auto result = SerializationHelper::binstr(value);

    ASSERT_EQ(result, expected);
}

TEST_F(SerializationHelperTest, binstrReturnsBinaryStringBigEndian) {
    auto expected = string("\x01\x02\x03\x04");
    auto value = (unsigned int)0x01020304;

    auto result = SerializationHelper::binstr(value);

    ASSERT_EQ(result, expected);
}

TEST_F(SerializationHelperTest, binstrReturnsBinaryStringLittleEndian) {
    auto expected = string("\x01\x02\x03\x04");
    auto value = (unsigned int)0x04030201;

    auto result = SerializationHelper::binstr(value, false);

    ASSERT_EQ(result, expected);
}

TEST_F(SerializationHelperTest, binstrDoesNotOmitLeadingZeros) {
    auto expected = string(3, (char)0) + string("\x01");
    auto value = (unsigned int)1;

    auto result = SerializationHelper::binstr(value);

    ASSERT_EQ(result, expected);
}
