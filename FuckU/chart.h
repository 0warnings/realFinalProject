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

};

#endif // CHART_H
