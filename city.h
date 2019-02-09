#ifndef CITY_H
#define CITY_H

#include <qinputdialog.h>
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>
#include <ui_mainwindow.h>
#include <vector>
using namespace std;

class city
{
private:
    int m_size;
    int **m_map = nullptr;
    int *m_path = nullptr;
    int m_maxBridge = 0;
    int startMax_index = 0;
    vector<int>* m_bridges = new vector<int>;
    const Ui_MainWindow *m_ui = nullptr;
    QWidget *m_mainWindow = nullptr;

public:
    city(int size , QWidget* mainWindow , const Ui_MainWindow *ui);
    static int** dynamicArray_2D(int width,int height);
    int findMax(int i , int j);
    void initializer();
    int maxBridgeNumber();
    void findPath(int index);

    int **getMap(){return m_map;}
    int *getPath(){return m_path;}
    int getSize(){return m_size;}
    vector<int>* getBridges(){return m_bridges;}
};

#endif // CITY_H
