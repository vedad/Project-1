#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "tdma.h"

using namespace std;


void doAlgorithm(double aVals, double bVals, double cVals, int N) {

    double a [N-1];
    double b [N];
    double c [N-1];
    double f [N];
    double v [N];
    double x [N];

    fill_n(a, N-1, aVals);
    fill_n(b, N, bVals);
    fill_n(c, N-1, cVals);

    a[0] = 0.0;
    c[N-2] = 0.0;

    double h = 1./(N+1);

    /* Forward substitution */

    for (int i=0; i <N; i++) {

        f[i] = h * h * (100 * exp(-10 * i * h));

    }

    for (int i=0; i < N; i++) {

        b[i+1] -= c[i] * a[i+1] / b[i];
        f[i+1] -= f[i] * a[i+1] / b[i];

    }

    /* Backward substitution */

    for (int i=(N-1); i >= 0; i--) {

        v[i] = (f[i] - c[i] * v[i+1]) / b[i];

    }

    fstream outFile;
    outFile.open("linEqSolutionSet.txt", ios::out);

    for (int i=0; i < N; i++) {

        x[i] = i/(double)(N);
        outFile << setprecision(3) << x[i] << " " << v[i] << endl;

    }

//    outFile << endl;
    outFile.close();

}
