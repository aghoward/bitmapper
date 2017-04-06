#pragma once

#include <memory>
#include <string>

#include "factories/ibitmapfactory.h"
#include "fileparser.h"
#include "files/bitmap.h"
#include "files/binaryfile.h"
#include "results/result.h"
#include "results/failurereasons.h"
#include "results/resultfactory.h"

using namespace std;

class Transposer {
    private:
        shared_ptr<IBitmapFactory> _bitmapFactory;

        Result<string, FileError> CreateBitmap(shared_ptr<BinaryFile> binaryFile, string bitmapPath, unsigned short bitsPerPixel);
        string GetPixels(shared_ptr<BinaryFile> binaryFile);
        Result<string, FileError> WriteToFile(shared_ptr<Bitmap> bitmap, string filename);

    public:
        Transposer(
            shared_ptr<IBitmapFactory> bitmapFactory)
            :
            _bitmapFactory(bitmapFactory)
            {};

        Result<string, FileError> Transpose(string elfPath, string bitmapPath, unsigned short bitsPerPixel);
};
