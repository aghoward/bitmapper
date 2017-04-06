#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>

#include "transposer.h"
#include "factories/bitmapfactory.h"
#include "factories/bitmapheaderfactory.h"
#include "factories/bitmapcoreheaderfactory.h"
#include "factories/colortableheaderfactory.h"

using namespace std;

void perror(string msg);

int main(int argc, char * argv[]) {
    if (argc != 4)
        perror(string("Usage: ") + argv[0] + " <elfpath> <bitmappath> <bitsperpixel>");

    auto bitmapHeaderFactory = make_shared<BitmapHeaderFactory>();
    auto bitmapCoreHeaderFactory = make_shared<BitmapCoreHeaderFactory>();
    auto colorTableHeaderFactory = make_shared<ColorTableHeaderFactory>();
    auto bitmapFactory = make_shared<BitmapFactory>(bitmapHeaderFactory, bitmapCoreHeaderFactory, colorTableHeaderFactory);

    auto transposer = Transposer(bitmapFactory);

    auto bitsPerPixel = (unsigned short)stoul(argv[3], nullptr, 0);
    auto result = transposer.Transpose(argv[1], argv[2], bitsPerPixel);

    result.Match<void>(
        [] (auto filename) { cout << "File written to: " << filename << endl; },
        [] (auto failureReason) { perror(to_string(failureReason)); });

    return 0;
}

void perror(string msg) {
    cout << "[ERROR]: " << msg << endl;
    exit(-1);
}
