#ifndef CHART_H
#define CHART_H
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QLineSeries>
namespace Ui {
class chart;
}

class chart : public QWidget
{
    Q_OBJECT

public:
    explicit chart(QWidget *parent = nullptr);
    ~chart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::chart *ui;
    QVector<QString> linesStr;
    QList<QLineSeries *> m_series;
    QLineSeries *series1 = new QLineSeries();//实例化一个QLineSeries对象
    QLineSeries *series2 = new QLineSeries();//实例化一个QLineSeries对象
    //void strToInt(const QString a,int time[3]);
    //void toSecond(int a[3],int b);
    //void toTime(int a,int b[3]);
    //bool upflag(QString x,QString a,QString b,int n);
    //bool lowflag(QString x,QString a,QString b,int n);
};

#endif // CHART_H
