#include "function_choose.h"
#include "ui_function_choose.h"
#include "ssubwindow.h"

Function_choose::Function_choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Function_choose)
{
    ui->setupUi(this);

    QImage *img=new QImage;
    img->load(":/img/res/img/Snipaste_2020-06-01_16-25-41.png");
    ui->label_2->setPixmap(QPixmap::fromImage(img->scaled(ui->label_2->size(),Qt::KeepAspectRatio)));

    ui->label->adjustSize();
}

Function_choose::~Function_choose()
{
    delete ui;
}

void Function_choose::on_pushButton_2_clicked()
{
    this->close();
    this->parent_window->show();
}

void Function_choose::on_pushButton_clicked()
{
    auto mini_tomato = new SSubWindow;
    mini_tomato->parent_window = this;
    this->hide();
    mini_tomato->show();
}
