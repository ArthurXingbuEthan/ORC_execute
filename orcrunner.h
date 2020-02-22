#ifndef _ORCRUNNER_
#define _ORCRUNNER_

#include "orcloader.h"

// OrcRunner (current file)
#include <fstream>

class OrcIsObject{};

#define Opcode unsigned char
enum type1_opcode : unsigned char { ADD, SUB, MUL, DIV, CMP, TST, AND, ORR, XOR, STR, STB, LOD };
enum type2_opcode : unsigned char { JMP, JLT, JEQ, CAL, PSH, POP, NOT, OUT, INP, AMP, ALT, AEQ, AAL };
enum type3_opcode : unsigned char { RET, NOP };

struct Register {
    unsigned char type;
    Opcode opcode; // can be initialized to "type1_opcode," "type2_opcode," "type3_opcode"
            // type 1
    unsigned char dst;  // destination
    unsigned char src;  // source
            // type 2
    unsigned short val; // value
};
struct Constant {
    unsigned char type;
    Opcode opcode;
            // type 1
    unsigned char dst;  // destination
    unsigned short src; // source
            // type 2
    unsigned short val;  // value
};

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

class OrcRunner {
    public:
        OrcRunner();
        OrcRunner(Orc orc);
        friend class OrcLoader;
    private:

        unsigned int MI;

        std::ifstream ifs;
        std::ofstream ofs;

        void execute();

};


#endif
