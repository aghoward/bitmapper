#pragma once

#include <fstream>
#include <memory>

#include "headers/elfheader.h"
#include "headers/programheader.h"
#include "results/result.h"
#include "results/failurereasons.h"
#include "utils.h"

using namespace std;

class ProgramHeaderFactory {
    private:
        static shared_ptr<ProgramHeader> createSingle(fstream &fd, BITNESS bitness, ENDIANESS endianess);
        static shared_ptr<ProgramHeader> deserialize32(fstream &fd, ENDIANESS endianess);
        static shared_ptr<ProgramHeader> deserialize64(fstream &fd, ENDIANESS endianess);

    public:
        static Result<vector<shared_ptr<ProgramHeader>>, FileError> Create(fstream &fd, shared_ptr<ElfHeader> elf);
};
