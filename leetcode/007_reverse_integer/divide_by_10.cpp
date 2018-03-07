#include "../common.h"
#include <stdio.h>


// http://stackoverflow.com/questions/5558492/divide-by-10-using-bit-shifts



int64_t div10(int64_t dividend)
{
    int64_t invDivisor = 0x1999999A;
    return (int64_t) ((invDivisor * dividend) >> 32);
}


int pure_shift(int n)
{
    unsigned q, r;
    q = (n >> 1) + (n >> 2);
    q = q + (q >> 4);
    q = q + (q >> 8);
    q = q + (q >> 16);
    q = q >> 3;
    r = n - (((q << 2) + q) << 1);
    return q + (r > 9);
}


int main()
{
    printf("%d\n", div10(65536));    
    printf("%d\n", pure_shift(65536));    
}



