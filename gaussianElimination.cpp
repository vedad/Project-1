#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "gaussianElimination.h"
#include "time.h"

using namespace std;

/*
 *  The function takes a tridiagonal matrix A, where the diagonals
 *  consist of three vectors; a, b, c. The function uses Gaussian
 *  elimination to solve the equation Ax = f, where x and f are
 *  vectors. The solutions v, along with the grid points x, are
 *  written to a file for further analysis.
 */

void GESolve(double aVals, double bVals, double cVals, int N) {

    clock_t start, finish;
    start = clock();

    double *a = new double[N+1]; // Lower diagonal
    double *b = new double[N+1]; // Leading diagonal
    double *c = new double[N+1]; // Upper diagonal
    double *f = new double[N+1]; // Source term
    double *v = new double[N+2]; // Solution
    double *x = new double[N+2]; // x-values

    // Function for filling the arrays with a constant aVals, bVals, cVals.
    fill_n(a, N+1, aVals);
    fill_n(b, N+1, bVals);
    fill_n(c, N+1, cVals);

    // Conditions to be met because of the arrays being N+1 long.
    a[0] = 0.0; a[1] = 0.0;
    b[0] = 0.0;
    f[0] = 0.0;
    c[N] = 0.0;

    double h = 1./(N+1); // Step length

    // Fill f with source term as function of x_i
    for (int i=1; i < (N+1); i++) {

        f[i] = h * h * (100 * exp(-10 * i * h));

    }

    // Forward substitution

    for (int i=2; i < (N+1); i++) {

        double factor = a[i] / b[i-1];
        b[i] -= c[i-1] * factor;
        f[i] -= f[i-1] * factor;

    }

    // Backward substitution

    v[0] = 0.0; // Dirichlet boundary conditions
    v[N+1] = 0.0; // - || -
    v[N] = f[N]/b[N]; // Define the last element in v

    for (int i=(N-1); i > 0; i--) {

        v[i] = (f[i] - c[i] * v[i+1]) / b[i];

    }

    finish = clock();
    double totTime = (finish - start)/(CLOCKS_PER_SEC);

    fstream outFile;
    outFile.open("numericalDataN10.txt", ios::out);

    // Make the values for x
    for (int i=0; i < N+2; i++) {

        x[i] = i/(double)(N+1);
        outFile << setprecision(15) << x[i] << " " << v[i] << endl;

    }

    outFile.close();

    cout << "Time elapsed for the tridiagonal matrix algorithm: " << totTime << " s" << endl;

    // Delete arrays to free memory
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] f;
    delete [] v;
    delete [] x;

}

