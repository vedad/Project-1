#include <iostream>
#include "poissonEqSolution.h"
#include <cmath>
#include <fstream>

using namespace std;

void analyticalSolution() {

    double x [1001];
    double u [1001];

    for (int i=0; i <= 1000; i++) {

        x[i] = i/1000.;
        u[i] = 1 - (1 - exp(-10)) * x[i] - exp(-10 * x[i]);

     }


    fstream outFile;
    outFile.open("analyticalSolution.txt", ios::out);

    for (int i=0; i <= 1000; i++) {

        outFile << u[i] << endl;
    }

    outFile.close();
}
