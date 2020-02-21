#include "orc.h"

// #include <iostream>

using namespace std;

Orc::Orc() {
    header = "EMPTY";
    type = OBJ;
    hasEntryPoint = FALSE;
    entryPoint = 0;
    symbolTable.numEntries = 0;
    relocationTable.numEntries = 0;
    sectionTable.numEntries = 0;
    segmentTable.numEntries = 0;
    contents_size = 0;
    contents = NULL;
}
Orc::Orc(const string &filename) {
    OrcInput orcinput;
    Orc in = Orc( orcinput.getOrcFromFilename(filename) );
    header = in.header;
    type = in.type;
    hasEntryPoint = in.hasEntryPoint;
    entryPoint = in.entryPoint;
    symbolTable.numEntries = in.symbolTable.numEntries;
    for (int i = 0; i < symbolTable.numEntries; i++)
    {
        symbolTable.symbols[i].name = in.symbolTable.symbols[i].name;
        symbolTable.symbols[i].type = in.symbolTable.symbols[i].type;
        symbolTable.symbols[i].isDefined = in.symbolTable.symbols[i].isDefined;
        symbolTable.symbols[i].section = in.symbolTable.symbols[i].section;
        symbolTable.symbols[i].offset = in.symbolTable.symbols[i].offset;
    }
    relocationTable.numEntries = in.relocationTable.numEntries;
    for (int i = 0; i < relocationTable.numEntries; i++)
    {
        relocationTable.relocations[i].offset = in.relocationTable.relocations[i].offset;
        relocationTable.relocations[i].section = in.relocationTable.relocations[i].section;
        relocationTable.relocations[i].symbol = in.relocationTable.relocations[i].symbol;
        relocationTable.relocations[i].plus = in.relocationTable.relocations[i].plus;
    }
    sectionTable.numEntries = in.sectionTable.numEntries;
    for (int i = 0; i < sectionTable.numEntries; i++)
    {
        sectionTable.section[i].permissions = in.sectionTable.section[i].permissions;
        sectionTable.section[i].offset = in.sectionTable.section[i].offset;
        sectionTable.section[i].name = in.sectionTable.section[i].name;
        sectionTable.section[i].size = in.sectionTable.section[i].size;
    }
    segmentTable.numEntries = in.segmentTable.numEntries;
    for (int i = 0; i < segmentTable.numEntries; i++)
    {
        segmentTable.segment[i].name = in.segmentTable.segment[i].name;
        segmentTable.segment[i].offset = in.segmentTable.segment[i].offset;
        segmentTable.segment[i].base = in.segmentTable.segment[i].base;
        segmentTable.segment[i].size = in.segmentTable.segment[i].size;
        segmentTable.segment[i].permissions = in.segmentTable.segment[i].permissions;
        segmentTable.segment[i].type = in.segmentTable.segment[i].type;
    }
    contents_size = in.contents_size;
    contents = new Byte7[contents_size];
    for (size_t i = 0; i < contents_size; i++) {
        contents[i] = in.contents[i];
    }
}
Orc::Orc(const Orc &in) {
    header = in.header;
    type = in.type;
    hasEntryPoint = in.hasEntryPoint;
    entryPoint = in.entryPoint;
    symbolTable.numEntries = in.symbolTable.numEntries;
    for (int i = 0; i < symbolTable.numEntries; i++)
    {
        symbolTable.symbols[i].name = in.symbolTable.symbols[i].name;
        symbolTable.symbols[i].type = in.symbolTable.symbols[i].type;
        symbolTable.symbols[i].isDefined = in.symbolTable.symbols[i].isDefined;
        symbolTable.symbols[i].section = in.symbolTable.symbols[i].section;
        symbolTable.symbols[i].offset = in.symbolTable.symbols[i].offset;
    }
    relocationTable.numEntries = in.relocationTable.numEntries;
    for (int i = 0; i < relocationTable.numEntries; i++)
    {
        relocationTable.relocations[i].offset = in.relocationTable.relocations[i].offset;
        relocationTable.relocations[i].section = in.relocationTable.relocations[i].section;
        relocationTable.relocations[i].symbol = in.relocationTable.relocations[i].symbol;
        relocationTable.relocations[i].plus = in.relocationTable.relocations[i].plus;
    }
    sectionTable.numEntries = in.sectionTable.numEntries;
    for (int i = 0; i < sectionTable.numEntries; i++)
    {
        sectionTable.section[i].permissions = in.sectionTable.section[i].permissions;
        sectionTable.section[i].offset = in.sectionTable.section[i].offset;
        sectionTable.section[i].name = in.sectionTable.section[i].name;
        sectionTable.section[i].size = in.sectionTable.section[i].size;
    }
    segmentTable.numEntries = in.segmentTable.numEntries;
    for (int i = 0; i < segmentTable.numEntries; i++)
    {
        segmentTable.segment[i].name = in.segmentTable.segment[i].name;
        segmentTable.segment[i].offset = in.segmentTable.segment[i].offset;
        segmentTable.segment[i].base = in.segmentTable.segment[i].base;
        segmentTable.segment[i].size = in.segmentTable.segment[i].size;
        segmentTable.segment[i].permissions = in.segmentTable.segment[i].permissions;
        segmentTable.segment[i].type = in.segmentTable.segment[i].type;
    }
    contents_size = in.contents_size;
    contents = new Byte7[contents_size];
    for (size_t i = 0; i < contents_size; i++)
    {
        contents[i] = in.contents[i];
    }
}
Orc::~Orc() {
    delete[] symbolTable.symbols;
    delete[] relocationTable.relocations;
    delete[] sectionTable.section;
    delete[] segmentTable.segment;
    delete[] contents;
}
