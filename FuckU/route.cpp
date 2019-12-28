#include "route.h"
#include "ui_route.h"
#include <QDialog>
#include <QFileDialog>
#include <QTextStream>

#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

route::route(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::route)
{
    ui->setupUi(this);
    this->resize( QSize( 1500, 927 ));
    QString path=":/image/image/2.jpeg";
    QPixmap pixmap = QPixmap(path).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    ui->tableWidget->setColumnCount(7);//设置表格的行数和列数
    ui->tableWidget->setRowCount(10000000);
    ui->tableWidget->setFont(QFont("Helvetica"));
}

route::~route()
{
    delete ui;
}

void route::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"),
            "", tr("file(*.csv)"));
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line;
        QStringList fields;
        while (!in.atEnd())
        {
            line = in.readLine();
            linesStr.push_back(line);
            fields = line.split(',');//按照","分割字符，因为csv文件是以逗号间隔数据的
        }
        QVector<QStringList> tmp;
        for(int i=0;i<83;i++){
            tmp.push_back(linesStr[i].split(','));
        }
        for(int i=0;i<83;i++){
            for(int j=0;j<83;j++){
                if(tmp[i].at(j).toInt()!=0){
                map[i][j]=tmp[i].at(j).toInt();}
            }
        }
}

void route::on_pushButton_2_clicked()
{

    //start=ui->enterstation->text().toInt();
    //end=ui->exitstation->text().toInt();
}



