#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include "globals.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr, QList<BDItemClothsData> clothsData = {},
                                                    QList<BDItemFurnitureData> furnitureData = {},
                                                    QList<BDItemProductData> productData = {});
    ~AdminWindow();
    QList<BDItemClothsData> cdata;
    QList<BDItemFurnitureData> fdata;
    QList<BDItemProductData> pdata;
    void loadData();

private slots:
    void on_pushButton_StockCloths_clicked();

    void on_pushButton_StockFurniture_clicked();

    void on_pushButton_StockProducts_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
