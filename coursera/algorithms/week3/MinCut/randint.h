#ifndef RANDINT_H
#define RANDINT_H

#include <random>

class RandInt
{
public:
    RandInt();
    ~RandInt();

    int getRand(int min, int max);

};

#endif // RANDINT_H
