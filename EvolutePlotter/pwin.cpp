#include "pwin.h"
#include "ui_pwin.h"

PWin::PWin(QWidget *parent, QVector<double> xs, QVector<double> ys) :
    QWidget(parent),
    ui(new Ui::PWin)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(600, 500));

    const qreal angularMin = 0;
    const qreal angularMax = 360;

    const qreal radialMin = 0;
    const qreal radialMax = 50;
    p_coords = new QSplineSeries();
    p_coords->setName("Evolute");

    //Добавляем точки
    for(int i = 0; i < ys.size(); i++) {

        p_coords->append(xs[i], ys[i]);
    }

    //инициализация виджета для полярных графиков
    chart = new QPolarChart();

    chart->addSeries(p_coords);

    angularAxis = new QValueAxis();
    angularAxis->setTickCount(9);
    angularAxis->setLabelFormat("%.1f");
    angularAxis->setShadesVisible(true);
    angularAxis->setShadesBrush(QBrush(QColor(249, 249, 255)));
    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    radialAxis = new QValueAxis();
    radialAxis->setTickCount(9);
    radialAxis->setLabelFormat("%d");
    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    p_coords->attachAxis(radialAxis);
    p_coords->attachAxis(angularAxis);
    radialAxis->setRange(radialMin, radialMax);
    angularAxis->setRange(angularMin, angularMax);
    ui->chartView->setChart(chart);
}

PWin::~PWin()
{
    delete ui;
}
