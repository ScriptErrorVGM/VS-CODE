#ifndef PWIN_H
#define PWIN_H

#include <QWidget>
#include <QPolarChart>
#include <QValueAxis>
#include <QtCharts/QSplineSeries>
#include <QVector>

namespace Ui {
class PWin;
}

class PWin : public QWidget
{
    Q_OBJECT

public:
    QPolarChart *chart;
    QValueAxis *angularAxis;
    QValueAxis *radialAxis;
    QSplineSeries *p_coords;
    explicit PWin(QWidget *parent = nullptr, QVector<double> xs = {0}, QVector<double> ys = {0});
    ~PWin();

private:
    Ui::PWin *ui;
};

#endif // PWIN_H
