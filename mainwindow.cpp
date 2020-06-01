#include "mainwindow.h"
#include "subwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFontDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    error_count = 0;

    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/font/res/font/forLetter.ttf");

//    QFont font;
//    font.setFamily("momo_xinjian");
//    font.setPixelSize(40);

//    QFont minifont;
//    minifont.setFamily("momo_xinjian");
//    minifont.setPixelSize(30);

//    ui->pushButton->setFont(font);
//    ui->label->setFont(minifont);

    QImage *img=new QImage;
    img->load(":/img/res/img/Clipboard - 2020-03-04 20.25.15.png");
    ui->label_2->setPixmap(QPixmap::fromImage(img->scaled(ui->label_2->size(),Qt::KeepAspectRatio)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString password = "0306";
    if(this->ui->lineEdit->text()==password)
    {
        auto s = new SubWindow;
        this->hide();
        s->show();
    }
    else if(this->ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"Emm~","至少写个密码试一试嘛！");
    }
    else
    {
        if(error_count < 3)
        {
            QMessageBox::information(this,"Hia~Hia~","你没有猜对密码，再来一次！");
            error_count++;
        }
        else if(error_count < 5) {
            QMessageBox::information(this,"Hia~Hia~","加——油—— 再试一试，说不定我之后会给你提示哦");
            error_count++;
        }
        else if(error_count < 7) {
            QMessageBox::information(this,"Hia~Hia~","哎呀，就是月日格式的一个日子啦，4个数字，比心哦");
            error_count++;
        }
        else if(error_count > 6){
            QMessageBox::information(this,"(+_+)?","密码就是纪念日啦");
        }
    }
}
