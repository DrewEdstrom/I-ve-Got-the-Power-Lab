#include "powerAlgorithms.h"

using namespace std;

//multiplies a given number (n) by itself p times and returns the result,
//giving the result of a number raised to a power
long long int naive_power(int x, int p)
{
    if(x == 0)
    {
        return 0;
    }
    if(p == 0)
    {
        return 1;
    }

    return x * naive_power(x, p-1);
}

//obtain the result of a number raised to a power using an unoptimized
//divide and conquer approach (duplicate calculations may occur)
long long int unoptimized_dc_power(int x, int p)
{
    if(x == 0)
    {
        return 0;
    }
    if(p == 0)
    {
        return 1;
    }
    if(p % 2 == 0)
    {
        return unoptimized_dc_power(x, p/2) * unoptimized_dc_power(x, p/2);
    }

    return x * unoptimized_dc_power(x, p/2) * unoptimized_dc_power(x, p/2);
}

//obtain the result of a number raised to a power using an optimized
//divide and conquer approach while avoiding the duplicate calculations 
//that may occur in the unoptimized_dc_power() function
long long int optimized_dc_power(int x, int p)
{
    if(x == 0)
    {
        return 0;
    }
    if(p == 0)
    {
        return 1;
    }

    long long int temp = optimized_dc_power(x, p/2);
    
    if(p % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return x * temp * temp;
    }
}
