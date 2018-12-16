#ifndef BDITEMPRODUCT_H
#define BDITEMPRODUCT_H

#include <QWidget>
#include "globals.h"

namespace Ui {
class BDItemProduct;
}

class BDItemProduct : public QWidget
{
    Q_OBJECT

public:
    explicit BDItemProduct(QWidget *parent = nullptr, BDItemProductData data = {});
    ~BDItemProduct();

private:
    Ui::BDItemProduct *ui;
};

#endif // BDITEMPRODUCT_H
