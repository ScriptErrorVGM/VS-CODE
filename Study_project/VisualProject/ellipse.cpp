#include "ellipse.h"

Ellipse::Ellipse()
{
    a = 40;
    b = 20;
    recalc();
}

void Ellipse::recalc()
{
    pointsX.clear();
    pointsY.clear();

    for(int i = 0; i < 360; i++) {
        pointsX.push_back(a * cos(i * M_PI / 180.0));
        pointsY.push_back(b * sin(i * M_PI / 180.0));
    }
}

QVector<double> Ellipse::getPointsX()
{
    return pointsX;
}

QVector<double> Ellipse::getPointsY()
{
    return pointsY;
}

double Ellipse::getA()
{
    return a;
}

double Ellipse::getB()
{
    return b;
}
void Ellipse::setA(double x)
{
    a = x;
    recalc();
}

void Ellipse::setB(double x)
{
    b = x;
    recalc();
}
