#include "orcrunner.h"
#include "orc.h"

#include <iostream>

using namespace std;

OrcRunner::OrcRunner() { throw NoOrcFileGiven(); }

OrcRunner::OrcRunner(Orc orc) {
    OrcRunner in = OrcLoader().getOrcRunner(orc);
}

void OrcRunner::execute() {}
