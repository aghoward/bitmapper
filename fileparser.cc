#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "fileparser.h"
#include "files/binaryfile.h"
#include "factories/elfheaderfactory.h"
#include "factories/programheaderfactory.h"
#include "factories/sectionheaderfactory.h"
#include "results/result.h"
#include "results/resultfactory.h"

using namespace std;

Result<shared_ptr<BinaryFile>, FileError> FileParser::Create(string filename) {
    fstream fd(filename, ios::in | ios::binary);
    if (!fd.is_open())
        return ResultFactory::CreateFailure<shared_ptr<BinaryFile>>(FileDoesNotExist);

    auto data = shared_ptr<BinaryFile>(new BinaryFile());
    auto result = FileParser::createElfHeader(fd, data);

    fd.close();
    return result;
}

Result<shared_ptr<BinaryFile>, FileError> FileParser::createElfHeader(fstream &fd, shared_ptr<BinaryFile> returnData) {
    auto elfHeaderResult = ElfHeaderFactory::Create(fd);
    return elfHeaderResult.Match<Result<shared_ptr<BinaryFile>, FileError>>(
        [&fd, &returnData] (auto header) {
            returnData->elf_header = header;
            return FileParser::createProgramHeaders(fd, returnData);
        },
        [] (auto failure) { return ResultFactory::CreateFailure<shared_ptr<BinaryFile>>(failure); }
    );
}

Result<shared_ptr<BinaryFile>, FileError> FileParser::createProgramHeaders(fstream &fd, shared_ptr<BinaryFile> returnData) {
    auto parseResult = ProgramHeaderFactory::Create(fd, returnData->elf_header);

    return parseResult.Match<Result<shared_ptr<BinaryFile>, FileError>>(
        [&fd, &returnData] (auto headers) {
            returnData->program_headers = headers; 
            return FileParser::createSectionHeaders(fd, returnData); 
        },
        [] (auto failure) { return ResultFactory::CreateFailure<shared_ptr<BinaryFile>>(failure); }
    );
}

Result<shared_ptr<BinaryFile>, FileError> FileParser::createSectionHeaders(fstream &fd, shared_ptr<BinaryFile> returnData) {
    auto parseResult = SectionHeaderFactory::Create(fd, returnData->elf_header);

    return parseResult.Match<Result<shared_ptr<BinaryFile>, FileError>>(
        [&returnData] (auto headers) { 
            returnData->section_headers = headers;
            return ResultFactory::CreateSuccess<shared_ptr<BinaryFile>, FileError>(returnData); 
        },
        [] (auto failure) { return ResultFactory::CreateFailure<shared_ptr<BinaryFile>>(failure); }
    );
}
