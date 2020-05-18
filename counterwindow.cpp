#include "counterwindow.h"
#include "ui_counterwindow.h"

CounterWindow::CounterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CounterWindow)
{
    ui->setupUi(this);
}

CounterWindow::~CounterWindow()
{
    delete ui;
}
