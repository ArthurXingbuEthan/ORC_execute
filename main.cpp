#include <iostream>
#include <string>

#include "orc.h"
#include "orcrunner.h"

using namespace std;


int main () {

    Orc hello("output_1.txt");

    OrcRunner a = hello;

    cout << "done" << endl;
    return 0;
}
