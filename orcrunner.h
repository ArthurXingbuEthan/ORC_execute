#ifndef _ORCRUNNER_
#define _ORCRUNNER_

class OrcIsObject{};
class NoFilenameGiven{};

enum type1_opcode : char { ADD, SUB, MUL, DIV, CMP, TST, AND, ORR, XOR, STR, STB, LOD };
enum type2_opcode : char { JMP, JLT, JEQ, CAL, PSH, POP, NOT, OUT, INP, AMP, ALT, AEQ, AAL };
enum type3_opcode : char { RET, NOP }


// struct register {
//     opcode;
    
    
// }

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

        unsigned int MI;
        std::vector<std::string> F;

        std::ifstream ifs;
        std::ofstream ofs;

        void execute();





};


#endif
