#include "../common.h"
#include <assert.h>


// greatest common divider
int gcd(int m, int n)
{
    while (n != 0)
    {
        int rem = m%n;
        m = n;
        n = rem;
    }

    return m;
}

int main(int argc, char *argv[])
{
    assert(gcd(17, 11) == 1);
    assert(gcd(24, 16) == 8);
    assert(gcd(3, 9) == 3);

    return 0;
}

