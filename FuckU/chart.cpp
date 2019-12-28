#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include "chart.h"
#include "ui_chart.h"
#include <QtCharts/QChartView>//显示图表
#include <QDoubleSpinBox>
#include <QDebug>
#include <QSlider>
#include <vector>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QTime>
#include <qmath.h>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QRandomGenerator>
#include <QHBoxLayout>
#include <QLineSeries>


chart::chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chart)
{
    ui->setupUi(this);
    this->resize( QSize( 1500, 927 ));
    QString path=":/image/image/3.jpeg";
    QPixmap pixmap = QPixmap(path).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);


}

chart::~chart()
{
    delete ui;
}

int datetimeTosecond(QDateTimeEdit *a){
    QString strhour=a->sectionText(QDateTimeEdit::HourSection);
    QString strminute=a->sectionText(QDateTimeEdit::MinuteSection);
    QString strsecond=a->sectionText(QDateTimeEdit::SecondSection);
    int hour=strhour.toInt();
    int minute=strminute.toInt();
    int second=strsecond.toInt();
    return 3600*hour+60*minute+second;
}

int timeTosecond(QTimeEdit *a){
    QString strhour=a->sectionText(QTimeEdit::HourSection);
    QString strminute=a->sectionText(QTimeEdit::MinuteSection);
    QString strsecond=a->sectionText(QTimeEdit::SecondSection);
    int hour=strhour.toInt();
    int minute=strminute.toInt();
    int second=strsecond.toInt();
    return 3600*hour+60*minute+second;
}

bool lowflag(QString a,QDateTimeEdit *start,QTimeEdit *step,int n){
    QString time=a.right(8);
    QStringList time_=time.split(':');
    int a_value=time_.at(0).toInt()*3600+time_.at(1).toInt()*60+time_.at(2).toInt();
    int start_value=datetimeTosecond(start);
    int step_value=timeTosecond(step);
    if(a_value>=start_value+step_value*n)
        return  true;
    else
        return false;
}

bool upflag(QString a,QDateTimeEdit *start,QTimeEdit *step,int n){
    QString time=a.right(8);
    QStringList time_=time.split(':');
    int a_value=time_.at(0).toInt()*3600+time_.at(1).toInt()*60+time_.at(2).toInt();
    int start_value=datetimeTosecond(start);
    int step_value=timeTosecond(step);
    if(a_value>start_value+step_value*(n+1))
        return  true;
    else
        return false;
}

void chart::on_pushButton_2_clicked()
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
        }
}

void chart::on_pushButton_clicked()
{
    QVector<QString> selectLineStr;
    QVector<QStringList> field;

    for (int i = 0; i < linesStr.size(); i++){
        field.push_back(linesStr[i].split(','));
        if ((field[i].at(2)==ui->stationID->text())){
            selectLineStr.push_back(linesStr[i]);
        }
    }//筛选数据

    std::sort(selectLineStr.begin(),selectLineStr.end());
    QVector<QString>inflow;
    QVector<QString>outflow;
    QVector<QStringList>tmp;
    QVector<QStringList>inFlow;
    QVector<QStringList>outFlow;
    int icount=0,ocount=0;
    for(int i=0;i<selectLineStr.size();i++){
       tmp.push_back(selectLineStr[i].split(','));
        if(tmp[i].at(4).toInt()==1)
        {inflow.push_back(selectLineStr[i]);
        inFlow.push_back(inflow[icount].split(','));
        icount++;}
        else {
            outflow.push_back(selectLineStr[i]);
            outFlow.push_back(outflow[ocount].split(','));
            ocount++;
        }
    }

    int n=(datetimeTosecond(ui->endingtime)-datetimeTosecond(ui->startingtime))/timeTosecond(ui->timestep)+1;
    QVector<int>in_count;
    QVector<int>out_count;
    for(int i=0;i<n;i++){
        int m=0;
        int inCount=0;
        int outCount=0;
        while (1) {
            if(lowflag(inFlow[m].at(0),ui->startingtime,ui->timestep,i))
                inCount++;
            if(lowflag(outFlow[m].at(0),ui->startingtime,ui->timestep,i))
                outCount++;
            m++;
            if(upflag(inFlow[m].at(0),ui->startingtime,ui->timestep,i)||upflag(outFlow[m].at(0),ui->startingtime,ui->timestep,i))
                break;
        }
        in_count.push_back(inCount);
        out_count.push_back(outCount);
    }

    QList<QSplineSeries *> m_series;
        QSplineSeries *series1 = new QSplineSeries();//实例化一个QLineSeries对象
        QSplineSeries *series2 = new QSplineSeries();//实例化一个QLineSeries对象
        m_series.append(series1);
        m_series.append(series2);
        //设置线条名称
        series1->setName(QString("line " + QString::number(1)));
        series2->setName(QString("line " + QString::number(2)));
        //series->setName(QString("line " + QString::number(m_series.count())));
        //设置线条颜色，如果不设置会给默认颜色
        series1->setColor(QColor(255,0,255));
        series2->setColor(QColor(0,255,255));
        //series1->setBrush(QColor(255,0,255));
        //series1->setPen(QColor(255,0,255));
        //设置是否线条可视
        series1->setVisible(true);
        series2->setVisible(true);
        //点标签是否可视
        series1->setPointLabelsVisible(true);
        series2->setPointLabelsVisible(true);
        //点标签颜色
        series1->setPointLabelsColor(QColor(255,255,255));
        series2->setPointLabelsColor(QColor(255,255,255));
        //点标签字体
        series1->setPointLabelsFont(QFont("微软雅黑"));
        series2->setPointLabelsFont(QFont("微软雅黑"));
        //设置点标签显示格式
        series1->setPointLabelsFormat("(@xPoint,@yPoint)");
        series2->setPointLabelsFormat("(@xPoint,@yPoint)");
        //是否切割边缘点标签，默认为true
        series1->setPointLabelsClipping(false);
        series2->setPointLabelsClipping(true);
        //设置点标签是否可视
        series1->setPointsVisible(true);
        series2->setPointsVisible(true);

        //添加坐标点
        for(int i=0;i<n;i++){
            series1->append(i,in_count[i]);
            series2->append(i,out_count[i]);
        }

        QChart *chart = new QChart();
        chart->setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
        chart->setAnimationOptions(QChart::AllAnimations);//设置启用或禁用动画
        //chart->setBackgroundBrush(QBrush(QColor(170,170,255)));//设置背景色,主题和背景二选一
        //chart->setDropShadowEnabled(true);//是否背景阴影
        chart->setLocalizeNumbers(true);//数字是否本地化
        //chart->legend()->show();//legend是否显示，show和hide
        chart->addSeries(series1);//添加系列到QChart上
        chart->addSeries(series2);//添加系列到QChart上

        //chart->createDefaultAxes();//创建默认轴
        QValueAxis *axisX = new QValueAxis();//轴变量、数据系列变量，都不能声明为局部临时变量
        QValueAxis *axisY = new QValueAxis();//创建X/Y轴
        auto max_1 = std::max_element(std::begin(in_count), std::end(in_count));
        auto max_2 = std::max_element(std::begin(out_count), std::end(out_count));
        auto ymax=qMax(max_1,max_2);
        int  xx=*ymax;
        axisX->setRange(0, n);
        axisY->setRange(0, xx);//设置X/Y显示的区间
        chart->setAxisX(axisX);
        chart->setAxisY(axisY);//设置chart的坐标轴
        series1->attachAxis(axisX);
        series2->attachAxis(axisX);

        chart->setTitle("Simple line chart example");//设置标题
        chart->setTitleBrush(QBrush(QColor(255,170,255)));//设置标题Brush
        chart->setTitleFont(QFont("微软雅黑"));//设置标题字体

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);//底部对齐
        //chart->legend()->detachFromChart();
        chart->legend()->setBackgroundVisible(true);//设置背景是否可视
        //chart->legend()->setAutoFillBackground(true);//设置背景自动填充
        //chart->legend()->setColor(QColor(255,128,128,128));//设置颜色
        //chart->legend()->setContentsMargins(10,10,10,10);//设置边距left,top,right,bottom
        chart->legend()->setLabelColor(QColor(255,128,255));//设置标签颜色
        chart->legend()->setVisible(true);//设置是否可视
        //chart->legend()->setMaximumHeight(50);
        //chart->legend()->setMaximumWidth(120);
        //chart->legend()->setMaximumSize(10000);
        //chart->legend()->setGeometry(50,50,120,50);//设置几何位置x,y,w,h
        //chart->legend()->setBrush(QBrush(QColor(128,128,128,128)));
        //chart->legend()->setPen(QPen(QColor(192,192, 192,192)));
        chart->legend()->setBorderColor(QColor(255,255,170,185));//设置边框颜色
        QFont font = chart->legend()->font();
        font.setItalic(!font.italic());
        chart->legend()->setFont(font);//设置字体为斜体
        font.setPointSizeF(12);
        chart->legend()->setFont(font);//设置字体大小
        chart->legend()->setFont(QFont("微软雅黑"));//设置字体类型

        ui->widget->setChart(chart);

}


