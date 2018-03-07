#include "randint.h"
#include <random>
#include <QDateTime>
#include <QTime>
#include <QDebug>

bool init = false;
std::default_random_engine ge;

RandInt::RandInt()
{
    QString curTimeStr = QTime::currentTime().toString("msszzz");
    if (!init)
    {
        int seed = curTimeStr.toInt();
        qDebug() << seed;
        ge = std::default_random_engine(seed);
        init = true;
    }
}

RandInt::~RandInt()
{

}

int RandInt::getRand(int min, int max)
{
    std::uniform_int_distribution<int> ui(min, max-1);

    return ui(ge);
}

