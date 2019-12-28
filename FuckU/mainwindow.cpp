#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QDialog>
#include <route.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 1500, 927 ));
    QString path=":/image/image/1.jpg";
    QPixmap pixmap = QPixmap(path).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dialog1 *v=new dialog1();
    v->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    chart *m=new chart ();
    m->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    route *m=new route ();
    m->show();
}
