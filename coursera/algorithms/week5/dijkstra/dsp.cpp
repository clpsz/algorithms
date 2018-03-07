#include <QMap>
#include <QDebug>
#include "graph.h"
#include "dsp.h"
#include "vertex.h"

DSP::DSP(int countVertex, Graph *G)
{
    this->G = G;
    this->countVertex = countVertex;
}

DSP::~DSP()
{

}

QVector<int> DSP::getShortestPaths(int V)
{
    QVector<int> res(countVertex+1, 1000000);
    QVector<bool> viewed(countVertex+1, false);
    int viewedCount = 0;

    QVector<Vertex *> vertices = G->getVertices();
    //Vertex *sourceVertex = vertices[V];

    res[V] = 0;
    viewed[V] = true;
    ++viewedCount;

    while (viewedCount < countVertex)
    {
       int nextIndex = -1;
       int nextDistance = -1;

       for (int i = 1; i <= countVertex; ++i)
       {
           if (viewed[i])
           {
               int curDistance = res[i];
               const QMap<int, int> &edges = vertices[i]->getEdges();

               QMap<int, int>::const_iterator it = edges.cbegin();
               while (it != edges.cend())
               {
                   if (viewed[it.key()])
                   {
                       ++it;
                       continue;
                   }
                   if (nextDistance == -1)
                   {
                       nextDistance = curDistance + it.value();
                       nextIndex = it.key();
                   }
                   else if (curDistance + it.value() < nextDistance)
                   {
                       nextDistance = curDistance + it.value();
                       nextIndex = it.key();
                   }

                   ++it;
               }
           }
       }

//       qDebug() << nextIndex << " " << nextDistance;
       res[nextIndex] = nextDistance;
       viewed[nextIndex] = true;

        ++viewedCount;
    }

    return res;
}
