#include <functional>
#include <memory>
#include <string>

#include "fileparser.h"
#include "transposer.h"
#include "utils.h"
#include "factories/ibitmapfactory.h"
#include "files/binaryfile.h"
#include "headers/sectionheader.h"
#include "results/failurereasons.h"
#include "results/result.h"
#include "results/resultfactory.h"

using namespace std;
using namespace utils;

Result<string, FileError> Transposer::Transpose(string elfPath, string bitmapPath, unsigned short bitsPerPixel) {
    auto binaryFileResult = FileParser::Create(elfPath);

    return binaryFileResult.Match<Result<string, FileError>>(
        [this, bitsPerPixel, &bitmapPath] (auto binaryFile) { return this->CreateBitmap(binaryFile, bitmapPath, bitsPerPixel); },
        [] (auto failureReason) { return ResultFactory::CreateFailure<string>(failureReason); });
}

Result<string, FileError> Transposer::CreateBitmap(shared_ptr<BinaryFile> binaryFile, string bitmapPath, unsigned short bitsPerPixel) {
    auto pixels = GetPixels(binaryFile);
    auto bitmap = _bitmapFactory->Create(pixels, bitsPerPixel);
    return WriteToFile(bitmap, bitmapPath);
}

string Transposer::GetPixels(shared_ptr<BinaryFile> binaryFile) {
    function<bool(shared_ptr<SectionHeader>)> filter = [] (auto h) { return h->type == SECT_PROGRAM; };
    auto binaryHeaders = where(binaryFile->section_headers, filter);

    auto pixels = string();
    for (auto header : binaryHeaders)
        pixels += header->contents;

    return pixels;
}

Result<string, FileError> Transposer::WriteToFile(shared_ptr<Bitmap> bitmap, string filename) {
    ofstream fd(filename, ios::binary);
    if (!fd.is_open())
        return ResultFactory::CreateFailure<string>(FileOpenError);

    fd << bitmap->Serialize();
    fd.close();

    return ResultFactory::CreateSuccess<string, FileError>(filename);
}
