#include <QMessageBox>
#include <QDateTime>
#include "windows.h"
#include "ssubwindow.h"
#include "ui_ssubwindow.h"
// this is for solving PSTR conversion problem in GetWindowText
#define UNICODE

SSubWindow::SSubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SSubWindow)
{
    QString display_num;

    ui->setupUi(this);
    this->appName = "";
    this->min_setting = 25;
    this->sec_setting = 0;
    this->init_time(this->min_setting, this->sec_setting);
    this->update_lcd(this->min_left, this->sec_left);
    this->ui->textBrowser->append("这里记录了小可爱的行动哦！");
    this->first_action_update = true;
    // a timer to update current time
    this->m_timer = new QTimer();
    connect(this->m_timer, SIGNAL(timeout()), this, SLOT(update_action_log()));
    // start timer button
    connect(this->ui->pushButton_start, SIGNAL(clicked()), this, SLOT(btn_start()));
    // stop timer button
    connect(this->ui->pushButton_stop, SIGNAL(clicked()), this, SLOT(btn_stop()));
    // the button to show settings dialog
    connect(this->ui->pushButton_setting, SIGNAL(clicked()), this, SLOT(show_settings()));
    // the main window receives timer settings from the settings dialog
    connect(&(this->settings_dialog), SIGNAL(setup(int,int)), this, SLOT(setup(int,int)));
}

void SSubWindow::init_time(int min, int sec){
    this->min_left = min;
    this->sec_left = sec;
}

// format current time to show on the lcd number widget
QString SSubWindow::format_time(int min, int sec){
    QString str_min;
    QString str_sec;
    QString display_num;
    str_min.setNum(min);
    if(min < 10){
        str_min = "0" + str_min;
    }
    str_sec.setNum(sec);
    if(sec < 10){
        str_sec = "0" + str_sec;
    }
    display_num = str_min + ":" + str_sec;
    return display_num;
}

void SSubWindow::btn_start(){
    if(this->m_timer->isActive()){
        return;
    }
//    this->ui->textBrowser->setText("");
    this->appName = "";
    QString display_num;
    this->init_time(this->min_setting, this->sec_setting);
    this->update_lcd(this->min_left, this->sec_left);
    this->m_timer->start(1000);
}

void SSubWindow::btn_stop(){
    if(this->m_timer->isActive()){
        this->m_timer->stop();
    }
}

void SSubWindow::update_lcd(int min, int sec){
    QString display_num;
    display_num = this->format_time(min, sec);
    this->ui->lcdNumber->display(display_num);
}

void SSubWindow::update_action_log(){
    HWND winHandle = GetForegroundWindow();
    int cTxtLen = GetWindowTextLength(winHandle);
    PSTR pszMem = (PSTR) VirtualAlloc((LPVOID) NULL,
                        (DWORD) (cTxtLen + 1), MEM_COMMIT,
                        PAGE_READWRITE);
    GetWindowText(winHandle, pszMem,
                        cTxtLen + 1);
    // to save Chinese characters into QString, fromLocal8Bit is needed
    QString tmpName = QString::fromLocal8Bit(pszMem);
    if(this->appName != tmpName){
        this->appName = tmpName;
        QDateTime time = QDateTime::currentDateTime();
        if(this->first_action_update == true)
            {
            this->first_action_update = false;
        }
        this->ui->textBrowser->append("\n");

        this->ui->textBrowser->append(time.toString("hh:mm:ss"));
        this->ui->textBrowser->append(this->appName);
    }
    VirtualFree(pszMem, 0, MEM_RELEASE);
    if (this->sec_left == 0){
        if (this->min_left == 0){
            this->m_timer->stop();
            this->setWindowState( (windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
            this->activateWindow();
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, tr("Congrats!"),
                                          tr("Do you want to restart?"),
                                            QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes){
                this->btn_start();
            }
            return;
        }
        this->min_left -= 1;
        this->sec_left = 59;
    } else {
        this->sec_left -= 1;
    }
    this->update_lcd(this->min_left, this->sec_left);
}

void SSubWindow::show_settings(){
    this->settings_dialog.show();
}

void SSubWindow::setup(int min, int sec){
    if(this->m_timer->isActive()){
        this->m_timer->stop();
    }
    this->min_setting = min;
    this->sec_setting = sec;
    this->init_time(this->min_setting, this->sec_setting);
    this->update_lcd(min, sec);
}

SSubWindow::~SSubWindow()
{
    if(this->m_timer->isActive()){
        this->m_timer->stop();
    }
    delete ui;
}

