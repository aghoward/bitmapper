#include <memory>

#include "colortableheaderfactory.h"
#include "headers/colortableheader.h"

using namespace std;

shared_ptr<ColorTableHeader> ColorTableHeaderFactory::Create(unsigned char blue, unsigned char green, unsigned char red) {
    return shared_ptr<ColorTableHeader> (new ColorTableHeader(blue, green, red));
}
