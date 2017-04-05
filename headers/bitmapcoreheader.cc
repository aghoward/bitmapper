#include <string>

#include "bitmapcoreheader.h"
#include "serialization/serializationhelper.h"

using namespace std;

unsigned int BitmapCoreHeader::GetDiskSize() {
    return Size;
}

string BitmapCoreHeader::Serialize() {
    return SerializationHelper::binstr(Size, false) +
        SerializationHelper::binstr(Width, false) +
        SerializationHelper::binstr(Height, false) +
        SerializationHelper::binstr(ColorPlanes, false) +
        SerializationHelper::binstr(BitsPerPixel, false);
}
