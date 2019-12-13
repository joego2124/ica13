#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>

#include "Folhdeccic.cpp"

using namespace std;

int main() {

    ofstream outFile;
    outFile.open("ECE 0301 - Differential Equation Reports.txt");

    Folhdeccic f(2, -1.25, 120);

    f.set_label("x");
    f.write_ode(outFile);
    f.write_solution(outFile);

    outFile.close();

    return 0;
}