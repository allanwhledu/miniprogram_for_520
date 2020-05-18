#include "storywindow.h"
#include "ui_storywindow.h"

StoryWindow::StoryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StoryWindow)
{
    ui->setupUi(this);
}

StoryWindow::~StoryWindow()
{
    delete ui;
}
