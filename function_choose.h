#ifndef FUNCTION_CHOOSE_H
#define FUNCTION_CHOOSE_H

#include <QWidget>
#include "subwindow.h"

namespace Ui {
class Function_choose;
}

class Function_choose : public QWidget
{
    Q_OBJECT

public:
    SubWindow* parent_window;
    explicit Function_choose(QWidget *parent = 0);
    ~Function_choose();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Function_choose *ui;
};

#endif // FUNCTION_CHOOSE_H
