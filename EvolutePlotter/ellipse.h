#ifndef ELLIPSE_H
#define ELLIPSE_H


#include <QVector>
#include <math.h>

class Ellipse
{
private:
    //центр в (0,0)
    const double x = 0;
    const double y = 0;

    //радиус внешней окружности
    double R;
    //а - бОльшая полуось, b - малая полуось
    double a, b;

    //массивы для точек
    QVector<double> pointsX;
    QVector<double> pointsY;
public:
    Ellipse();
    //функция для нахождения точек
    void recalc();
    QVector<double> getPointsX();
    QVector<double> getPointsY();
    double getA();
    double getB();
    void setA(double x);
    void setB(double x);
};
#endif // ELLIPSE_H
