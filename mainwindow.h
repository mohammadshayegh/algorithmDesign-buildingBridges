#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qinputdialog.h>
#include <QDialog>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QDebug>
#include <string.h>
#include "city.h"
#include <algorithm>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int **m_City = nullptr;
    int m_size = 0;
    vector<int>* m_bridges;
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
