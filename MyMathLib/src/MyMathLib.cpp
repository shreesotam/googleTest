#include "MyMathLib.h"
#include <stdexcept>
#include <math.h>

double mySqrt(double x)
{
    if (x<0)
    {
        throw std::runtime_error("Negative argument");
    }
    return sqrt(x);
}

int sum(int a, int b)
{
    return a+b;
}
