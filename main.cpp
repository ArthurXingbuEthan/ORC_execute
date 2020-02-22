#include <iostream>
#include <string>

#include "orc.h"

using namespace std;


int main () {

    Orc hi = Orc("output_1.txt");

    OrcRunner a = OrcRunner(hi);

    cout << "done" << endl;
    return 0;
}
