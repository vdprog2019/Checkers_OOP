#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "field.h"
#include <QObject>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void buttonClick();
    void newGame();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    field f;
protected:
    QLabel *label;
    QPushButton *btn;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
