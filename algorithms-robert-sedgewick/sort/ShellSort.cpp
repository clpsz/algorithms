#include "ShellSort.h"

void ShellSort::sort()
{
    int h;

    while (h < dataLen/3)
    {
        h = 3*h + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < dataLen; i++)
        {
            for (int j = i; j >= h; j -= h)
            {
                if (less(data[j], data[j-h]))
                {
                    exch(j, j-h);
                }
                else
                {
                    break;
                }
            }
        }
        h /= 3;
    }
}

