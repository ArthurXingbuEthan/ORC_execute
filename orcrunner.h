#ifndef _ORCRUNNER_
#define _ORCRUNNER_

class OrcIsObject{};
class NoFilenameGiven{};

#include "orc.h"

struct Permissions;
struct Symbol;
struct SymbolTable;
struct Section;
struct SectionTable;
struct Segment;
struct SegmentTable;
struct Relocation;
struct RelocationTable;

class OrcRunner {
    public:
        OrcRunner();
        OrcRunner(std::string filename);
    private:
        Orc orc;
        void execute();

};


#endif
