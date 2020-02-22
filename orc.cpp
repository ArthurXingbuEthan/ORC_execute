#include <iostream>
#include "orc.h"
#include "orcinput.h"

using namespace std;


Orc::Orc() {
    cout << "Entered default constructor" << endl;
    header = "EMPTY";
    type = OBJ;
    hasEntryPoint = FALSE;
    entryPoint = 0;
    symbolTable.numEntries = 0;
    symbolTable.symbols = NULL;
    relocationTable.numEntries = 0;
    relocationTable.relocations = NULL;
    sectionTable.numEntries = 0;
    sectionTable.section = NULL;
    segmentTable.numEntries = 0;
    segmentTable.segment = NULL;
    contents_size = 0;
    contents = NULL;
    cout << "Completed default constructor" << endl;
}
Orc::Orc(const string &filename) {
    cout << "Entered Orc(filename) constructor" << endl;
    OrcInput orcinput;
    Orc in = Orc( orcinput.getOrcFromFilename(filename) );
    header = in.header;
    type = in.type;
    hasEntryPoint = in.hasEntryPoint;
    entryPoint = in.entryPoint;
    cout << "1" << endl;
    symbolTable.numEntries = in.symbolTable.numEntries;
    for (int i = 0; i < symbolTable.numEntries; i++)
    {
        symbolTable.symbols[i].name = in.symbolTable.symbols[i].name;
        symbolTable.symbols[i].type = in.symbolTable.symbols[i].type;
        symbolTable.symbols[i].isDefined = in.symbolTable.symbols[i].isDefined;
        symbolTable.symbols[i].section = in.symbolTable.symbols[i].section;
        symbolTable.symbols[i].offset = in.symbolTable.symbols[i].offset;
    }
    cout << "2" << endl;
    relocationTable.numEntries = in.relocationTable.numEntries;
    for (int i = 0; i < relocationTable.numEntries; i++)
    {
        relocationTable.relocations[i].offset = in.relocationTable.relocations[i].offset;
        relocationTable.relocations[i].section = in.relocationTable.relocations[i].section;
        relocationTable.relocations[i].symbol = in.relocationTable.relocations[i].symbol;
        relocationTable.relocations[i].plus = in.relocationTable.relocations[i].plus;
    }
    cout << "3" << endl;
    sectionTable.numEntries = in.sectionTable.numEntries;
    for (int i = 0; i < sectionTable.numEntries; i++)
    {
        sectionTable.section[i].permissions = in.sectionTable.section[i].permissions;
        sectionTable.section[i].offset = in.sectionTable.section[i].offset;
        sectionTable.section[i].name = in.sectionTable.section[i].name;
        sectionTable.section[i].size = in.sectionTable.section[i].size;
    }
    cout << "4" << endl;
    segmentTable.numEntries = in.segmentTable.numEntries;
    for (int i = 0; i < segmentTable.numEntries; i++) {
        cout << "40" << endl;
        segmentTable.segment[i].name = in.segmentTable.segment[i].name;
        cout << "41" << endl;
        segmentTable.segment[i].offset = in.segmentTable.segment[i].offset;
        cout << "42" << endl;
        segmentTable.segment[i].base = in.segmentTable.segment[i].base;
        cout << "43" << endl;
        segmentTable.segment[i].size = in.segmentTable.segment[i].size;
        cout << "44" << endl;
        segmentTable.segment[i].permissions = in.segmentTable.segment[i].permissions;
        cout << "45" << endl;
        segmentTable.segment[i].type = in.segmentTable.segment[i].type;
        cout << "46" << endl;
    }
    cout << "5" << endl;
    contents_size = in.contents_size;
    contents = new Byte7[contents_size];
    for (size_t i = 0; i < contents_size; i++) {
        contents[i] = in.contents[i];
    }
    cout << "Completed Orc(filename) constructor" << endl;
}
Orc::Orc(const Orc &in) {
    cout << "Entered copy constructor" << endl;
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
    cout << "Completed copy constructor" << endl;
}
Orc::~Orc() {
    cout << "Entered destructor" << endl;
    delete[] symbolTable.symbols;
    delete[] relocationTable.relocations;
    delete[] sectionTable.section;
    delete[] segmentTable.segment;
    delete[] contents;
    cout << "Completed destructor" << endl;
}
