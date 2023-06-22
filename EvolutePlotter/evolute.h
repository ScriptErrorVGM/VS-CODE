#ifndef EVOLUTE_H
#define EVOLUTE_H

#include <QVector>
#include <math.h>
#include <algorithm>
#include <set>
#include <iterator>
#include <utility>

class Evolute
{
private:
    //а - бОльшая полуось, b - малая полуось
    double a, b;

    //массивы для точек
    QVector<double> pointsX;
    QVector<double> pointsY;
public:
    Evolute();
    //функция для нахождения точек
    void recalc();
    QVector<double> getPointsX();
    QVector<double> getPointsY();
    double getA();
    double getB();
    void setA(double x);
    void setB(double x);
};

#endif // EVOLUTE_H
