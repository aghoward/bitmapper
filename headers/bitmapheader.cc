#include <string>

#include "bitmapheader.h"
#include "serialization/serializationhelper.h"

using namespace std;

unsigned int BitmapHeader::GetDiskSize() {
    return Identity.size() + sizeof(FileSize) + sizeof(Reserved) + sizeof(PixelOffset);
}

string BitmapHeader::Serialize() {
    return Identity +
        SerializationHelper::binstr(FileSize, false) +
        SerializationHelper::binstr(Reserved, false) +
        SerializationHelper::binstr(PixelOffset, false);
}
