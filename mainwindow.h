#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "globals.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QList<BDItemClothsData> clothsData = {},
                                                   QList<BDItemFurnitureData> furnitureData = {},
                                                   QList<BDItemProductData> productData = {});
    ~MainWindow();
    //QList<BDItemClothsData> clothsData;

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
