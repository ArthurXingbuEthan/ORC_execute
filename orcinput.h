#ifndef _ORCINPUT_
#define _ORCINPUT_

// Orc Forward Declarations
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

// OrcInput (current file)
class noMoreByte7s{};

#include <fstream>
#include <string>

class OrcInput {
    public:
        OrcInput() { MI = 0; }
        friend class Orc;
    private:
        Orc getOrcFromFilename(const std::string & filename);
        unsigned int MI;
        std::string * F;
        size_t F_size;

        std::string filename;
        std::ifstream ifs;
        std::ofstream ofs;

        std::string reverseString(std::string s);
        char getCharacterFrom7Bits(std::string s);
        int getWord28();
        std::string getText7();
        char getByte7();
        std::string getRawByte7();
        Permissions getPermissions();
        Symbol getSymbol();
        SymbolTable getSymbolTable();
        Relocation getRelocation();
        RelocationTable getRelocationTable();
        Section getSection();
        SectionTable getSectionTable();
        Segment getSegment();
        SegmentTable getSegmentTable();

};


#endif