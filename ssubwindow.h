#ifndef SSUBWINDOW_H
#define SSUBWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include "settingsdialog.h"
#include "subwindow.h"
#include "function_choose.h"

namespace Ui {
class SSubWindow;
}

class SSubWindow : public QMainWindow
{
    Q_OBJECT

public:
    Function_choose* parent_window;
    explicit SSubWindow(QWidget *parent = 0);
    ~SSubWindow();

private:
    Ui::SSubWindow *ui;
    QTimer *m_timer;
    int min_left;
    int sec_left;
    int min_setting;
    int sec_setting;
    bool first_action_update;
    QString appName;
    SettingsDialog settings_dialog;
    QString format_time(int, int);
    void init_time(int, int);
    void update_lcd(int, int);

public slots:
    void update_action_log();
    void btn_start();
    void btn_stop();
    void show_settings();
    void setup(int, int);
private slots:
    void on_return_button_clicked();
};

#endif // SSUBWINDOW_H
