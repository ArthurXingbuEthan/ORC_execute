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
#include <unordered_map>

class NoOrcFileGiven{};

class OrcLoader {
    public:
        OrcLoader();
        OrcRunner getOrcRunner(Orc orc);
    private:
        std::unordered_map<size_t,Byte7> MEMORY;
};

#endif