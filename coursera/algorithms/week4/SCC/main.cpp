#include "graph.h"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Graph G(875714, "data1.txt");
//    Graph G(12, "data.txt");
//    G.printGraph();
//    qDebug() << "";
    G.getRFinishedOrder();
//    G.printRFinishedOrder();
    auto res = G.calcSCC();
    QVector<int> counts(875714, 0);

    int size = res.size() - 1;
    for (int i = 1;  i <= size; ++i)
    {
        if (res[i] >= 0)
            ++counts[res[i]];
    }

    std::sort(counts.begin(), counts.end());

    int countsSize = counts.size();
    for (int i = 0; i < 5; i++)
    {
        qDebug() << counts[countsSize - 1 - i] << " ";
    }
//    int size = res.size() - 1;

//    for (int i = 1; i <= size; ++i)
//    {
//        qDebug() << i << ": " << res[i];
//    }

    qDebug() << "finished";

    return a.exec();
}
