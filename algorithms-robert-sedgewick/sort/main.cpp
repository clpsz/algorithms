#include "common.h"
#include "Sort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

const string usage("Usage:\n      _main method");

int main(int argc, char *argv[])
{
    Sort *sort;

    if (argc != 2)
    {
    }

    if (string(argv[1]) == string("selection"))
    {
        sort = new SelectionSort();
    }
    else if (string(argv[1]) == string("insertion"))
    {
        sort = new InsertionSort();
    }
    else if (string(argv[1]) == string("bubble"))
    {
        sort = new BubbleSort();
    }
    else if (string(argv[1]) == string("shell"))
    {
        sort = new ShellSort();
    }
    else if (string(argv[1]) == string("merge"))
    {
        sort = new MergeSort();
    }
    else if (string(argv[1]) == string("quick"))
    {
        sort = new QuickSort();
    }
    else
    {
        cout << usage << endl;
        return -1;
    }

    sort->show();
    sort->sort();
    sort->show();

    return 0;
}

