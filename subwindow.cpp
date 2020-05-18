#include "subwindow.h"
#include "ssubwindow.h"
#include "ui_subwindow.h"

#include <QDateTime>
#include <QTime>

SubWindow::SubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);

    QImage *img=new QImage;
    img->load(":/img/res/img/Clipboard - 2020-03-04 20.42.37.png");
    ui->label->setPixmap(QPixmap::fromImage(img->scaled(ui->label->size(),Qt::KeepAspectRatio)));

    // 显示在一起之后的天数
    QDateTime endtime = QDateTime::currentDateTime();
    uint etime = endtime.toTime_t();
    QString starttime ="2018-03-06 18:00:00";
    QDateTime start = QDateTime::fromString(starttime, "yyyy-MM-dd hh:mm:ss");
    uint stime = start.toTime_t();
    int ndaysec = 24*60*60;
    int day_from_couple = (etime - stime)/(ndaysec) + ((etime - stime)%(ndaysec)+(ndaysec-1))/(ndaysec) - 1;
    QString day_from_couple_str = QString::number(day_from_couple);
    ui->days->setText(day_from_couple_str);
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::on_pushButton_clicked()
{
    auto ss = new SSubWindow;
    this->hide();
    ss->show();
}
