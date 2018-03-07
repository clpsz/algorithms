#ifndef VETEX_H
#define VETEX_H

#include <QVector>

class Vetex
{
public:
    Vetex(int v);
    ~Vetex();
    void addAdj(int w);
    int selectRandomAdj();
    void removeSelfLoop(int w);
    void update(int oldW, int newW);
    const QVector<int> &getAdjs();
    QString toString();
    int edges();

private:
    int vIndex;
    QVector<int> adjs;
};

#endif // VETEX_H
