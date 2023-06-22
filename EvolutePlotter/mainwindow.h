#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "ellipse.h"
#include "evolute.h"
#include "pwin.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void redrawSquare();

    void on_checkBox_stateChanged(int arg1);

    void resizeEvent(QResizeEvent *event);

    void on_toPolarButton_clicked();

    void on_aLineEdit_textEdited(const QString &arg1);

    void on_bLineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
