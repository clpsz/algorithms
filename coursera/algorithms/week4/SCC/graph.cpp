#include "graph.h"
#include "vertex.h"
#include <QFile>
#include <QTextStream>
#include <QStack>
#include <QDebug>

Graph::Graph(int vCount, QString fileName):
    vertices(vCount+1, 0), rVertices(vCount+1, 0), rFinishOrder(vCount, 0)
{
    for (int i = 1; i <= vCount; ++i)
    {
        rVertices[i] = new Vertex(i);
        vertices[i] = new Vertex(i);
    }

    QFile graphFile(fileName);

    if (!graphFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open File error";
        exit(-1);
    }
    QTextStream in(&graphFile);

    QString line;
    int tail;
    int head;

    while (!in.atEnd())
    {
        line = in.readLine();
        QTextStream ss(&line);
        ss >> tail;
        ss >> head;

        vertices[tail]->addAdj(head);
        rVertices[head]->addAdj(tail);
    }
    graphFile.close();
}

Graph::~Graph()
{

}

void Graph::printGraph()
{
    int size = vertices.size() - 1;

    for (int i = 1; i <= size; ++i)
    {
        qDebug() << vertices[i]->toString();
    }
}

void Graph::printRFinishedOrder()
{
    int i = 0;
    for (auto d : rFinishOrder)
    {
        qDebug() << d << ": " << i++;
    }
}

void Graph::getRFinishedOrder()
{
    int size = rVertices.size();
    QVector<bool> known(size, false);
    --size;

    QStack<Vertex *> s;
    int order = 0;

    for (int i = 1; i <= size; ++i)
    {
        if (known[i])
            continue;

        s.push(rVertices[i]);
        known[i] = true;
        while (!s.empty())
        {
            auto thisVertex = s.top();
            bool finished = true;

            for (auto adj : thisVertex->getAdjs())
            {
                if (!known[adj])
                {
                    s.push(rVertices[adj]);
                    known[adj] = true;
                    finished = false;
                }
            }

            if (finished)
            {
                rFinishOrder[order] = thisVertex->getV();
                order++;

                s.pop();
            }
        }
    }
}

QVector<int> Graph::calcSCC()
{
    int size = vertices.size();
    QVector<bool> known(size, false);
    QVector<int> groups(size, -1);
    --size;

    QStack<Vertex *> s;
    int groupID = 0;

    for (int j = 0; j < size; ++j)
    {
        int i = rFinishOrder[size - j - 1];
        if (known[i])
            continue;

//        qDebug() << "Find: " << i;

        s.push(vertices[i]);
        known[i] = true;
        groups[i] = groupID;
        while (!s.empty())
        {
            auto thisVertex = s.top();
            bool finished = true;

            for (auto adj : thisVertex->getAdjs())
            {
                if (!known[adj])
                {
                    s.push(vertices[adj]);
                    known[adj] = true;
                    groups[adj] = groupID;
                    finished = false;
                }
            }

            if (finished)
            {
                s.pop();
            }
        }
        ++groupID;
    }

    return groups;
}

