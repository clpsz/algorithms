#ifndef VERTEX_H
#define VERTEX_H

#include <QVector>

class Vertex
{
public:
    Vertex(int v);
    ~Vertex();

    int getV() {
        return V;
    }

    const QVector<int> &getAdjs() {
        return adjs;
    }

    void addAdj(int head);

    QString toString();

private:
    int V;
    QVector<int> adjs;
};

#endif // VERTEX_H
