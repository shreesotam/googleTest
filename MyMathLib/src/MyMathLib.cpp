#include "MyMathLib.h"
#include <stdexcept>
#include <math.h>
#include <cctype>
#include <string.h>

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

bool isPositive(int x)
{
    
    return x>=0;
}

int countPositives(std::vector<int> const &inputVector)
{
    return std::count_if(inputVector.begin(),inputVector.end(),isPositive);
}

void toUpper(char *inputString)
{
    for(unsigned i= 0; i<strlen(inputString);i++)
    {
        inputString[i] = toupper(inputString[i]);
    }
}
