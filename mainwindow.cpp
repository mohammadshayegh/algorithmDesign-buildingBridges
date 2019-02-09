#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_5->setText("");
    int i = ui->lineEdit->text().toInt();
    city river(i,this,ui);
    m_City = river.getMap();
    m_size = i;
    m_bridges = river.getBridges();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    if(m_City && m_size)
    {
        int *elements = new int [m_size+1]{0};

        for(int i=1 ; i < m_size+1 ; i++)
            elements[m_City[0][i]] = i;

        for(int j=1 ; j < m_size+1 ;  j++)
        {
            QPainter painter(this);QPoint p;

            p.setX(58 +  j*40);
            p.setY(214);
            QRect r1(50 +  j*40, 200 ,20,20);

            painter.setBrush(QBrush(QColor("#FF5500")));
            painter.setPen("#FF007F");

            painter.drawEllipse(r1);

            painter.setPen(Qt::white);
            painter.drawText(p,QString::number(m_City[0][j]));
        }

        for(int i=1 ; i < m_size+1 ;  i++)
        {
            QPainter painter(this);QPoint p;

            p.setX(58 +  i*40);
            p.setY(214 + 50);
            QRect r1(50 +  i*40, 200 + 50,20,20);

            painter.setBrush(QBrush(QColor("#FF007F")));
            painter.setPen("#FF5500");
            painter.drawEllipse(r1);

            painter.setPen(Qt::white);
            painter.drawText(p,QString::number(m_City[i][0]));

            int* arr = m_bridges->data();
            for(int k=0 ; k<m_bridges->size(); k++)
                if(m_City[arr[k]][0] == m_City[i][0])
                {
                    QPen pn;
                    pn.setColor("#5555FF");
                    pn.setWidth(2);
                    painter.setPen(pn);
                    painter.setBrush(QBrush(Qt::black));

                    painter.drawLine(58 + i*40,250,58 + elements[m_City[arr[k]][0]]*40,220);
                }
        }
    }
}
