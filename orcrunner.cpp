#include "orc.h"
// JANK FIX: Please find better way unless this is best
#include "orcloader.cpp"

#include <iostream>

using namespace std;

OrcRunner::OrcRunner() { entryPoint = 0; }

OrcRunner::OrcRunner(const Orc & orc) { 
    OrcRunner in = OrcLoader().getOrcRunner(orc);
    MEMORY = unordered_map<size_t,Byte7>(in.MEMORY);
    entryPoint = in.entryPoint;
}

// this will be the meaty function
// run the operation that you find, change MI to next operation
void OrcRunner::execute() const {}
