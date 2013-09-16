#include <iostream>
#include "poissonEqSolution.h"
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 *  The function makes N+1 discrete values for the solution
 *  of the 1D Poisson equation, as a function of x.
 *  The solutions are written to a file, for comparison with
 *  the numerical approach.
 */

void PoissonEqSolve(int N) {

    double *x = new double [N+2]; // x-values
    double *u = new double [N+2]; // Solution array

    fstream outFile;
    outFile.open("analyticalDataN1000.txt", ios::out);

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

    // Delete arrays to free memory
    delete [] x;
    delete [] u;

}
