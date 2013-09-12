#include <iostream>
#include "gaussianElimination.h"
#include "poissonEqSolution.h"

using namespace std;

int main()
{
    GESolve(-1.0, 2.0, -1.0, 100);
    PoissonEqSolve(100);

    return 0;
}

