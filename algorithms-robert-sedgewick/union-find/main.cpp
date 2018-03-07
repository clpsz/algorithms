#include "common.h"
#include "quick_find.h"
#include "quick_union.h"
#include "weighted_quick_union.h"


int main(int argc, char *argv[])
{
    int unionCount;
    cin >> unionCount;
    UF *uf;

    if (argc < 2)
    {
        cerr << "Usage: " << endl << "      ./_main method";
        return -1;
    }

    if (string(argv[1]) == string("quick_find"))
    {
        uf = new quickFind(unionCount);
    }
    else if (string(argv[1]) == string("quick_union"))
    {
        uf = new quickUnion(unionCount);
    }
    else if (string(argv[1]) == string("weighted_quick_union"))
    {
        uf = new weightedQuickUnion(unionCount);
    }
    else
    {
        return -1;
    }

    int node1, node2;
    for (int i = 0; i < unionCount; i++)
    {
        cin >> node1 >> node2;
        uf->_union(node1, node2);
    }

    cout << uf->connected(1, 2) << endl;
    cout << uf->connected(1, 6) << endl;
    cout << uf->connected(1, 7) << endl;
    cout << uf->connected(476, 675) << endl;
    cout << uf->connected(1, 9) << endl;

    return 0;
}
