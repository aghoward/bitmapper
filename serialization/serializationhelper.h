#pragma once

#include <string>

using namespace std;

class SerializationHelper {
    public:
        static string binstr(unsigned int value, bool isBigEndian = true);
        static string binstr(unsigned short value, bool isBigEndian = true);
};
