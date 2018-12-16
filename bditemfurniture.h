#ifndef BDITEMFURNITURE_H
#define BDITEMFURNITURE_H

#include <QWidget>
#include "globals.h"

namespace Ui {
class BDItemFurniture;
}

class BDItemFurniture : public QWidget
{
    Q_OBJECT

public:
    explicit BDItemFurniture(QWidget *parent = nullptr, BDItemFurnitureData data = {});
    ~BDItemFurniture();

private:
    Ui::BDItemFurniture *ui;
};

#endif // BDITEMFURNITURE_H
