#include "mainwindow.h"
#include "ui_mainwindow.h"

class Ellipse ellipse;
Evolute evolute;
QCPCurve *curveEllipse;
QCPCurve *curveEvolute;

double xrange;
double yrange;

QCPItemEllipse *elliPrim;
int iter = 0;
bool canSee = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //название окна
    this->setWindowTitle("Evolute");


    //устанавливаем стартовое значение текстового поля
    ui->aLineEdit->setText(QString::number(ellipse.getA()));
    ui->bLineEdit->setText(QString::number(ellipse.getB()));
    //проверка на ввод
    ui->aLineEdit->setValidator(new QDoubleValidator(this));
    ui->bLineEdit->setValidator(new QDoubleValidator(this));

    //инициализация кривых
    curveEllipse = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    curveEllipse->setData(ellipse.getPointsX(), ellipse.getPointsY());

    curveEvolute = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    curveEvolute->setData(evolute.getPointsX(), evolute.getPointsY());

    //инициализация примитива
    elliPrim = new QCPItemEllipse(ui->plot);
    double tmp_x = evolute.getPointsX()[0];
    double tmp_y = evolute.getPointsY()[0];
    elliPrim->topLeft->setCoords(tmp_x-4, tmp_y+4);
    elliPrim->bottomRight->setCoords(tmp_x+4, tmp_y-4);
    elliPrim->setBrush(QBrush(Qt::red));
    elliPrim->setPen(QPen(Qt::red));
    elliPrim->setVisible(0);

    //инициализация таймера для анимации
    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(redrawSquare()));
    dataTimer->start(100);

    //подписи к осям
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");

    xrange = 150;
    yrange = 150;

    ui->plot->xAxis->setRange((-1)*xrange, xrange);
    ui->plot->yAxis->setRange((-1)*yrange, yrange);
    ui->plot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redrawSquare()
{
    //анимация примитива
    if(canSee) {
        QVector<double> xs = evolute.getPointsX();
        QVector<double> ys = evolute.getPointsY();
        if(iter == xs.size()) {
         iter = 0;
        }
        elliPrim->topLeft->setCoords(xs[iter]-4, ys[iter]+4);
        elliPrim->bottomRight->setCoords(xs[iter]+4, ys[iter]-4);
        iter+=1;
        ui->plot->replot();
    }
}

/*//функция, вызывающаяся при изменении текста внутри текстового поля
void MainWindow::on_radiusLineEdit_textEdited(const QString &arg1)
{
    ast.setR(abs(arg1.toDouble()));
    curve->setData(ast.getPointsX(), ast.getPointsY());
    ui->plot->replot();
}*/


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    canSee = !canSee;
    iter = 0;
    elliPrim->setVisible(canSee);
    ui->plot->replot();
}

//функция, вызывающаяся при изменении размера главного окна
void MainWindow::resizeEvent(QResizeEvent *event)
{
    double x_c = 0.2411;
    double y_c = 0.3036;
    if(event->oldSize().width() < 0)
        return;

    yrange = (double)event->size().height() * y_c;
    xrange = (double)event->size().width() * x_c;

    ui->plot->yAxis->setRange((-1)*yrange, yrange);
    ui->plot->xAxis->setRange((-1)*xrange, xrange);
    ui->plot->replot();
}

//функция, открывающая новое окно, после нажатия на кнопку
void MainWindow::on_toPolarButton_clicked()
{
    PWin *pw = new PWin(nullptr, evolute.getPointsX(), evolute.getPointsY());
    pw->setWindowTitle("Polar");
    pw->show();
}


void MainWindow::on_aLineEdit_textEdited(const QString &arg1)
{
    ellipse.setA(abs(arg1.toDouble()));
    curveEllipse->setData(ellipse.getPointsX(), ellipse.getPointsY());
    evolute.setA(abs(arg1.toDouble()));
    curveEvolute->setData(evolute.getPointsX(), evolute.getPointsY());
    ui->plot->replot();
}


void MainWindow::on_bLineEdit_textEdited(const QString &arg1)
{
    ellipse.setB(abs(arg1.toDouble()));
    curveEllipse->setData(ellipse.getPointsX(), ellipse.getPointsY());
    evolute.setB(abs(arg1.toDouble()));
    curveEvolute->setData(evolute.getPointsX(), evolute.getPointsY());
    ui->plot->replot();
}
