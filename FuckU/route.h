#ifndef ROUTE_H
#define ROUTE_H

#include <QDialog>
#include <QTextEdit>
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
    QVector<QString> linesStr1;
public:
    QVector<QStringList> source;
};

#endif // ROUTE_H
