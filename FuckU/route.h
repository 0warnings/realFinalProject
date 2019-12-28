#ifndef ROUTE_H
#define ROUTE_H

#include <QDialog>

namespace Ui {
class route;
}

class route : public QDialog
{
    Q_OBJECT

public:
    explicit route(QWidget *parent = nullptr);
    ~route();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::route *ui;
    QVector<QString> linesStr;
    int map[83][83];
    QString tmp;
};

#endif // ROUTE_H
