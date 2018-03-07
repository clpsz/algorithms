#include "../common.h"
#include <assert.h>


int isEven(int n)
{
    if (n%2 == 0)
        return 1;
    
    return 0;
}

// greatest common divider
int pow(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    if (isEven(n))
    {
        return pow(x*x, n/2);
    }
    else
    {
        return x*pow(x*x, n/2);
    }
}

int main(int argc, char *argv[])
{
    assert(pow(1, 0) == 1);
    assert(pow(1, 100) == 1);
    assert(pow(2, 10) == 1024);
    assert(pow(3, 3) == 27);

    return 0;
}

