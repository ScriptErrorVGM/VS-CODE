#include "evolute.h"

Evolute::Evolute()
{
    a = 40;
    b = 20;
    recalc();
}

struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const
    {
        //сравниваем по углу
        return (-atan2(l.first, -l.second)) < (-atan2(r.first, -r.second));
    }
};

void Evolute::recalc()
{
    pointsX.clear();
    pointsY.clear();

    double x, y, cost, sint;
    std::multiset<std::pair<double,double>, comp> m;

    for(double t = 0; t <= 100; t+=1) {
            cost = cos(t);
            sint = sin(t);
            x = (((a*a - b*b)/a) * (cost * cost * cost));
            y = (((b*b - a*a)/b) * (sint * sint * sint));
            m.insert(std::make_pair(x, y));
    }

    for(auto it = m.begin(); it != m.end(); it++) {
        pointsX.push_back(it->first);
        pointsY.push_back(it->second);
    }
}

QVector<double> Evolute::getPointsX()
{
    return pointsX;
}

QVector<double> Evolute::getPointsY()
{
    return pointsY;
}

double Evolute::getA()
{
    return a;
}

double Evolute::getB()
{
    return b;
}

void Evolute::setA(double x)
{
    a = x;
    recalc();
}

void Evolute::setB(double x)
{
    b = x;
    recalc();
}
