#include <memory>


#include "files/binaryfile.h"
#include "headers/elfheader.h"
#include "headers/programheader.h"
#include "headers/sectionheader.h"

using namespace std;

BinaryFile::BinaryFile(shared_ptr<ElfHeader> elf, vector<shared_ptr<ProgramHeader>> programHeaders, vector<shared_ptr<SectionHeader>> sectionHeaders) {
    elf_header = elf;
    program_headers = programHeaders;
    section_headers = sectionHeaders;
}
