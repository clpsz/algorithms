#include "vetex.h"
#include "randint.h"
#include <QTextStream>
#include <QDebug>

Vetex::Vetex(int v):
    vIndex(v)
{
}

Vetex::~Vetex()
{
}

void Vetex::addAdj(int w)
{
    adjs.push_back(w);
}

int Vetex::selectRandomAdj()
{
    int size = adjs.size();
    RandInt r;
    int rand = r.getRand(0, size);

    return adjs[rand];
}

void Vetex::removeSelfLoop(int w)
{
    QMutableVectorIterator<int> it(adjs);
    while (it.hasNext())
    {
        if (it.next() == w)
            it.remove();
    }
}



void Vetex::update(int oldW, int newW)
{
    QMutableVectorIterator<int> it(adjs);
    while (it.hasNext())
    {
        if (it.next() == oldW)
            it.setValue(newW);
    }
}

const QVector<int> &Vetex::getAdjs()
{
    return adjs;
}

QString Vetex::toString()
{
    QVectorIterator<int> it(adjs);
    QString thisStr;
    QTextStream out(&thisStr);
    out << vIndex << ": ";

    while (it.hasNext())
    {
        out << it.next() << " ";
    }

    return thisStr;
}

int Vetex::edges()
{
    return adjs.size();
}

