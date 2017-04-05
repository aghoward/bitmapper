#pragma once
#include <string>

#include "serialization/iserializeable.h"

using namespace std;

class Header: public ISerializeable {
    public:
        virtual unsigned int GetDiskSize() = 0;
};
