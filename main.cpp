#include <iostream>
#include <fstream>
#include <cmath>
#include "gaussianElimination.h"
#include "poissonEqSolution.h"
#include "relativeError.h"

using namespace std;

int main() {

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

    return 0;
}

