#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QVector>

class Vertex;

class Graph
{
public:
    Graph(int vCount, QString fileName);
    ~Graph();

    void printGraph();
    void printRFinishedOrder();
    void getRFinishedOrder();
    QVector<int> calcSCC();

private:
    QVector<Vertex *> vertices;
    QVector<Vertex *> rVertices;
    QVector<int> rFinishOrder;
};

#endif // GRAPH_H
