#ifndef SSUBWINDOW_H
#define SSUBWINDOW_H

#include <QMainWindow>

namespace Ui {
class SSubWindow;
}

class SSubWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SSubWindow(QWidget *parent = 0);
    ~SSubWindow();

private:
    Ui::SSubWindow *ui;
};

#endif // SSUBWINDOW_H
