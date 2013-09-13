#include <iostream>
#include <fstream>
#include "relativeError.h"
#include <cmath>
#include <iomanip>

using namespace std;

void calcRelErr(int N) {

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

    for (int k=1; k < (N+1); k++) {

        err[k] = log10(abs((v[k] - u[k])/u[k]));

    }

    double maxErr = err[1];
    for (int k=1; k < (N+1); k++) {

        if (err[k] > maxErr) { maxErr = err[k]; }

    }

    fstream outFile;
    outFile.open("singleErrorData.txt", ios::out);

    outFile << setprecision(15) << maxErr << endl;

    outFile.close();

}
