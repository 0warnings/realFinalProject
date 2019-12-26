#include "dialog1.h"
#include "ui_dialog1.h"
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QDialog>

dialog1::dialog1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog1)
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
    for(int i=0;i<7;i++){
    ui->tableWidget->setColumnWidth(i,170);}
}

dialog1::~dialog1()
{
    delete ui;
}

void dialog1::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"),
            "", tr("file(*.csv)"));
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line;
        QStringList fields;
        int row = 0;
        while (!in.atEnd())
        {
            line = in.readLine();
            linesStr.push_back(line);
            fields = line.split(',');//按照","分割字符，因为csv文件是以逗号间隔数据的
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row, column, new QTableWidgetItem(fields[column]));//显示数据
            }
            row++;
        }
}

void dialog1::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(0)>=ui->lowEdit->text())&&( field[i].at(0)<= ui->upEdit->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}}

void dialog1::on_pushButton_3_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(1)>=ui->lowEdit_1->text())&&( field[i].at(1)<= ui->upEdit_1->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

void dialog1::on_pushButton_4_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(2)>=ui->lowEdit_2->text())&&( field[i].at(2)<= ui->upEdit_2->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

void dialog1::on_pushButton_5_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(3)>=ui->lowEdit_3->text())&&( field[i].at(3)<= ui->upEdit_3->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

void dialog1::on_pushButton_6_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(4)>=ui->lowEdit_4->text())&&( field[i].at(4)<= ui->upEdit_4->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

void dialog1::on_pushButton_7_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(5)>=ui->lowEdit_5->text())&&( field[i].at(5)<= ui->upEdit_5->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

void dialog1::on_pushButton_8_clicked()
{
    ui->tableWidget->clear();
        QVector<QString>selectLineStr;
        QVector<QStringList> field;

        for (int i = 0; i < linesStr.size(); i++){
            field.push_back(linesStr[i].split(','));
            if ((field[i].at(6)>=ui->lowEdit_6->text())&&( field[i].at(6)<= ui->upEdit_6->text())){
                selectLineStr.push_back(linesStr[i]);
            }
        }//筛选数据

        QStringList fields;
        //写标题
        fields = linesStr[0].split(',');

        for (int column = 0; column < fields.size(); column++){
            ui->tableWidget->setItem(0, column, new QTableWidgetItem(fields[column]));
        }//之前fields.size() 为linesStr[0] 错误 ，这里是因为QString是以一个字符为单位，而QStringList以一个数据储存
        //写内容
        for (int row = 0; row < selectLineStr.size(); row++){
            fields = selectLineStr[row].split(',');
            for (int column = 0; column < fields.size(); column++){
                ui->tableWidget->setItem(row+1, column, new QTableWidgetItem(fields[column]));
            }

}
}

