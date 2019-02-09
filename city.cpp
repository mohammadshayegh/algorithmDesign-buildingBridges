#include "city.h"

city::city(int size, QWidget *mainWindow, const Ui_MainWindow *ui) :
    m_size(size),m_ui(ui),m_mainWindow(mainWindow)
{
    m_map = dynamicArray_2D(m_size+1,m_size+2);
    m_path = new int [m_size+1]{0};
    initializer();
    m_maxBridge = maxBridgeNumber();
    m_ui->label_3->setText(QString::number(m_maxBridge));
    findPath(startMax_index);
}

int** city::dynamicArray_2D(int width,int height)
{
    int **array = new int* [width];
    for(int i=0;i<width;i++)
        array[i] =  new int[height]{0} ;

    return array;
}

int city::findMax(int x, int j)
{
    // x : vertical element
    // j : horizental element

    int max = 0;

    for (int i = x ; i != 0 ; i--)
        if( m_map[i][j] == 0 && m_map[i][m_size+1] > max)
        {
            max = m_map[i][m_size +1];
            m_path[ x ] = i;
        }

    if(!m_path[x])
        m_path[ x ] = x;

    return max ;
}

void city::initializer()
{
    for (int i=1;i<m_size+1;i++)
    {
        do{
            m_map[0][i] = QInputDialog::getInt(m_mainWindow, "Enter a Number","first city indexes",
                                               0, 0, 100, 1);

            if(m_map[0][i]<=0 || m_map[0][i]>m_size)
            {
                QString attention = "Bigger than 0 ,Smaller than ";
                attention.append(QString::number(m_size));
                QMessageBox msgBox;
                msgBox.setText(attention);
                msgBox.exec();
            }
        }
        while(m_map[0][i]<=0 || m_map[0][i]>m_size);

    }

    for (int i=1;i<m_size+1;i++)
    {
        do{
            m_map[i][0] = QInputDialog::getInt(m_mainWindow, "Enter a Number","second city indexes"
                                              ,0, 0, 100, 1);

            if(m_map[i][0]<=0 || m_map[i][0]>m_size)
            {
                QString attention = "Bigger than 0 ,Smaller than ";
                attention.append(QString::number(m_size));
                QMessageBox msgBox;
                msgBox.setText(attention);
                msgBox.exec();
            }
        }
        while(m_map[i][0]<=0 || m_map[i][0]>m_size);
    }
}

int city::maxBridgeNumber()
{
    int maxx = 0;
    for (int i=1 ; i<m_size+1 ; i++)
    {
        int j = 1;
        for ( j=1 ; m_map[0][j-1] != m_map[i][0];j++)
            m_map[i][j] = m_map[i][0];

        m_map[i][m_size+1] = findMax(i,j-1) + 1;

        if(m_map[i][m_size+1] > maxx)
        {
            maxx = m_map[i][m_size+1];
            startMax_index = i;
        }
    }
    return maxx;
}

void city::findPath(int index )
{
    if (index == m_path[index])
    {
        m_bridges->push_back(index);
        m_ui->label_5->setText(m_ui->label_5->text() + QString::number(index) );
        return;
    }
    else
    {
        m_bridges->push_back(index);
        m_ui->label_5->setText(m_ui->label_5->text() + QString::number(index) + " " );
        findPath( m_path[index] );
    }
}

