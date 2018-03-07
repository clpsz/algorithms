#ifndef GRAPH_H
#define GRAPH_H

#include <QMap>

class Vetex;

class Graph
{
public:
    Graph(int v, QString fileName);
    ~Graph();

    void contract(int v, int w);
    void contractAndPrint(int v, int w);
    void selectRandomEdge(int &v, int &w);
    void printGraph();
    int getVetexNum() {
        return vNum;
    }
    int anyCut();

private:
    int vNum;
    int eNum;
    QMap<int, Vetex*> vetexs;
};

#endif // GRAPH_H
