#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "graph.h"
#include "dsp.h"

QVector<int> care{7,37,59,82,99,115,133,165,188,197};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int vertexCount = 200;
    QString filename("data.txt");

    Graph G(vertexCount, filename);
    DSP D(vertexCount, &G);

    QVector<int> sp = D.getShortestPaths(1);


    QString res;
    QTextStream ss(&res);
    for (auto c : care)
    {
        ss << sp[c] << ",";
    }
    qDebug() << res;
//    G.printGraph();

    return a.exec();
}
