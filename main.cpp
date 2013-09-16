#include <iostream>
#include <fstream>
#include <cmath>
#include <armadillo>
#include "time.h"
#include "gaussianElimination.h"
#include "poissonEqSolution.h"
#include "relativeError.h"
#include "LUdecomp.h"

using namespace std;
using namespace arma;

void exB(int);
void exC();
void exD(int);

/*
 *  The main function calls one of the other functions to run the
 *  program(s) that solves the given exercises.
 */

int main() {

    exB(10);

    return 0;

}

void exB(int N) {

    GESolve(-1.0, 2.0, -1.0, N);
//    PoissonEqSolve(N);

}

/*
 *  exC calls the Gaussian elimination solver,
 *  the analytical solver, and calculates the max relative
 *  error for several N and writes these to a file for plotting.
 */

void exC() {


    fstream outFile;
    outFile.open("errorData.txt", ios::out);

    fstream inFile;

    for (int N=10; N <= 1e6; N*=10) {

        GESolve(-1.0, 2.0, -1.0, N);
        PoissonEqSolve(N);
        calcRelErr(N);

        inFile.open("singleErrorData.txt", ios::in);

        double a, maxErr;

        while (inFile >> a) {

            maxErr = a;

        }

        inFile.close();

        outFile << log10(N) << " " << maxErr << endl;

    }

    outFile.close();

}

void exD(int N) {

    LUSolve(N);
}

