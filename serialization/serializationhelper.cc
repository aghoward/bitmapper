#include <algorithm>
#include <string>

#include "serializationhelper.h"

using namespace std;

template <typename T>
string _binstr(T value, bool isBigEndian) {
    auto ret = string();

    for (auto i = 0; i < sizeof(T); i++) {
        ret += (char)((value >> (i * 8)) & 0xFF);
    }

    if (isBigEndian)
        reverse(ret.begin(), ret.end());

    return ret;
}

string SerializationHelper::binstr(unsigned int value, bool isBigEndian) {
    return _binstr(value, isBigEndian);
}


string SerializationHelper::binstr(unsigned short value, bool isBigEndian) {
    return _binstr(value, isBigEndian);
}
