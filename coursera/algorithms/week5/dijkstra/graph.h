#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QVector>
#include "vertex.h"

class Graph
{
public:
    Graph(int vCount, const QString &filename);
    ~Graph();

    const QVector<Vertex *> &getVertices() { return vertices; }

    void printGraph();

private:
    QVector<Vertex *> vertices;
};

#endif // GRAPH_H
