#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QtSql>
#include "globals.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    QList<BDItemClothsData> clothsData;
    QList<BDItemFurnitureData> furnitureData;
    QList<BDItemProductData> productData;

private slots:
    void on_pushButton_Login_clicked();

private:
    bool loadDB();
    Ui::LoginWindow *ui;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
