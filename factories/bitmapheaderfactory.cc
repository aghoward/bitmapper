#include <memory>

#include "bitmapheaderfactory.h"
#include "headers/bitmapheader.h"

using namespace std;

shared_ptr<BitmapHeader> BitmapHeaderFactory::Create(unsigned int fileSize, unsigned int pixelOffset) {
    return shared_ptr<BitmapHeader>(new BitmapHeader(string("BM"), fileSize, 0x0, pixelOffset));
}
