#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "graph.h"

Graph::Graph(int vCount, const QString &filename):
    vertices(vCount + 1, 0)
{
    QFile graphFile(filename);

    if (!graphFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open File error";
        exit(-1);
    }
    QTextStream in(&graphFile);

    int i = 1;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        vertices[i] = new Vertex(line);
        ++i;
    }
}

void Graph::printGraph()
{
    int size = vertices.size() - 1;

    for (int i = 1; i <= size; ++i)
    {
        qDebug() << vertices[i]->toString();
    }
}

Graph::~Graph()
{

}

