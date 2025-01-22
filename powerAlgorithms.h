#ifndef POWERALGORITHMS_H_INC
#define POWERALGORITHMS_H_INC

//multiplies a given number (n) by itself p times and returns the result,
//giving the result of a number raised to a power
long long int naive_power(int x, int p);

//obtain the result of a number raised to a power using an unoptimized
//divide and conquer approach (duplicate calculations may occur)
long long int unoptimized_dc_power(int x, int p);

//obtain the result of a number raised to a power using an optimized
//divide and conquer approach while avoiding the duplicate calculations 
//that may occur in the unoptimized_dc_power() function
long long int optimized_dc_power(int x, int p);

#endif
