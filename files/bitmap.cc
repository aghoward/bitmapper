#include <string>

#include "bitmap.h"

using namespace std;

string Bitmap::Serialize() {
    auto colorTables = string();
    for (auto t : ColorTableHeaders)
        colorTables += t->Serialize();

    return FileHeader->Serialize() +
        DibHeader->Serialize() +
        colorTables +
        Pixels;
}
