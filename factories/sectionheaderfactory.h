#pragma once 

#include <fstream>
#include <memory>

#include "headers/elfheader.h"
#include "headers/sectionheader.h"
#include "results/result.h"
#include "results/failurereasons.h"
#include "utils.h"

using namespace std;

class SectionHeaderFactory {
    private:
        static bool isFileOk(fstream &fd);
        static shared_ptr<SectionHeader> createSingle(fstream &fd, BITNESS bitness, ENDIANESS endianess);
        static shared_ptr<SectionHeader> deserialize(fstream &fd, int wordSize, ENDIANESS endianess);
        static string getContents(fstream &fd, shared_ptr<SectionHeader> header);

    public:
        static Result<vector<shared_ptr<SectionHeader>>, FileError> Create(fstream &fd, shared_ptr<ElfHeader> elf);
};
