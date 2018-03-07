#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QMap>

class Vertex
{
public:
    Vertex(QString thisline);
    ~Vertex();

    const QMap<int, int> &getEdges() { return edges; }
    QString toString();

private:
    QMap<int, int> edges;
    int V;
};

#endif // VERTEX_H
