#ifndef COUNTERWINDOW_H
#define COUNTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class CounterWindow;
}

class CounterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CounterWindow(QWidget *parent = 0);
    ~CounterWindow();

private:
    Ui::CounterWindow *ui;
};

#endif // COUNTERWINDOW_H
