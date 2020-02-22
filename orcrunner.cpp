#include "orcrunner.h"
#include <iostream>

using namespace std;


OrcRunner::OrcRunner() { throw NoFilenameGiven(); }

OrcRunner::OrcRunner(string filename) {
    if (orc.type == OBJ) throw OrcIsObject();
    
    orc = filename;
    execute();
}

void OrcRunner::execute() {
    
}
