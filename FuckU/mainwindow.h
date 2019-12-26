#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTableWidgetItem>
#include <iostream>
#include <vector>
#include <QDialog>
#include "dialog1.h"

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


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString>linesStr;
    QVector<QString>linesStr_flag;
};
#endif // MAINWINDOW_H
