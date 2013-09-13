#include <iostream>
#include "poissonEqSolution.h"
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void PoissonEqSolve(int N) {

    double *x = new double [N+2];
    double *u = new double [N+2];

    fstream outFile;
    outFile.open("analyticalData.txt", ios::out);

    for (int i=0; i < (N+2); i++) {

        /*
        Calculate values for x in [0,1] and the analytical solution
        to the Poisson equation.
        */

        x[i] = i/(double)(N+1);
        u[i] = 1 - (1 - exp(-10)) * x[i] - exp(-10 * x[i]);
        outFile << setprecision(15) << x[i] << " " << u[i] << endl;

    }

    outFile.close();

}
