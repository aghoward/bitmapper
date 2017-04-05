#include <string>

#include "colortableheader.h"

using namespace std;

unsigned int ColorTableHeader::GetDiskSize() {
    return 4;
}

string ColorTableHeader::Serialize() {
    return string(1, Blue) + string(1, Green) + string(1, Red) + string(1, Alpha);
}
