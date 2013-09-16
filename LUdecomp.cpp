#include <iostream>
#include <fstream>
#include <cmath>
#include <armadillo>
#include "time.h"
#include "LUdecomp.h"

using namespace std;
using namespace arma;

/*
 *  This function attemps to solve the linear set of equations
 *  Ax = f, by using a function lu() from the Armadillo library
 *  that employs LU decomposition of a matrix.
 */

void LUSolve(int N) {

    mat A, L, U, P; // Initialize matrices needed for LU decomposition
    A.zeros(N,N);

    vec x = zeros<vec>(N); // Grid points
    vec f = zeros<vec>(N); // Source term

    double h = 1./(N+1); // Step length

    for (int i=0; i < N; i++) {

        f[i] = h * h * 100 * exp(-10 * (i+1) * h);

    }

    // Make the matrix A tridiagonal like we had earlier.
    for (int i=0; i < N; i++) {

        for (int j=0; j < N; j++) {

            if (i==j) {
                A(i,j) = 2;
            }

            else if (abs(i-j) == 1) {
                A(i,j) = -1;
            }

            else { continue; }
        }
    }

    // Use LU decomposition
//    lu(L, U, P, A);

    mat B = P.t() * L * U;
    L = A.i();

    x = L * f;

    cout << x << endl;


}
