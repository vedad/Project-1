#include <iostream>
#include "tdma.h"
#include "poissonEqSolution.h"

using namespace std;

int main()
{
    doAlgorithm(-1.0, 2.0, -1.0, 1000);
    analyticalSolution();


    return 0;
}

