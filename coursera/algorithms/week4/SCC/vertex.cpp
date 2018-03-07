#include "vertex.h"
#include <QTextStream>

Vertex::Vertex(int v):
    V(v)
{

}

Vertex::~Vertex()
{

}

void Vertex::addAdj(int head)
{
    adjs.push_back(head);
}

QString Vertex::toString()
{
    QString line;
    QTextStream ss(&line);

    ss << V << ": ";

    for (auto adj : adjs)
        ss << adj << " ";

    return line;
}
