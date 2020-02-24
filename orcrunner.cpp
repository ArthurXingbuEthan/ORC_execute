#include "orc.h"
// JANK FIX: Please find better way unless this is best
#include "orcloader.cpp"

#include <iostream>

using namespace std;

ostream & operator << (ostream &out, const permissions & p) {
        out << ( (p.readable())?"Re":"  " ) << ( (p.writeable())?"Wr":"  " ) << ( (p.executable())?"Ex":"  " );
        return out;
}
ostream & operator << (ostream &out, const memory_value & m) {
        out << ((m.value!=0)?(char)m.value:' ') << " : " << bitset<7>(m.value).to_string() << " : " << m.p;
        return out;
}

OrcRunner::OrcRunner() { }

OrcRunner::OrcRunner(const Orc & orc) {
    OrcRunner in = OrcLoader().getOrcRunner(orc);
    MEMORY = unordered_map<size_t,memory_value>(in.MEMORY);
    entryPoint = in.entryPoint;

    filename = orc.getFilename();
}

// this will be the meaty function
// run the operation that you find, change MI to next operation
void OrcRunner::execute() const {
    ofstream ofs;
    ofs.open(filename + ".exe.txt");

    // YO! You are allowed to do this! That way you don't have to do "MEMORY.at(40).value"
    // int a = MEMORY.at(40);


    // currently just prints all memory addresses
    for (unordered_map<size_t,memory_value>::const_iterator it = MEMORY.begin(); it != MEMORY.end(); it++ )
        ofs << ((it->first > 99)?"":" ") << it->first << ": " << it->second << endl;



    ofs.close();
}
