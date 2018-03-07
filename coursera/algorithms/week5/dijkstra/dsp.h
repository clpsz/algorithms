#ifndef DSP_H
#define DSP_H

#include <QVector>

class Graph;

class DSP
{
public:
    DSP(int countVertex, Graph *G);
    ~DSP();

    QVector<int> getShortestPaths(int V);


private:
    Graph *G;
    int countVertex;
};

#endif // DSP_H
