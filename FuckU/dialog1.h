#ifndef DIALOG1_H
#define DIALOG1_H

#include <QWidget>

namespace Ui {
class dialog1;
}

class dialog1 : public QWidget
{
    Q_OBJECT

public:
    explicit dialog1(QWidget *parent = nullptr);
    ~dialog1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();
private:
    Ui::dialog1 *ui;
    QVector<QString>linesStr;
};

#endif // DIALOG1_H
