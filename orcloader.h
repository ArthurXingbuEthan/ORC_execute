#ifndef _ORCLOADER_
#define _ORCLOADER_

// OrcRunner Forward Declaration
class OrcRunner;

// Orc Forward Declarations
#define Byte7 char
struct Permissions;
struct Symbol;
struct SymbolTable;
struct Section;
struct SectionTable;
struct Segment;
struct SegmentTable;
struct Relocation;
struct RelocationTable;
class Orc;


// OrcLoader (current file)
#include <fstream>
#include <string>
#include <vector>

class NoOrcFileGiven{};

class OrcLoader {
    public:
        OrcRunner getOrcRunner(const Orc & orc);
};

#endif