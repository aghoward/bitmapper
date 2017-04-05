#pragma once

#include <string>

using namespace std;

class ISerializeable {
    public:
        virtual string Serialize() = 0;
};
