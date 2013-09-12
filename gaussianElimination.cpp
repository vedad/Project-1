#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "gaussianElimination.h"

using namespace std;

void GESolve(double aVals, double bVals, double cVals, int N) {

    double a [N+1];
    double b [N+1];
    double c [N+1];
    double f [N+1];
    double v [N+2];
    double x [N+2];

    fill_n(a, N+1, aVals);
    fill_n(b, N+1, bVals);
    fill_n(c, N+1, cVals);

    a[0] = 0.0; a[1] = 0.0;
    b[0] = 0.0;
    f[0] = 0.0;
    c[N] = 0.0;

    double h = 1./(N+1);

    for (int i=1; i < (N+1); i++) {

        f[i] = h * h * (100 * exp(-10 * i * h));

    }

    // Forward substitution

    for (int i=2; i < (N+1); i++) {

        b[i] -= c[i-1] * a[i] / b[i-1];
        f[i] -= f[i-1] * a[i] / b[i-1];

    }

    // Backward substitution

    v[0] = 0.0;
    v[N+1] = 0.0;
    v[N] = f[N]/b[N];

    for (int i=(N-1); i > 0; i--) {

        v[i] = (f[i] - c[i] * v[i+1]) / b[i];

    }

    fstream outFile;
    outFile.open("numericalData.txt", ios::out);

    for (int i=0; i < N+2; i++) {

        x[i] = i/(double)(N+1);
        outFile << x[i] << " " << v[i] << endl;

    }

    outFile.close();

}

