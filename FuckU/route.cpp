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
    ui->tableWidget->setColumnCount(81);//设置表格的行数和列数
    ui->tableWidget->setRowCount(81);
    ui->tableWidget->setFont(QFont("Helvetica"));
    for(int i=0;i<81;i++){
    ui->tableWidget->setColumnWidth(i,30);}
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


void dfs(int x,int y,int t,int *flag,int *zh,int map[][81],int ans[81][81])
{
    flag[x]=1;
    zh[t]=x;
    int m=0;
    if(x==y)
    {
        for(int i=0;i<=t;i++)
            ans[m][i]=zh[i];
        m++;
    }
    for(int i=0;i<81;i++)
    {
        if(map[x][i]!=0&&flag[i]==0)
        {
            dfs(i,y,t+1,flag,zh,map,ans);
        }
    }
    flag[x]=0;    //标记取消
}


void route::on_pushButton_2_clicked()
{
    int start=ui->enterstation->text().toInt();
    int end=ui->exitstation->text().toInt();

    int map[81][81];
    int zh[81];  //存放当前路径
    int flag[81];
    int ans[81][81];

    for(int i=0;i<81;i++){
        for(int j=0;j<81;j++){
            ans[i][j]=100;
        }
    }

    for(int i=0;i<81;i++){
        for(int j=0;j<81;j++){
            map[i][j]=source[i+1].at(j+1).toInt();
        }
    }

    dfs(start,end,0,flag,zh,map,ans);

    for(int i=0;i<81;i++){
        for(int j=0;j<81;j++){
            if(ans[i][j]!=100)
            {ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(ans[i][j],10)));}
    }
}
}



