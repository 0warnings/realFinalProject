#include "route.h"
#include "ui_route.h"
#include <QDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

int route::u,route::v;
int route::map[82][82];
int route::ans[82];
int route::vis[82]={0};

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
    ui->tableWidget->setColumnCount(82);//设置表格的行数和列数
    ui->tableWidget->setRowCount(82);
    ui->tableWidget->setFont(QFont("Helvetica"));
    for(int i=0;i<82;i++){
    ui->tableWidget->setColumnWidth(i,15);}
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
        QStringList tmp;

        while (!in.atEnd())
        {
            line = in.readLine();
            linesStr1.push_back(line);
            tmp=line.split(',');
            source.push_back(tmp);
          }

}

void print(int s,int e){
    for(int i=s;i<e;i++){
        QString ss=QString::number(route::ans[i],10);
    }
}


void DFS(int k,int start)
{
    if(start == route::v)
    {
        //ans[k] = v;
        print(0,k);
        return;
    }
    route::vis[start] = 1;
    for(int i = 0;i<82;i++)
    {
        if(route::vis[i]==1 || route::map[start][i]==0)
        continue;
        route::ans[k] = i;
        DFS(k+1,i);
    }
    route::vis[start] = 0;
}

void route::on_pushButton_2_clicked()
{
    int start=ui->enterstation->text().toInt();
    int end=ui->exitstation->text().toInt();

    for(int i = 0;i<82;i++)
        {
            for(int j = 0;j<82;j++)
            {
                map[i][j]=source[i].at(j).toInt();
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(map[i][j]));
            }
        }
    v=end;
    u=start;
        ans[0] = u;
        DFS(1,u);
}



