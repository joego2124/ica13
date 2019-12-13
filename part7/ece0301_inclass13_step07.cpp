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

    Folhdeccic f1;
    Folhdeccic f2(10, -2.5, 1);

    f1.write_ode(outFile);
    f1.write_solution(outFile);

    f2.set_label("x");
    f2.write_ode(outFile);
    f2.write_solution(outFile);

    outFile.close();

    return 0;
}