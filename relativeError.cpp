#include <iostream>
#include <fstream>
#include "relativeError.h"
#include <cmath>
#include <iomanip>

using namespace std;

/*
 *   The function reads the numerical solutions and analytical
 *   solutions to the 1D Poisson equation, given in a text file.
 *   It calculates the relative error, extracts the max relative
 *   error for a given N, and writes this value to a file for
 *   further analysis.
 */

void calcRelErr(int N) {

    // Reads numerical solutions
    fstream inFile1;
    inFile1.open("../build-Project-1-Desktop_Qt_5_1_0_clang_64bit-Debug/numericalData.txt", ios::in);

    double *v = new double [N+2];
    int i = 0;
    double a, b;

    while (inFile1 >> a >> b) {

        v[i] = b;
        i++;
    }

    inFile1.close();

    // Reads analytical solutions
    fstream inFile2;
    inFile2.open("../build-Project-1-Desktop_Qt_5_1_0_clang_64bit-Debug/analyticalData.txt", ios::in);

    double *u = new double [N+2];
    double c, d;
    int j = 0;

    while (inFile2 >> c >> d) {

        u[j] = d;
        j++;

    }

    double *err = new double [N+2];
    err[0] = 0.0;
    err[N+1] = 0.0;

    // Calculates relative error for a given N
    for (int k=1; k < (N+1); k++) {

        err[k] = log10(abs((v[k] - u[k])/u[k]));

    }

    // Extract max relative error
    double maxErr = err[1];
    for (int k=1; k < (N+1); k++) {

        if (err[k] > maxErr) { maxErr = err[k]; }

    }

    // Write out max relative error to file
    fstream outFile;
    outFile.open("singleErrorData.txt", ios::out);

    outFile << setprecision(15) << maxErr << endl;

    outFile.close();

}
