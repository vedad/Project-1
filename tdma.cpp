#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "tdma.h"

using namespace std;

void doAlgorithm(double aVals, double bVals, double cVals, int N) {

    double a [N];
    double b [N];
    double c [N];
    double f [N];
    double v [N];
    double x [N];

    fill_n(a, N, aVals);
    fill_n(b, N, bVals);
    fill_n(c, N, cVals);

    a[0] = 0.0;
    c[N-1] = 0.0;

    double h = 1./(N+1);

    for (int i=0; i < N; i++) {

        f[i] = h * h * (100 * exp(-10 * i * h));

    }

    /* Forward substitution */

    for (int i=0; i < N; i++) {

        b[i+1] -= c[i] * a[i+1] / b[i];
        f[i+1] -= f[i] * a[i+1] / b[i];

    }

    cout << "third to last f: " << f[N-3] << endl;
    cout << "second to last f: " << f[N-2] << endl;
    cout << "last f: " << f[N-1] << endl;
    cout << "superlast f: " << f[N] << endl;

    /* Backward substitution */

    for (int i=N; i >= 0; i--) {

        if (i == N) {

            v[i] = 0;
        }

        else if (i == 0) {

            v[i] = 0;
        }

        else {

            v[i] = (f[i] - c[i] * v[i+1]) / b[i];

        }

    }

    fstream outFile;
    outFile.open("linEqSolutionSet.txt", ios::out);

    for (int i=0; i <= N; i++) {

        x[i] = i/(double)(N);
        outFile << setprecision(3) << x[i] << " " << v[i] << endl;
        cout << v[i] << "      " << "index: " << i << endl;

    }

    cout << "v-size: " << sizeof(v)/sizeof(*v) << endl;
    cout << "x-size: " << sizeof(x)/sizeof(*x) << endl;


//    outFile << endl;
    outFile.close();

}
