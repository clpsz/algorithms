#include <Qdebug>
#include <QTextStream>
#include "vertex.h"

Vertex::Vertex(QString thisline)
{
    QTextStream ss(&thisline);

    ss >> V;
    int peer, distance;
    while (!ss.atEnd())
    {
        ss >> peer;
        ss >> distance;
        edges.insert(peer, distance);
    }
}

QString Vertex::toString()
{
    QString res;
    QTextStream ss(&res);

    ss << V << ":";

    QMap<int, int>::const_iterator it = edges.cbegin();

    while (it != edges.cend())
    {
        ss << " " << it.key() << "," << it.value();
        ++it;
    }

    return res;
}

Vertex::~Vertex()
{

}

