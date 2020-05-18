#include "ssubwindow.h"
#include "ui_ssubwindow.h"

SSubWindow::SSubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SSubWindow)
{
    ui->setupUi(this);

    QImage *img=new QImage;
    img->load(":/img/res/img/Clipboard - 2020-03-04 20.42.37.png");
    ui->label->setPixmap(QPixmap::fromImage(img->scaled(ui->label->size(),Qt::KeepAspectRatio)));
}

SSubWindow::~SSubWindow()
{
    delete ui;
}
