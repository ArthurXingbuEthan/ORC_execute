#ifndef _ORC_
#define _ORC_

#include "orcinput.h"

#define Byte7 char
#define Word28 int
#define Text7 std::string

class noMoreByte7s{};

enum Bool : Byte7 { FALSE, TRUE };
enum FileType : Byte7 { EXE, OBJ };
enum SymbolType : Byte7 { EXTERN, FUNC };
enum SegmentType : Byte7 { PROGBITS, NOTE };

struct Permissions {
    Word28 word28;
    Bool executable() { return (Bool)((word28>>4)&1); }
    Bool writeable() { return (Bool)((word28>>5)&1); }
    Bool readable() { return (Bool)((word28>>6)&1); }
};
struct Symbol {
    Text7 name;
    SymbolType type;
    Bool isDefined;
    Word28 section;
    Word28 offset;
};
struct SymbolTable {
    Word28 numEntries;
    Symbol * symbols;
};
struct Section {
    Permissions permissions;
    Word28 offset;
    Text7 name;
    Word28 size;
};
struct SectionTable {
    Word28 numEntries;
    Section * section;
};
struct Segment {
    Text7 name;
    Word28 offset;
    Word28 base;
    Word28 size;
    Permissions permissions;
    SegmentType type;
};
struct SegmentTable {
    Word28 numEntries;
    Segment * segment;
};
struct Relocation {
    Word28 offset;
    Word28 section;
    Text7 symbol;
    Word28 plus;
};
struct RelocationTable {
    Word28 numEntries;
    Relocation * relocations;
};

class Orc {
    public:
        Orc();
        Orc(const std::string &filename);
        Orc(const Orc &in);
        ~Orc();
        friend Orc OrcInput::getOrcFromFilename(std::string filename);
    private:
        Text7 header;
        FileType type;
        Bool hasEntryPoint;
        Word28 entryPoint;
        SymbolTable symbolTable;
        RelocationTable relocationTable;
        SectionTable sectionTable;
        SegmentTable segmentTable;
        size_t contents_size;
        Byte7 * contents;
};


#endif