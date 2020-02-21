#ifndef _ORCINPUT_
#define _ORCINPUT_

#include <fstream>
#include <string>
#include <vector>

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

class OrcInput {
    public:
        OrcInput();

        // function that neds to access Orc methods
        Orc getOrcFromFilename(std::string filename);

    private:
        unsigned int MI = 0;
        std::vector<std::string> F;

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