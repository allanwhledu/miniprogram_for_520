#include "subwindow.h"
#include "ssubwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);

    QImage *img=new QImage;
    img->load(":/img/res/img/Clipboard - 2020-03-04 20.42.37.png");
    ui->label->setPixmap(QPixmap::fromImage(img->scaled(ui->label->size(),Qt::KeepAspectRatio)));
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
