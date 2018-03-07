#include "graph.h"
#include "vetex.h"
#include "randint.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

Graph::Graph(int v, QString fileName):
    vNum(v), eNum(0)
{
    for (int i = 1; i < v+1; ++i)
    {
        Vetex *v = new Vetex(i);
        vetexs.insert(i, v);
    }

    QFile graphFile(fileName);

    if (!graphFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open File error";
        exit(-1);
    }
    QTextStream in(&graphFile);

    QString line;
    int vv;
    int adj;

    while (!in.atEnd())
    {
        line = in.readLine();
        QTextStream ss(&line);
        ss >> vv;

        while (!ss.atEnd())
        {
            ss >> adj;
            vetexs[vv]->addAdj(adj);
        }
    }
    graphFile.close();
}

Graph::~Graph()
{
}

// suck v into w
void Graph::contract(int v, int w)
{
//    qDebug() << "Contracting: " << v << " " << w;
    Vetex *V = vetexs[v];
    Vetex *W = vetexs[w];

    V->removeSelfLoop(w);
    W->removeSelfLoop(v);

    const QVector<int> &vAdjs = V->getAdjs();
    for (auto adj : vAdjs)
    {
        W->addAdj(adj);
        vetexs[adj]->update(v, w);
    }

    auto it = vetexs.find(v);
    vetexs.erase(it);
    vNum--;
}

void Graph::contractAndPrint(int v, int w)
{
    contract(v, w);
    printGraph();
}

void Graph::selectRandomEdge(int &v, int &w)
{
    int size = vetexs.size();
    RandInt r;
    int rand = r.getRand(0, size);

    QMapIterator<int, Vetex *> it(vetexs);
    while (rand >= 0 && it.hasNext())
    {
        it.next();
        rand--;
    }
    v = it.key();
    Vetex *thisVetex = it.value();
    w = thisVetex->selectRandomAdj();
}



void Graph::printGraph()
{
    QMapIterator<int, Vetex*> it(vetexs);
    qDebug() << vNum << ":";
    while (it.hasNext())
    {
        it.next();
        Vetex *thisVetex = it.value();

        qDebug() << thisVetex->toString();
    }
    qDebug() << " ";
}

int Graph::anyCut()
{
    QMapIterator<int, Vetex*> it(vetexs);
    it.next();
    Vetex *thisVetex = it.value();
    return thisVetex->edges();
}
