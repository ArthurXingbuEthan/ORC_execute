#include "orcrunner.h"
#include "orc.h"

#include <iostream>

using namespace std;

OrcLoader::OrcLoader() {}

OrcRunner OrcLoader::getOrcRunner(Orc orc) {
    cout << "Entering OrcLoader::getOrcRunner(Orc)\n";
    orc.contents;
    OrcRunner R;
    cout << "Exiting OrcLoader::getOrcRunner(Orc)\n";
}
