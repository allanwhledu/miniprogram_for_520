#ifndef STORYWINDOW_H
#define STORYWINDOW_H

#include <QMainWindow>

namespace Ui {
class StoryWindow;
}

class StoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoryWindow(QWidget *parent = 0);
    ~StoryWindow();

private:
    Ui::StoryWindow *ui;
};

#endif // STORYWINDOW_H
