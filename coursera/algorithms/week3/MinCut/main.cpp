#include "graph.h"
#include <QCoreApplication>
#include <QThread>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qSetMessagePattern("%{file} %{line} %{function} %{message}");

    int minCut = 1000;

    int count = 40;
    while (--count > 0)
    {
        Graph G(200, "data.txt");
        while (G.getVetexNum() > 2)
        {
            int v, w;
            G.selectRandomEdge(v, w);
            G.contract(v, w);
        }
//        G.printGraph();

        int curCut = G.anyCut();
//        qDebug() << curCut;
        if (curCut < minCut)
            minCut = curCut;
    }


    qDebug() << "Min cut is: " << minCut;
    return a.exec();
}
